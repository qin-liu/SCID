#include "stdafx.h"
#include "questionsmanagedlg.h"
#include "DataCenter.h"
#include "scid.h"
#include "EditContentDlg.h"

QuestionsManageDlg::QuestionsManageDlg(SCID *parent):QDialog((QWidget*)parent),m_scid(parent)
{
    SET_FONT
	m_pData = DATACENTER::instance();

    setWindowTitle(tr("���������"));

	setFont(QFont("Times New Roman", 11));
	setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint); 

	CreateWidget();
	CreateAction();
	ReTranslateStrings();
}

void QuestionsManageDlg::CreateWidget()
{
	//������ť

	importBnt_ = new QPushButton(this);
	importBnt_->setMinimumHeight(40);
	importBnt_->setMaximumWidth(100);
	
	exportBnt_ = new QPushButton(this);
	exportBnt_->setMinimumHeight(40);
	exportBnt_->setMaximumWidth(100);

	QHBoxLayout* oprLayout = new QHBoxLayout();
	oprLayout->addStretch(0);
//	oprLayout->addWidget(AddQuesBtn_);
//	oprLayout->addWidget(delQuesBtn_);
	oprLayout->addWidget(importBnt_);
	oprLayout->addWidget(exportBnt_);
	oprLayout->addStretch(0);
	oprLayout->setSpacing(50);
	oprLayout->setContentsMargins(30, 0, 30, 5);
	oprBtnGroup_ = new QGroupBox(this);
	oprBtnGroup_->setLayout(oprLayout);

	//�������б�
	quesTree_ = new QTreeWidget(this);
	QVBoxLayout* treeLayout = new QVBoxLayout();
	treeLayout->addWidget(quesTree_);
	treeLayout->setContentsMargins(0, 0, 5, 0);
	quesTree_->setMaximumWidth(200);

	//��������
	quesIdTitle_ = new QLabel(this);
	quesIdText_  = new QTextBrowser(this);
	quesIdText_->setMaximumHeight(30);
	quesIdText_->setMaximumWidth(200);
	quesIdText_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QHBoxLayout *idLayout = new QHBoxLayout();
	idLayout->addWidget(quesIdTitle_);
	idLayout->addWidget(quesIdText_);
	idLayout->addStretch(0);

	//����������
	quesTypeTitle_ = new QLabel(this);
	quesType_ = new QComboBox(this);
	quesType_->setMaximumHeight(30);
	quesType_->setMinimumWidth(200);
	QHBoxLayout *typeLayout = new QHBoxLayout();
	typeLayout->addWidget(quesTypeTitle_);
	typeLayout->addWidget(quesType_);
	typeLayout->addStretch(0);
	
	QVBoxLayout* idAndTypeLayout = new QVBoxLayout();
	idAndTypeLayout->addLayout(idLayout);
	idAndTypeLayout->addLayout(typeLayout);


	//ѡ������
	sel0Title_ = new QLabel(this);
	sel1Title_ = new QLabel(this);
	sel2Title_ = new QLabel(this);
	sel3Title_ = new QLabel(this);
	sel0Jump_ = new QTextEdit(this);
	sel1Jump_ = new QTextEdit(this);
	sel2Jump_ = new QTextEdit(this);
	sel3Jump_ = new QTextEdit(this);
	sel0Check_ = new QCheckBox(this);	
	sel1Check_ = new QCheckBox(this);
	sel2Check_ = new QCheckBox(this);
	sel3Check_ = new QCheckBox(this);
	QSplitter *splitter = new QSplitter(this);
	sel0Jump_->setMaximumSize(QSize(300, 30));
	sel1Jump_->setMaximumSize(QSize(300, 30));
	sel2Jump_->setMaximumSize(QSize(300, 30));
	sel3Jump_->setMaximumSize(QSize(300, 30));
	sel0Jump_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	QGridLayout *selLayout = new QGridLayout();
	selLayout->setContentsMargins(20, 20, 500, 20);
	selLayout->setSpacing(10);
	selLayout->addWidget(sel0Title_, 0, 0);
	selLayout->addWidget(sel0Jump_,  0, 1);
	selLayout->addWidget(sel0Check_, 0, 2);
	selLayout->addWidget(sel1Title_, 1, 0);
	selLayout->addWidget(sel1Jump_,  1, 1);
	selLayout->addWidget(sel1Check_, 1, 2);
	selLayout->addWidget(sel2Title_, 2, 0);
	selLayout->addWidget(sel2Jump_,  2, 1);
	selLayout->addWidget(sel2Check_, 2, 2);
	selLayout->addWidget(sel3Title_, 3, 0);
	selLayout->addWidget(sel3Jump_,  3, 1);
	selLayout->addWidget(sel3Check_, 3, 2);
	selectionGroup_ = new QGroupBox(this);
	selectionGroup_->setLayout(selLayout);
	
	//����������
	quesContentGroup_ = new QGroupBox(this);
	quesContent_ = new QTextEdit(this);
    quesContent_->setAcceptRichText(true);
    quesContent_->setFontPointSize(14);

    editContentBnt_ = new QPushButton(this);
    editContentBnt_->setMinimumWidth(20);
	QVBoxLayout *contentLayout = new QVBoxLayout();
	contentLayout->addWidget(quesContent_);
    QHBoxLayout *editBtnlayout = new QHBoxLayout();
    editBtnlayout->addStretch();
    editBtnlayout->addWidget(editContentBnt_);
    
    contentLayout->addLayout(editBtnlayout);
	quesContentGroup_->setLayout(contentLayout);
    
	//��ת
	jumpTable_ = new QTableWidget(this);
    jumpTable_->setColumnCount(6);
    QStringList headList;
    headList <<"��תѡ��"<<"�������"<<"ѡ��?"<<"ѡ��1"<<"ѡ��2"<<"ѡ��3";
    jumpTable_->setHorizontalHeaderLabels(headList);

	addJumpBtn_ = new QPushButton(this);
	delJumpBtn_ = new QPushButton(this);
	jumpGroup_ = new QGroupBox(this);
	QHBoxLayout *jumpBtnLayout = new QHBoxLayout();
	jumpBtnLayout->setSpacing(30);
	jumpBtnLayout->addStretch(0);
	jumpBtnLayout->addWidget(addJumpBtn_);
	jumpBtnLayout->addWidget(delJumpBtn_);

	QVBoxLayout* jumpLayout = new QVBoxLayout();
	jumpLayout->addWidget(jumpTable_);
	jumpLayout->addLayout(jumpBtnLayout);
	jumpGroup_->setLayout(jumpLayout);

	//right layout splitter�ұߵĲ���
	QVBoxLayout *rightLayout = new QVBoxLayout();
	rightLayout->addLayout(idAndTypeLayout);
	rightLayout->addWidget(selectionGroup_);
	rightLayout->addWidget(quesContentGroup_);
	rightLayout->addWidget(jumpGroup_);
	
	QFrame* rightFrame = new QFrame(this);
	rightFrame->setLayout(rightLayout);
	rightFrame->setFrameStyle(QFrame::NoFrame);

	//�м�
	QHBoxLayout *centerLayout = new QHBoxLayout();
	centerLayout->addLayout(treeLayout);
	centerLayout->addWidget(rightFrame);

    //���水ť
    saveBtn_ = new QPushButton(this);
    saveBtn_->setMaximumSize(100, 40);
    cancelBtn_ = new QPushButton(this);
    cancelBtn_->setMaximumSize(100, 40);

    QHBoxLayout *saveLayout = new QHBoxLayout();
    saveLayout->addStretch();
    saveLayout->addWidget(saveBtn_);
    saveLayout->addWidget(cancelBtn_);
    saveLayout->setContentsMargins(100, 5, 30, 5);
    saveLayout->setSpacing(20);

	//main layout
	mainLayout_ = new QVBoxLayout();
	mainLayout_->addWidget(oprBtnGroup_);
	mainLayout_->addLayout(centerLayout);
    mainLayout_->addLayout(saveLayout);
	setLayout(mainLayout_);

}

