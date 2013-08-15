#include "stdAfx.h"
#include "answerpanel.h"
#include "SelectionWidget.h"

AnswerPanel::AnswerPanel(QMainWindow* parent):QWidget(parent)
{
    answeingIndex_ = -1;

    SET_FONT
    //设置背景色
    setAutoFillBackground(true);
    QPalette p = palette();
    p.setColor(QPalette::Dark, QColor(123,191,234));
    setPalette(p);

	CreateWidget();	
	RetranslateStrings();

	connect(commitBtn_, SIGNAL(clicked()), this, SLOT(CommitAnswer()));
	connect(returnBackBtn_, SIGNAL(clicked()), parent, SLOT(ReturnBack()));
	connect(this, SIGNAL(SendAnswerToParentSignal(INS_ANSWER)), parent, SLOT(CommitAnswer(INS_ANSWER)));
}

void AnswerPanel::CreateWidget()
{	
	QFont ft; 
	ft.setPointSize(15);
	idLabel_ = new QLabel(this);
	idLabel_->setObjectName("IdLabel");
    idLabel_->setFont(ft);
	
    //4-8
    selWidget_ = new SelectionWdiget();

	quesText_ = new QTextBrowser(this);
	quesText_->setObjectName("QuestText");
    quesText_->setAcceptRichText(true);

    //questext font
    quesText_->setFontPointSize(14);

	answerStackView_ = new QStackedWidget(this);
	answerStackView_->setObjectName("AnswerStack");
    answerStackView_->setMaximumHeight(130);

	describeText_ = new QTextEdit(this);
    describeText_->ensureCursorVisible();
    describeText_->setCursorWidth(3);
    describeText_->setFontPointSize(14);
// 	sel0Radio_ = new QRadioButton(this);
// 	sel1Radio_ = new QRadioButton(this);
// 	sel2Radio_ = new QRadioButton(this);
// 	sel3Radio_ = new QRadioButton(this);
	
	groupDescribe_ = new QGroupBox(this);
	QHBoxLayout *layoutDiscribe = new QHBoxLayout();
	layoutDiscribe->addWidget(describeText_);
	groupDescribe_->setLayout(layoutDiscribe);
	
	QHBoxLayout *layoutSelection = new QHBoxLayout();
	layoutSelection->setContentsMargins(180, 0, 60, 0);
// 	layoutSelection->addWidget(sel0Radio_);
// 	layoutSelection->addWidget(sel1Radio_);
// 	layoutSelection->addWidget(sel2Radio_);
// 	layoutSelection->addWidget(sel3Radio_);

    layoutSelection->addWidget(selWidget_);

	groupSelection_ = new QGroupBox(this);
	groupSelection_->setLayout(layoutSelection);
    groupSelection_->setStyleSheet("QGroupBox{border:1px solid skyblue}");

	answerStackView_->addWidget(groupSelection_);
	answerStackView_->addWidget(groupDescribe_);

	returnBackBtn_ = new QPushButton(this);
	returnBackBtn_->setObjectName("ReturnBtn");
	returnBackBtn_->setMinimumHeight(45);
	returnBackBtn_->setMinimumWidth(100);
	commitBtn_ = new QPushButton(this);	
	commitBtn_->setObjectName("CommitBtn");
	commitBtn_->setMinimumHeight(45);
	commitBtn_->setMinimumWidth(100);
    commitBtn_->setFocus(); 
//    commitBtn_->setShortcut(QString("Space")); 

	layoutBottom_ = new QHBoxLayout();
	layoutBottom_->addStretch(0);
	layoutBottom_->addWidget(returnBackBtn_);
	layoutBottom_->addStretch(0);
	layoutBottom_->addWidget(commitBtn_);
	layoutBottom_->addStretch(0);
	layoutBottom_->setMargin(8);

	groupLayout_ = new QVBoxLayout();
	groupLayout_->setSpacing(20);
	groupLayout_->addWidget(idLabel_);
	groupLayout_->addWidget(quesText_);
	groupLayout_->addWidget(answerStackView_);
	groupLayout_->addLayout(layoutBottom_);
	

 	answerPanelGroup_ = new QGroupBox();
	answerPanelGroup_->setTitle("测验");
	answerPanelGroup_->setLayout(groupLayout_);

 	mainLayout = new QVBoxLayout();
 	mainLayout->addWidget(answerPanelGroup_);
	mainLayout->setMargin(10);
 	setLayout(mainLayout);

}

void AnswerPanel::RetranslateStrings()
{
    QFont font;
    font.setPointSize(12);
    font.setBold(true);
    font.setFamily("幼圆");

    idLabel_->setFont(font);
	idLabel_->setText(tr(""));
	answerPanelGroup_->setTitle("测验");
	returnBackBtn_->setText(tr("上一题"));
	commitBtn_->setText(tr("提交"));

	groupDescribe_->setTitle(tr("描述题"));
	groupSelection_->setTitle(tr("选择题"));
// 	sel0Radio_->setText("? 资料不足");
// 	sel1Radio_->setText("1 无或否");
// 	sel2Radio_->setText("2 阈下");
// 	sel3Radio_->setText("3 阈上或是");
}

void AnswerPanel::DisplayNothing()
{
	idLabel_->setText("");
	quesText_->setText("");
	describeText_->clear();
	answerStackView_->setCurrentIndex(1);
}

