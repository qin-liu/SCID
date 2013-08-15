#include "stdAfx.h"
#include "NewTestInfoDlg.h"

NewTestInfoDlg::NewTestInfoDlg()
{
    SET_FONT

    setWindowTitle(tr("新建测试"));
	CreateWidget2();
	setFixedSize(QSize(250, 210));
	connect(okBtn_, SIGNAL(clicked()), this,  SLOT(ClickOk()));
	connect(cancelBtn_, SIGNAL(clicked()), this, SLOT(ClickCancel()));
}

NewTestInfoDlg::~NewTestInfoDlg()
{

}

void NewTestInfoDlg::CreateWidget()
{
	testNameLabel_   = new QLabel(this);
	testNameLabel_->setText(tr("测试名称:"));
	testerNameLabel_ = new QLabel(this);
	testerNameLabel_->setText(tr("  测试人:"));
	answerNameLabel_ = new QLabel(this);
	answerNameLabel_->setText(tr("被测试人:"));
	testNameEdit_   = new QLineEdit(this);
	testNameEdit_->setMaximumHeight(30);
	testerNameEdit_ = new QLineEdit(this);
	testerNameEdit_->setMaximumHeight(30);
	answerNameEdit_ = new QLineEdit(this);
	answerNameEdit_->setMaximumHeight(30);

	QHBoxLayout *layout1 = new QHBoxLayout();
	layout1->addWidget(testNameLabel_);
	layout1->addWidget(testNameEdit_);
	layout1->setContentsMargins(30, 0, 30, 0);
	QHBoxLayout *layout2 = new QHBoxLayout();
	layout2->addWidget(testerNameLabel_);
	layout2->addWidget(testerNameEdit_);
	layout2->setContentsMargins(30, 0, 30, 0);
	QHBoxLayout *layout3 = new QHBoxLayout();
	layout3->addWidget(answerNameLabel_);
	layout3->addWidget(answerNameEdit_);
	layout3->setContentsMargins(30, 0, 30, 0);
	
	okBtn_ = new QPushButton(this);
	okBtn_->setText("确定 ");
	cancelBtn_ = new QPushButton(this);
	cancelBtn_->setText("取消");
	QHBoxLayout *layoutBtn = new QHBoxLayout();
	layoutBtn->addWidget(cancelBtn_);
	layoutBtn->addWidget(okBtn_);
	layoutBtn->setContentsMargins(5, 0, 5, 0);

	QVBoxLayout *mainLayout = new QVBoxLayout();
	mainLayout->addLayout(layout1);
	mainLayout->addLayout(layout2);
	mainLayout->addLayout(layout3);
	mainLayout->addLayout(layoutBtn);
	mainLayout->setSpacing(5);
	setLayout(mainLayout);
}

void NewTestInfoDlg::CreateWidget2()
{
    areaLabel_ = new QLabel(this);
    areaLabel_->setText(tr("单位"));
    areaLabel_->setMaximumSize(60, 20);
    areaBox_ = new QComboBox(this);
    for (int i =1; i<6; ++i)
    {     
        char temp[10] = {0};
        sprintf_s(temp, 10, "%02d", i);
        areaBox_->insertItem(i-1, QString(temp));
    }
    QHBoxLayout *areaLayout = new QHBoxLayout();
    areaLayout->addWidget(areaLabel_);
    areaLayout->addWidget(areaBox_);
    areaLayout->setContentsMargins(10, 0, 10, 0);

    testerLabel_ = new QLabel(this);
    testerLabel_->setText("收集人");
    testerLabel_->setMaximumSize(60, 20);
    testerBox_ = new QComboBox(this);
    for (int i=1; i<100; ++i)
    {
        char temp[10] = {0};
        sprintf_s(temp, 10, "%02d", i);
        testerBox_->insertItem(i-1, QString(temp));
    }
    QHBoxLayout *testerLayout = new QHBoxLayout();
    testerLayout->addWidget(testerLabel_);
    testerLayout->addWidget(testerBox_);
    testerLayout->setContentsMargins(10, 0, 10, 0);

    groupLabel_ = new QLabel(this);
    groupLabel_->setText("分组");
    groupLabel_->setMaximumSize(60, 20);
    groupBox_ = new QComboBox(this);
    groupBox_->insertItem(0, QString('A'));
    groupBox_->insertItem(1, QString('B'));
    groupBox_->insertItem(2, QString('C'));

    QHBoxLayout *groupLayout = new QHBoxLayout();
    groupLayout->addWidget(groupLabel_);
    groupLayout->addWidget(groupBox_);
    groupLayout->setContentsMargins(10, 0, 10, 0);

    answerLabel_ = new QLabel(this);
    answerLabel_->setText("病人");
    answerLabel_->setMaximumSize(60, 20);
    answerBox_ = new QComboBox(this);
    for (int i=1; i<5000; ++i)
    {
        char temp[10] = {0};
        sprintf_s(temp, 10, "%04d", i);
        answerBox_->insertItem(i-1, QString(temp));     
    }
    QHBoxLayout *answerLayout = new QHBoxLayout();
    answerLayout->addWidget(answerLabel_);
    answerLayout->addWidget(answerBox_);
    answerLayout->setContentsMargins(10, 0, 10, 0);

    //BTN
    okBtn_ = new QPushButton(this);
    okBtn_->setText("确定 ");
    cancelBtn_ = new QPushButton(this);
    cancelBtn_->setText("取消");
    QHBoxLayout *layoutBtn = new QHBoxLayout();
    layoutBtn->addWidget(cancelBtn_);
    layoutBtn->addWidget(okBtn_);
    layoutBtn->setContentsMargins(10, 0, 10, 0);
    layoutBtn->setSpacing(20);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(areaLayout);
    mainLayout->addLayout(testerLayout);
    mainLayout->addLayout(groupLayout);
    mainLayout->addLayout(answerLayout);
    mainLayout->addLayout(layoutBtn);
    mainLayout->setSpacing(3);
    setLayout(mainLayout);
}

void NewTestInfoDlg::GetNewTestInfo(QString &strTestName, QString &strTesterName, QString &strAnswerName)
{
// 	strTestName = m_strTestName;
// 	strTesterName = m_strTesterName;
// 	strAnswerName = m_strAnswerName;
    
    strTestName = m_strTestCode;
}

void NewTestInfoDlg::ClickOk()
{
// 	m_strTestName = testNameEdit_->text();
// 	if (m_strTestName.isNull())
// 	{
// 		QMessageBox::about(this, "新的测试", "测试名称不能为空!");
// 		return;
// 	}
// 
// 	m_strTesterName = testerNameEdit_->text();
// 	m_strAnswerName = answerNameEdit_->text();
// 	emit accept();


    //======获取编码
    QString area = areaBox_->currentText();
    QString tester = testerBox_->currentText();
    QString group = groupBox_->currentText();
    QString answer = answerBox_->currentText();

    m_strTestCode = area+tester+group+answer;
    emit accept();
}

void NewTestInfoDlg::ClickCancel()
{
	emit reject();
}