void QuestionsManageDlg::CreateAction()
{
	connect(this, SIGNAL(LoadTreeSignal()), this, SLOT(DisplayQuesTree()));
	connect(importBnt_, SIGNAL(clicked()), this, SLOT(Import()));
    connect(exportBnt_, SIGNAL(clicked()), this, SLOT(Export()));
	connect(quesTree_,SIGNAL(itemDoubleClicked(QTreeWidgetItem*, int)), this,SLOT(ShowSelectQuesItem(QTreeWidgetItem*,int)));
    connect(saveBtn_, SIGNAL(clicked()), SLOT(ClickSave()));
    connect(cancelBtn_, SIGNAL(clicked()), SLOT(ClickCancel()));
    connect(addJumpBtn_, SIGNAL(clicked()), SLOT(AddCondition()));
    connect(delJumpBtn_, SIGNAL(clicked()), SLOT(DelCondition()));
    connect(editContentBnt_, SIGNAL(clicked()), SLOT(ClickEditContent()));
}

void QuestionsManageDlg::ReTranslateStrings()
{
// 	AddQuesBtn_->setText(tr("�½�"));
// 	delQuesBtn_->setText(tr("ɾ��"));
	importBnt_->setText(tr("����"));
	exportBnt_->setText(tr("����"));
	oprBtnGroup_->setTitle(tr("����"));

	quesTree_->setHeaderLabel(tr("�������б�"));

	quesIdTitle_->setText(tr("��������"));
	quesTypeTitle_->setText(tr("����������"));
    
    quesType_->addItem(tr("ѡ����"), QVariant(1));
    quesType_->addItem(tr("������"), QVariant(2));

	selectionGroup_->setTitle(tr("ѡ������"));
	sel0Title_->setText(tr("ѡ�� ?"));
	sel1Title_->setText(tr("ѡ�� 1"));
	sel2Title_->setText(tr("ѡ�� 2"));
	sel3Title_->setText(tr("ѡ�� 3"));

	quesContentGroup_->setTitle(tr("����������"));
    editContentBnt_->setText(tr("�༭"));
	jumpGroup_->setTitle(tr("��ת����"));
	addJumpBtn_->setText(tr("���"));
	delJumpBtn_->setText(tr("ɾ��"));

    saveBtn_->setText(tr("����"));
    cancelBtn_->setText(tr("ȡ��"));
}