void AnswerPanel::DiplayQuestion(INS_QUESTION& question, int answeringIndex)
{
	if (answeringIndex < -1)
	{
		return;
	}

	answeringQues_ = question;

    if(question.sID == "L111")
        idLabel_->setText("");
    else
	    idLabel_->setText(question.sID);

    quesText_->clear();

    if (question.sContent.indexOf("<html>") != -1)
    {
        //如果为带格式的<html>
        quesText_->setHtml(question.sContent);
    }
    else
    {
        //纯文本
        quesText_->setText(question.sContent);
    }
	
	answeingIndex_ = answeringIndex + 1;

    if (question.nType == QTYPE_SELECTION)
    {
        ChangeSelectWidgt(question.sID);
        answerStackView_->setCurrentIndex(0);
    }
    else
    {
        describeText_->clear();
        answerStackView_->setCurrentIndex(1);
    }

// 	if (question.nType == QTYPE_SELECTION)
// 	{
// 		//选择题 
// 		if (question.nValid0 == 1)
// 			sel0Radio_->setEnabled(true);
// 		else
// 			sel0Radio_->setEnabled(false);
// 
// 		if (question.nValid1 == 1)
// 			sel1Radio_->setEnabled(true);
// 		else
// 			sel1Radio_->setEnabled(false);
// 
// 		if (question.nValid2 == 1)
// 			sel2Radio_->setEnabled(true);
// 		else
// 			sel2Radio_->setEnabled(false);
// 
// 		if (question.nValid3 == 1)
// 			sel3Radio_->setEnabled(true);
// 		else
// 			sel3Radio_->setEnabled(false);
// 
// 		//默认选项
// 		sel0Radio_->setChecked(false);
// 		sel1Radio_->setChecked(false);
// 		sel2Radio_->setChecked(false);
// 		sel3Radio_->setChecked(false);
// 		if (question.nValid0 == 1)
// 		{
// 			sel0Radio_->setChecked(true);
// 		}
// 		else if (question.nValid1 == 1)
// 		{
// 			sel1Radio_->setChecked(true);
// 		}
// 		else if (question.nValid2 == 1)
// 		{
// 			sel2Radio_->setChecked(true);
// 		}
// 		else if (question.nValid3 == 1)
// 		{
// 			sel3Radio_->setChecked(true);
// 		}
// 		answerStackView_->setCurrentIndex(0);
// 	}
// 	else
// 	{	
// 		//描述题
// 		describeText_->clear();
// 		answerStackView_->setCurrentIndex(1);
// 	}
}


void AnswerPanel::CommitAnswer()
{
	if (answeingIndex_ < 0)
	{
		return;
	}

	INS_ANSWER answer;
	answer.nIndex = answeingIndex_;
	answer.sQuestionid = answeringQues_.sID;
	if (answeringQues_.nType == 1) //选择题
	{
// 		if (sel1Radio_->isChecked())
// 		{
// 			answer.sAnswer = "1";
// 		}
// 		else if (sel2Radio_->isChecked())
// 		{
// 			answer.sAnswer = "2";
// 		}
// 		else if (sel3Radio_->isChecked())
// 		{
// 			answer.sAnswer = "3";
// 		}
// 		else
// 		{
// 			answer.sAnswer = "?";
// 		}

        answer.sAnswer = selWidget_->GetSelAnswer();
	}
	else
	{
		answer.sAnswer = describeText_->toPlainText();
	}
	
	//发消息给父窗口
	emit SendAnswerToParentSignal(answer);
}


void AnswerPanel::ChangeSelectWidgt(QString quesID)
{
    QStringList strList;
    int nValid0 = 1;
    int nValid1 = 1;
    int nValid2 = 1;
    int nValid3 = 1;

    int nQuesID = TransStrToIntID(quesID);
    int nQuesS1 = TransStrToIntID(QString("S1"));
    int nQuesS12 = TransStrToIntID(QString("S12"));
    int nQuesS13 = TransStrToIntID(QString("S13"));
    int nQuesS16 = TransStrToIntID(QString("S16"));

    if (quesID == "P1")
    {
        strList<<"1. 女"<<"2. 男";
    }
    else if (quesID == "P17")
    {
        strList<<"1. 否"<<"3. 是";
    }
    else if (quesID == "P26")
    {
        strList<<"1. 否"<<"3. 是";
    }
    else if (quesID == "P33")
    {
        strList<<"1. 否"<<"3. 是";
    }
    else if (nQuesID >= nQuesS1 && nQuesID <= nQuesS12)
    {
        strList<<"1"<<"2"<<"3";
    }
    else if (nQuesID >= nQuesS13 && nQuesID <= nQuesS16)
    {
        strList<<"1"<<"3";
    }
    else
    {
        strList<<"? 资料不足"<<"1 无或否"<<"2 阈下"<<"3 阈上或是";
        INS_QUESTION ques = DATACENTER::instance()->m_question_map[TransStrToIntID(quesID)];
        nValid0  = ques.nValid0;
        nValid1  = ques.nValid1;
        nValid2  = ques.nValid2;
        nValid3  = ques.nValid3;
    }
   
    selWidget_->ChangeSelectModel(strList.size(), strList, nValid0, nValid1, nValid2, nValid3);
}