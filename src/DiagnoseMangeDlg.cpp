#include "StdAfx.h"
#include "DiagnoseMangeDlg.h"

DiagnoseMangeDlg::DiagnoseMangeDlg(QWidget *parent):QDialog(parent)
{
    resize(420, 400);
    setWindowTitle("诊断管理");

    diagnoseTable_ = new QTableWidget(this);
    diagnoseTable_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    diagnoseTable_->setSelectionBehavior(QAbstractItemView::SelectRows);
    diagnoseTable_->setSelectionMode(QAbstractItemView::MultiSelection);
    diagnoseTable_->setColumnCount(5);
    diagnoseTable_->setColumnWidth(0, 80);
    diagnoseTable_->setColumnWidth(1, 80);
    diagnoseTable_->setColumnWidth(2, 80);
    diagnoseTable_->setColumnWidth(3, 160);

    QStringList strheadList;
    strheadList<<"序号"<<"测试题号"<<"答案"<<"内容";
    diagnoseTable_->setHorizontalHeaderLabels(strheadList);

    addBtn_ = new QPushButton(this);
    addBtn_->setText("添加");

    delBtn_ = new QPushButton(this);
    delBtn_->setText("删除");
    
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(50);
    btnLayout->addWidget(delBtn_);
    btnLayout->addWidget(addBtn_);

    QVBoxLayout *center = new QVBoxLayout();
    center->addWidget(diagnoseTable_);
    center->addLayout(btnLayout);
    setLayout(center);

    LoadDiagnose();

    connect(addBtn_, SIGNAL(clicked()), this, SLOT(AddDiagnose()));
    connect(delBtn_, SIGNAL(clicked()), this, SLOT(DelDiagnose()));
}

DiagnoseMangeDlg::~DiagnoseMangeDlg(void)
{

}

void DiagnoseMangeDlg::LoadDiagnose()
{
    DIAGNOSIS_VEC::iterator it = DATACENTER::instance()->m_diagnosis_vec.begin();
    for (int i=0; it != DATACENTER::instance()->m_diagnosis_vec.end(); ++it)
    {
        diagnoseTable_->insertRow(i);
        diagnoseTable_->setItem(i, 0, new QTableWidgetItem(QString::number(i+1)));
        diagnoseTable_->setItem(i, 1, new QTableWidgetItem(it->sQuestionid));
        diagnoseTable_->setItem(i, 2, new QTableWidgetItem(it->sKeyContent));
        diagnoseTable_->setItem(i, 3, new QTableWidgetItem(it->sDiagnosis));
        ++i;
    }
}

void DiagnoseMangeDlg::AddDiagnose()
{
     AddDiagnoseDlg *dlg = new AddDiagnoseDlg(this);
     dlg->exec();
}

void DiagnoseMangeDlg::DelDiagnose()
{
//     QList<QTableWidgetItem *> list = diagnoseTable_->selectedItems();
//     QList<QTableWidgetItem *>::iterator it = list.begin();
//     for ()
//     {
//     }
}

void DiagnoseMangeDlg::addDiagnoseItem(QString& strQuesID, QString& strKey, QString& strContent)
{
    int row = diagnoseTable_->rowCount();
    diagnoseTable_->insertRow(row);
    diagnoseTable_->setItem(row, 0, new QTableWidgetItem(QString::number(row)));
    diagnoseTable_->setItem(row, 1, new QTableWidgetItem(strQuesID));
    diagnoseTable_->setItem(row, 2, new QTableWidgetItem(strKey));
    diagnoseTable_->setItem(row, 3, new QTableWidgetItem(strContent));

    INS_DIAGNOSIS diagnose;
    diagnose.sQuestionid = strQuesID;
    diagnose.sKeyContent = strKey;
    diagnose.sDiagnosis = strContent;
    DATACENTER::instance()->addDiagnose(diagnose);
}

//====wo shi fen ge xian===============
AddDiagnoseDlg::AddDiagnoseDlg(DiagnoseMangeDlg *parent):manageDlg(parent)
{
    resize(300, 200);
    quesIDLabel_ = new QLabel(this);
    quesIDLabel_->setText("测试题");

    quesIDEdit_ = new QLineEdit(this);
    
    contentLabel_ = new QLabel(this);
    contentLabel_->setText("诊断内容");

    contentEdit_ = new QLineEdit(this);

    keyLabel_ = new QLabel(this);
    keyLabel_->setText("诊断关键字");

    keyEdit_ = new QLineEdit(this);

    QGridLayout *gridLayout = new QGridLayout();
    gridLayout->setContentsMargins(10, 10, 10, 10);
    gridLayout->addWidget(quesIDLabel_, 0, 0);
    gridLayout->addWidget(quesIDEdit_, 0, 1);
    gridLayout->addWidget(keyLabel_, 1, 0);
    gridLayout->addWidget(keyEdit_, 1, 1);
    gridLayout->addWidget(contentLabel_, 2, 0);
    gridLayout->addWidget(contentEdit_, 2, 1);

    okBtn_ = new QPushButton(this);
    okBtn_->setText("确定");
    cancelBtn_ = new QPushButton(this);
    cancelBtn_->setText("取消");

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->setContentsMargins(5, 5, 5, 5);
    btnLayout->addWidget(okBtn_);
    btnLayout->addWidget(cancelBtn_);

    QVBoxLayout *centerLayout = new QVBoxLayout();
    centerLayout->addLayout(gridLayout);
    centerLayout->addLayout(btnLayout);
    setLayout(centerLayout);

    connect(okBtn_, SIGNAL(clicked()), this, SLOT(Ok()));
    connect(cancelBtn_, SIGNAL(clicked()), this, SLOT(Cancel()));
}

AddDiagnoseDlg::~AddDiagnoseDlg()
{

}

void AddDiagnoseDlg::Ok()
{
    if (quesIDEdit_->text().isEmpty() ||
        keyEdit_->text().isEmpty() ||
        contentEdit_->text().isEmpty())
    {

        QMessageBox::about(this, "添加诊断", "测试题号和答案不能空！");
        return;       
    }
    
    QUESTION_MAP::iterator it = DATACENTER::instance()->m_question_map.find(TransStrToIntID(quesIDEdit_->text()));
    if (it == DATACENTER::instance()->m_question_map.end())
    {
        QMessageBox::question(this, "添加诊断", "你输入的测试题号不存在，请重新输入");
        return;
    }

    manageDlg->addDiagnoseItem(quesIDEdit_->text(), keyEdit_->text(), contentEdit_->text());
    emit accept();
}

void AddDiagnoseDlg::Cancel()
{
    emit reject();
}