// SLOTS ==============================================================

void QuestionsManageDlg::DisplayQuesTree() //��ʾ��������
{
    quesTree_->clear();

    GROUP_MAP group_map = m_pData->GetGroupMap();
    QUESTION_MAP ques_map = m_pData->GetQuesMap();
    //=============================
    QMap<QString, QTreeWidgetItem*> itemMap;

    GROUP_MAP::iterator it_group = group_map.begin();
    for (; it_group != group_map.end(); ++it_group)
    {
        if (it_group->ulQuestionCount != 0)
        {
            QTreeWidgetItem* groupItem = new QTreeWidgetItem(quesTree_, QStringList(it_group->sName));
            itemMap.insert(it_group->sName, groupItem);
        }
    }
    
    //�������
    QUESTION_MAP::iterator it_ques = ques_map.begin();
    for (; it_ques != ques_map.end(); ++it_ques)
    {
        QString group = GetGroupId(it_ques->sID);
        QMap<QString, QTreeWidgetItem*>::iterator it_find = itemMap.find(group);
        if (it_find != itemMap.end())
        {
            QTreeWidgetItem* quesItem = new QTreeWidgetItem(*it_find, QStringList(it_ques.value().sID));
        }
    }
}

void QuestionsManageDlg::Import()
{
	QMessageBox::StandardButton rb = QMessageBox::question(NULL, "����", "���µ��������ɾ�����в��ԣ�ȷ��Ҫ���µ��룿", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
	if(rb == QMessageBox::No)
	{
		return;
	}

	QString filename = QFileDialog::getOpenFileName(this, "����Excel", QDir::currentPath(), "Excel Files(*.xls)");
	if (filename.indexOf(".xls", 1) == -1)
	{
		if (! filename.isNull())
		{
			QMessageBox::about(this, "����", "��ѡ��Excel�ļ�");
		}
		return;
	}
	
    setCursor(Qt::WaitCursor);
	if (! m_pData->LoadFromExcel(filename))
	{
		QMessageBox::about(NULL, "Import", "����Excel�����ļ�ʧ�ܣ�����Excel�ļ��Ƿ��Ѿ��򿪡�");
	}
    setCursor(Qt::ArrowCursor);
	emit LoadTreeSignal();
    m_scid->InitSCID();
}

void QuestionsManageDlg::Export()
{
    //�������⵽Excel
    QString strFileName;
    strFileName = QFileDialog::getSaveFileName(this, "����������", strFileName, tr("Excel (*.xls)"));
    if (strFileName.isEmpty())
    {
        return;
    }

    YExcel::BasicExcel excel;
    excel.New();
    YExcel::BasicExcelWorksheet* sheet1 = excel.GetWorksheet("Sheet1");
    if (sheet1 == NULL)
    {
        QMessageBox::warning(this, "��������", "�Ҳ���Excel Sheet1 �ı�");
        return;
    }

    ExportSheet1(sheet1);
    if (! excel.SaveAs(strFileName.toAscii().constData()))
    {
        QMessageBox::warning(this, "��������", "����Excelʧ��, ��ע��·�����������ġ�");
    }
    else
    {
        QMessageBox::warning(this, "��������", "����Excel�ɹ���");
    }
}

void QuestionsManageDlg::ShowSelectQuesItem(QTreeWidgetItem* item, int column)
{
	QString str = item->data(0, 0).toString();
	INS_QUESTION ques = m_pData->m_question_map[TransStrToIntID(str)];

 	quesIdText_->setText(ques.sID);

    quesType_->setCurrentIndex(ques.nType - 1);
	sel0Check_->setCheckState(ques.nValid0? Qt::Checked : Qt::Unchecked);
	sel1Check_->setCheckState(ques.nValid1? Qt::Checked : Qt::Unchecked);
	sel2Check_->setCheckState(ques.nValid2? Qt::Checked : Qt::Unchecked);
	sel3Check_->setCheckState(ques.nValid3? Qt::Checked : Qt::Unchecked);

	sel0Jump_->setText(ques.sJump0);
	sel0Jump_->setEnabled(ques.nValid0);
	sel1Jump_->setText(ques.sJump1);
	sel0Jump_->setEnabled(ques.nValid1);
	sel2Jump_->setText(ques.sJump2);
	sel0Jump_->setEnabled(ques.nValid2);
	sel3Jump_->setText(ques.sJump3);
	sel0Jump_->setEnabled(ques.nValid3);

    quesContent_->clear();
    if (ques.sContent.indexOf("<html>")!= -1)
        quesContent_->setHtml(ques.sContent);
    else
        quesContent_->setText(ques.sContent);
	

    //��ʾ��ת������
    int nRow = jumpTable_->rowCount();
    for (int i=0; i<nRow; ++i)
    {
        jumpTable_->removeRow(0);
    }

    QUES_CONDITONMAP_MAP::iterator it_vec_vec = m_pData->m_conditionmap_map.find(ques.sID);
    if (it_vec_vec != m_pData->m_conditionmap_map.end())
    {
        CONDITION_VEC_VEC vec_vec = *it_vec_vec;
        for (int i=0; i<4; ++i)
        {
            CONDITION_VEC vec = vec_vec.at(i);
            CONDITION_VEC::iterator it_condition = vec.begin();
            for (int row=0; it_condition != vec.end(); ++it_condition, ++row)
            {
                INS_CONDITION conditon = *it_condition;
                QTableWidgetItem* item1 = new QTableWidgetItem(QString::number(it_condition->selection));
                QTableWidgetItem* item2 = new QTableWidgetItem(it_condition->sCondtionQuestionid);
                QTableWidgetItem* item3 = new QTableWidgetItem(it_condition->bJumpSelect0? "��":"��");
                QTableWidgetItem* item4 = new QTableWidgetItem(it_condition->bJumpSelect1? "��":"��");
                QTableWidgetItem* item5 = new QTableWidgetItem(it_condition->bJumpSelect2? "��":"��");
                QTableWidgetItem* item6 = new QTableWidgetItem(it_condition->bJumpSelect3? "��":"��");
                jumpTable_->insertRow(row);
                jumpTable_->setItem(row, 0, item1);
                jumpTable_->setItem(row, 1, item2);
                jumpTable_->setItem(row, 2, item3);
                jumpTable_->setItem(row, 3, item4);
                jumpTable_->setItem(row, 4, item5);
                jumpTable_->setItem(row, 5, item6);
            }
        }

    }
}

void QuestionsManageDlg::showEvent ( QShowEvent * event )
{
    showMaximized();
	emit LoadTreeSignal();
}

void QuestionsManageDlg::ClickSave()
{
    QTreeWidgetItem* item = quesTree_->currentItem();
    if (item == NULL)
    {
        return;
    }

    QString strQuesId = item->text(0);

    QUESTION_MAP::iterator it_ques = m_pData->m_question_map.find(TransStrToIntID(strQuesId));
    if (it_ques == m_pData->m_question_map.end())
    {
        return;
    }

    it_ques->nType = quesType_->currentIndex() + 1;

    it_ques->nValid0 = sel0Check_->isChecked()? 1:0;
    it_ques->nValid1 = sel1Check_->isChecked()? 1:0;
    it_ques->nValid2 = sel2Check_->isChecked()? 1:0;
    it_ques->nValid3 = sel3Check_->isChecked()? 1:0;

    it_ques->sContent = quesContent_->toHtml();
    it_ques->sJump0 = sel0Jump_->toPlainText();
    it_ques->sJump1 = sel1Jump_->toPlainText();
    it_ques->sJump2 = sel2Jump_->toPlainText();
    it_ques->sJump3 = sel3Jump_->toPlainText();

    m_pData->SaveQuestion(*it_ques);
//    QMessageBox::about(this, "��������", "����ɹ�");
}

void QuestionsManageDlg::ClickCancel()
{
    emit reject();
}

void QuestionsManageDlg::AddCondition()
{
    int nRowCount = jumpTable_->rowCount();
    jumpTable_->insertRow(nRowCount);
}

void QuestionsManageDlg::DelCondition()
{
    int nRow = jumpTable_->currentRow();
    QMessageBox::StandardButton ret = QMessageBox::question(this, "��ת����", "�Ƿ�Ҫɾ������ת����", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (ret == QMessageBox::Yes)
    {
        jumpTable_->removeRow(nRow);
    } 
}

void QuestionsManageDlg::ClickEditContent()
{
    EditContentDlg *EditDlg = new EditContentDlg(quesContent_->toHtml());
    int nWidth = QApplication::desktop()->width();
    int nHeight = QApplication::desktop()->height();
    EditDlg->resize(nWidth/2, nHeight/2);
    if (EditDlg->exec() == QDialog::Accepted)
    {
        quesContent_->setHtml(EditDlg->GetEditHTMLContent());
        ClickSave(); 
    }   
}

bool QuestionsManageDlg::ExportSheet1(YExcel::BasicExcelWorksheet *pSheet1)
{
    DataCenter *pData = DATACENTER::instance();
    QUESTION_MAP::iterator it_ques = pData->m_question_map.begin();
    for (; it_ques != pData->m_question_map.end(); ++it_ques)
    {
        int nNum = (int)GetGroupId(it_ques->sID).toAscii().at(0);
        int nCol = nNum - 65;
        QString strRow = it_ques->sID.remove(0, 1);
        int nRow = strRow.toInt() - 1;
        pSheet1->Cell(nRow, nCol)->SetWString(reinterpret_cast<const wchar_t*>(it_ques->sContent.unicode()));
    }
    return true;
}