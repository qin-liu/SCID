#include "stdafx.h"
#include "LoadTestDlg2.h"

LoadTestDlg::LoadTestDlg(QWidget* parent, AnswerCenter *pAnCenter, QString& strUserName, int nAmsweringSaveIndex):QDialog(parent),
                                                                                         m_pAncenter(pAnCenter),
                                                                                         m_strUserName(strUserName),
                                                                                         m_nAmsweringSaveIndex(nAmsweringSaveIndex)
{
    SET_FONT
    setWindowTitle(tr("���ز���"));
    CreateWidget();
    LoadTestList();
    connect(loadBtn_, SIGNAL(clicked()), this, SLOT(ClickLoad()));
    connect(exitBtn_, SIGNAL(clicked()), this, SLOT(Exit()));
    connect(delBtn_, SIGNAL(clicked()), this, SLOT(ClickDel()));
}

LoadTestDlg::~LoadTestDlg()
{

}

int LoadTestDlg::GetAnswerSaveIndex()
{
       return m_nSaveIndex;
}

void LoadTestDlg::CreateWidget()
{
    testTable_ = new QTableWidget(this);
    testTable_->setColumnCount(3);
    testTable_->setColumnWidth(0, 80);
    testTable_->setColumnWidth(1, 100);
    testTable_->setColumnWidth(2, 200);

    QStringList strheadList;
    strheadList<<"���"<<"���Ա���"<<"����ʱ��";
    testTable_->setHorizontalHeaderLabels(strheadList);
    
    testTable_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    testTable_->setSelectionBehavior(QAbstractItemView::SelectRows);
    testTable_->setSelectionMode(QAbstractItemView::SingleSelection);
    testTable_->horizontalHeader()->setStretchLastSection(true);

    loadBtn_ = new QPushButton(this);
    loadBtn_->setText("����");
    exitBtn_ = new QPushButton(this);
    exitBtn_->setText("ȡ��");
    delBtn_ = new QPushButton(this);
    delBtn_->setText("ɾ��");

    QHBoxLayout *layoutBtn = new QHBoxLayout();
    layoutBtn->addWidget(loadBtn_);
    layoutBtn->addWidget(exitBtn_);
    layoutBtn->addWidget(delBtn_);
    layoutBtn->setContentsMargins(80, 5, 80, 5);

    QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->addWidget(testTable_);
    mainlayout->addLayout(layoutBtn);
   
    setLayout(mainlayout);
}   

void LoadTestDlg::LoadTestList()
{
    if (!m_pAncenter)
        return;
    
   QList<INS_ANSWER_SAVEINFO> infoList;
   if (! m_pAncenter->GetAnswerSaveInfoList(infoList))
   {
       return;
   }

   QList<INS_ANSWER_SAVEINFO>::iterator it = infoList.begin();
   for (int i=0; it != infoList.end(); ++it)
   {
       if (m_strUserName == it->sUser && it->nIndex != m_nAmsweringSaveIndex)
       {
           testTable_->insertRow(i);
           testTable_->setItem(i, 0, new QTableWidgetItem(QString::number(it->nIndex)));
           testTable_->setItem(i, 1, new QTableWidgetItem(it->sTestName));
           testTable_->setItem(i, 2, new QTableWidgetItem(it->sDateTime));
           ++i;
       }
   }
}

QSize LoadTestDlg::SizeHint()
{
    return QSize(800, 600);
}
//slots =====================================================
void LoadTestDlg::ClickLoad()
{
    int nRow = testTable_->currentRow();
    QTableWidgetItem *item = testTable_->item(nRow, 0);
    if (item == NULL)
    {
        return;
    }

    m_nSaveIndex = item->text().toInt();
    emit accept();
}

void LoadTestDlg::Exit()
{
    emit reject();
}

void LoadTestDlg::ClickDel()
{
    int nRow = testTable_->currentRow();
    QTableWidgetItem *item = testTable_->item(nRow, 0);
    if (item == NULL)
    {
        return;
    }
    QMessageBox::StandardButton rb = QMessageBox::warning(this, "warning", "���ڽ��в��ԣ��Ƿ�������ڵĲ��ԣ�", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
    if (rb != QMessageBox::Yes)
    {
        return;
    }

    int nSaveIndex = item->text().toInt();
    if (nSaveIndex == m_nAmsweringSaveIndex)
    {
        QMessageBox::about(this, "ɾ����", "���ڴ���");
        return;
    }
    if (m_pAncenter->DeleteAnswer(nSaveIndex))
    {
        QMessageBox::question(this, "ɾ����", "ɾ���𰸳ɹ�");
    }
    testTable_->removeRow(nRow);
}