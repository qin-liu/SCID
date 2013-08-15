#include "stdafx.h"
#include "scid.h"
#include "answerstableview.h"
#include "answerstablemodel.h"
#include "answerpanel.h"
#include "questionsmanagedlg.h"
#include "NewTestInfoDlg.h"
#include "LoadTestDlg.h"
#include "UserManageDlg.h"
#include "CheckJumpMode.h"
#include "DiagnoseMangeDlg.h"

SCID::SCID(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	//ui.setupUi(this);  //不使用QT Designer
    QString appPath = QApplication::applicationDirPath()  + "/" + QApplication::applicationName() + ".ini";
//    appPath.replace('/', '\\');
    if (! QFile::exists(appPath))
    {
        FILE *file = fopen(appPath.toAscii().constData(), "w");
        fclose(file);
    }

   m_setting = new QSettings(appPath, QSettings::IniFormat);

    m_bAutoJump = true;
	m_bStartTest = false;
    m_nAnsweringIndex = -1;
    m_nSaveIndex = -1;

    m_pData = DATACENTER::instance();
    m_pAnCenter = ANCENTER::instance();

	CreateActions();
	CreateMenu();
	CreateShotCuts();
	CreateToolBar();
    CreateStatusBar();
	setToolBarIconSize();
	CreateAnswersTableView();

	ReTranslateStrings();

	splitter_ = new QSplitter(Qt::Horizontal);
	splitter_->setHandleWidth(2);
	splitter_->setFrameShadow(QFrame::Sunken);
	splitter_->addWidget(answerTableWidget_);
	splitter_->addWidget(answerPanel_);

	centerWidget_ = new QTabWidget(this);
	centerWidget_->setObjectName("centerWidget");
	centerWidget_->setFocusPolicy(Qt::NoFocus);
	centerWidget_->setMovable(true);

	centerLayout_ = new QHBoxLayout(this);
	centerLayout_->addWidget(splitter_);
	centerLayout_->setContentsMargins(2,0,3,6);
	centerWidget_->setLayout(centerLayout_);
	setCentralWidget(centerWidget_);

    //
    QWidget *menu = menuWidget();
    menu->setAutoFillBackground(true);
    QPalette pa = menu->palette();
    pa.setColor(QPalette::Background, QColor(232,241,247));
    menu->setPalette(pa);

    //读取配置
    ReadSettings();
    
    InitCheckJumpModeMap();
}


SCID::~SCID()
{

}

void SCID::SetLoginUser(INS_USER &user)
{
    m_user = user;

    if (m_user.nRole != 0)
    {
        //非管理员,限制权限
        userManageAct_->setEnabled(false);
        quesManageAct_->setEnabled(false);
    }
    QString str = "用户:" + m_user.sUserName;
    user_status_labela_->setText(str);
}

void SCID::CreateActions()
{
	userManageAct_ = new QAction(this);
	userManageAct_->setObjectName("userManageAct");
	userManageAct_->setIcon(QIcon("./images/userManage.png"));
	connect(userManageAct_, SIGNAL(triggered()), this, SLOT(UserManage()));

	exitAct_ = new QAction(this);
	
	exitAct_->setObjectName("exitAct");
	exitAct_->setIcon(QIcon("./images/exit.png"));
	this->addAction(exitAct_);
	connect(exitAct_, SIGNAL(triggered()), this,  SLOT(CloseApp()));

	helpDocAct_ = new QAction(this);
	helpDocAct_->setObjectName("helpAct");
	connect(helpDocAct_, SIGNAL(triggered()), this,  SLOT(help()));

	aboutAct_ = new QAction(this);
	aboutAct_->setObjectName("aboutAct");
	connect(aboutAct_, SIGNAL(triggered()), this,  SLOT(About()));

	goTestAct_ = new QAction(this);
	goTestAct_->setObjectName("goTestAct");
	goTestAct_->setIcon(QIcon("./images/goTest.png"));
    goTestAct_->setShortcut(QString("S"));
	connect(goTestAct_, SIGNAL(triggered()), this, SLOT(StartTest()));
	
	loadTestAct_ = new QAction(this);
	loadTestAct_->setObjectName("loadTestAct");
	loadTestAct_->setIcon(QIcon("./images/loadTest.png"));
    loadTestAct_->setShortcut(QString("L"));
	connect(loadTestAct_, SIGNAL(triggered()), this, SLOT(LoadTest()));

	changUserAct_ = new QAction(this);
	changUserAct_->setObjectName("changUserAct");
	changUserAct_->setIcon(QIcon("./images/changUser.png"));

	quesManageAct_ = new QAction(this);

#ifdef CLIENT_VERSION
    //enable quesiton manage
    quesManageAct_->setEnabled(false);
#endif

	quesManageAct_->setObjectName("quesManageAct");
	quesManageAct_->setIcon(QIcon("./images/quesManage.png"));
	connect(quesManageAct_, SIGNAL(triggered()), this, SLOT(ShowQuestionManageDlg()));

    diagnoseManageAct_ = new QAction(this);
#ifdef CLIENT_VERSION
    diagnoseManageAct_->setEnabled(false);
#endif
    quesManageAct_->setObjectName("diagnoseAct");
    connect(diagnoseManageAct_, SIGNAL(triggered()), this, SLOT(DiagnoseManage()));

	answersExportAct_ = new QAction(this);
	answersExportAct_->setObjectName("answerExportAct");
	answersExportAct_->setIcon(QIcon("./images/answerExport.png"));
    answersExportAct_->setShortcut(QString("E"));
    connect(answersExportAct_, SIGNAL(triggered()), this, SLOT(ExportAnswerToExcel()));

    returnToAct_ = new QAction(this);
    returnToAct_->setObjectName("ReturnToAct");
    returnToAct_->setIcon(QIcon("./images/returnBackTo.png"));
    returnToAct_->setShortcut(QString("B"));
    connect(returnToAct_, SIGNAL(triggered()), this, SLOT(ClickReturnTo()));

    jumpModeAct_ = new QAction(this);
    jumpModeAct_->setObjectName("JumpModeAct");
    jumpModeAct_->setIcon(QIcon("./images/autoJump.png"));
    jumpModeAct_->setShortcut(QString("A"));
    connect(jumpModeAct_, SIGNAL(triggered()), this, SLOT(SetJumpMode()));

//     fontSetAct_ = new QAction(this);
//     fontSetAct_->setObjectName("FontSet");
//     fontSetAct_->setIcon(QIcon("./images/fontSet.png"));
//     connect(fontSetAct_, SIGNAL(triggered()), this, SLOT(FontSet()));

    fontColorAct_ = new QAction(this);
    fontColorAct_->setObjectName("FontColorAct");
}

void SCID::CreateMenu()
{
	sysMenu_ = new QMenu("系统管理", this);
	menuBar()->addMenu(sysMenu_);
	sysMenu_->addAction(userManageAct_);
    sysMenu_->addAction(quesManageAct_);
    sysMenu_->addAction(diagnoseManageAct_);
	sysMenu_->addSeparator();
	sysMenu_->addAction(exitAct_);

	helpMenu_ = new QMenu("帮助", this);
	menuBar()->addMenu(helpMenu_);
	helpMenu_->addAction(helpDocAct_);
	helpMenu_->addAction(aboutAct_);

    setMenu_ = new QMenu("设置", this);
//  menuBar()->addAction(fontSetAct_);
    menuBar()->addAction(fontColorAct_);
}

void SCID::CreateShotCuts()
{
	exitAct_->setShortcut(QKeySequence(Qt::CTRL+Qt::Key_Q));
	helpDocAct_->setShortcut(QKeySequence(Qt::Key_F8));
}

void SCID::CreateToolBar()
{
	mainToolbar_ = new QToolBar(this);
	mainToolbar_->setObjectName("mainToolBar");
    mainToolbar_->setAutoFillBackground(true);

	mainToolbar_->setMovable(false);
	mainToolbar_->setAllowedAreas(Qt::TopToolBarArea);
	mainToolbar_->setContextMenuPolicy(Qt::DefaultContextMenu);
    mainToolbar_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
	addToolBar(mainToolbar_);
 
    mainToolbar_->addAction(goTestAct_);
    mainToolbar_->addAction(loadTestAct_);
    mainToolbar_->addAction(returnToAct_);  
    mainToolbar_->addAction(jumpModeAct_);
    mainToolbar_->addAction(answersExportAct_);
//  mainToolbar_->addAction(fontSetAct_);
    mainToolbar_->addSeparator();
    mainToolbar_->addAction(exitAct_);

    mainToolbar_->widgetForAction(goTestAct_)->setMinimumWidth(60);
    mainToolbar_->widgetForAction(goTestAct_)->setMinimumHeight(55);
    mainToolbar_->widgetForAction(loadTestAct_)->setMinimumWidth(60);
    mainToolbar_->widgetForAction(loadTestAct_)->setMinimumHeight(55);
    mainToolbar_->widgetForAction(returnToAct_)->setMinimumWidth(60);
    mainToolbar_->widgetForAction(returnToAct_)->setMinimumHeight(55);
    mainToolbar_->widgetForAction(jumpModeAct_)->setMinimumWidth(60);
    mainToolbar_->widgetForAction(jumpModeAct_)->setMinimumHeight(55);
    mainToolbar_->widgetForAction(answersExportAct_)->setMinimumWidth(60);
    mainToolbar_->widgetForAction(answersExportAct_)->setMinimumHeight(55);
//  mainToolbar_->widgetForAction(fontSetAct_)->setMinimumWidth(60);
//  mainToolbar_->widgetForAction(fontSetAct_)->setMinimumHeight(55);
    mainToolbar_->widgetForAction(exitAct_)->setMinimumWidth(60);
    mainToolbar_->widgetForAction(exitAct_)->setMinimumHeight(55);
}

void SCID::CreateStatusBar()
{
    statusBar_ = new QStatusBar;
    user_status_labela_ = new QLabel;
    user_status_labela_ = new QLabel();
    statusBar_->addPermanentWidget(user_status_labela_);
    setStatusBar(statusBar_);
}

void SCID::ReTranslateStrings()
{
	userManageAct_->setText(tr("用户管理(&U)..."));
	exitAct_->setText(tr("退出"));
	helpDocAct_->setText(tr("帮助文档(&H)"));
	aboutAct_->setText(tr("关于(&A)..."));
	
	goTestAct_->setText(tr("开始新测验(&S)"));
	loadTestAct_->setText(tr("加载测验(&L)"));
    jumpModeAct_->setText(tr("自动跳转(&A)"));
    returnToAct_->setText(tr("返回(&B)"));
	answersExportAct_->setText(tr("答案导出(&E)"));
	quesManageAct_->setText(tr("题库管理(&Q)"));
    diagnoseManageAct_->setText("诊断管理(&D)");
//	fontSetAct_->setText("字体设置");
	answerTableWidget_->setWindowTitle(tr("答案列表"));
}

void SCID::setToolBarIconSize()
{
	mainToolbar_->setIconSize(QSize(32, 32));
}

void SCID::CreateAnswersTableView()
{
	answerTableWidget_ = new QTableWidget(this);
	answerTableWidget_->setObjectName("AnswerTableWidget");
	answerTableWidget_->setRowCount(0);
	answerTableWidget_->setColumnCount(2);
	answerTableWidget_->setColumnWidth(0, 80);
	answerTableWidget_->setColumnWidth(1, 300);
	answerTableWidget_->setFrameStyle(QFrame::Plain);
	answerTableWidget_->setEditTriggers(QAbstractItemView::NoEditTriggers);
	answerTableWidget_->setSelectionBehavior(QAbstractItemView::SelectRows);
	answerTableWidget_->setSelectionMode(QAbstractItemView::SingleSelection);
	answerTableWidget_->horizontalHeader()->setStretchLastSection(true);
	QHeaderView* headerView = answerTableWidget_->verticalHeader();
	headerView->setHidden(false);

	QStringList headList;
	headList << "题号" << "答案";
	answerTableWidget_->setHorizontalHeaderLabels(headList);
    answerTableWidget_->horizontalHeader()->setFixedHeight(25);
    answerTableWidget_->horizontalHeader()->setStyleSheet("QHeaderView::section {background-color:skyblue;color: black;padding-left: 4px;border: 1px solid #6c6c6c;}");
    answerTableWidget_->verticalHeader()->setStyleSheet("QHeaderView::section {  background-color:lightblue;color: black;padding-left: 4px;border: 1px solid #6c6c6c}");

	answerPanel_ = new AnswerPanel(this);
	answerPanel_->setObjectName("AnswerPanel");
	
	//行的双击事件，显示答案文本框
	connect(answerTableWidget_, SIGNAL(doubleClicked(const QModelIndex&)), SLOT(DBClickToShowAnswer(const QModelIndex&)));
}

//Slots ======================================================
void SCID::ShowQuestionManageDlg()
{
	QuestionsManageDlg* pQuesDlg = new QuestionsManageDlg(this);
	pQuesDlg->exec();
}

void SCID::DiagnoseManage()
{
    DiagnoseMangeDlg* pDiagnoseManageDlg = new DiagnoseMangeDlg(this);
    pDiagnoseManageDlg->exec();
}

void SCID::StartTest()
{
    if (m_pData->m_question_map.isEmpty())
    {
        QMessageBox::about(this, tr("开始测试"), tr("没有可加载的测试题"));
        return;
    }

	if (m_bStartTest)
	{
		QMessageBox::StandardButton rb = QMessageBox::warning(this, "warning", "正在进行测试，是否放弃现在的测试？", QMessageBox::Yes | QMessageBox::No, QMessageBox::No);
		if(rb == QMessageBox::No)
		{
			return;
		}
	}
	
TEST_INFO:
	//填写测试信息
	INS_ANSWER_SAVEINFO answerInfo;
	NewTestInfoDlg *newTest = new NewTestInfoDlg;
	if (newTest->exec() == QDialog::Rejected)
	{
		return;
	}
	else
	{
		newTest->GetNewTestInfo(answerInfo.sTestName, answerInfo.sTesterName, answerInfo.sAnswerName);
        answerInfo.sUser = m_user.sUserName;
        answerInfo.sDateTime = QDateTime::currentDateTime().toString(Qt::LocalDate);
	}

	//创建数据库答案保存相关
	int nRet = m_pAnCenter->CreateAnswerSave(answerInfo);
	if (-1 == nRet)
	{
		//创建失败
		QMessageBox::critical(NULL, "错误", "创建答案保存数据失败", QMessageBox::Yes, QMessageBox::Yes);
		return;
	}
	else if (-2 == nRet)
	{
		QMessageBox::StandardButton rb = QMessageBox::question(NULL, "开始测试", "你创建的测试名已存在，是否重新创建？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
		if (rb == QMessageBox::Yes)
		{
			goto TEST_INFO; //重新输入
		}
		else
		{
			return;
		}
	}	
    
   //初始化为最初状态
    InitSCID();

    //答案保存序号
     m_nSaveIndex = nRet;

	//加载第一题
	QString strQuesId;
	
    //开始测验标志
    m_bStartTest = true;

	INS_QUESTION question = m_pData->m_question_map.begin().value();
	answerPanel_->DiplayQuestion(question, m_nAnsweringIndex);

    statusBar_->showMessage("开始测验", 0);
}

void SCID::ClickUserManage()
{
    
}

void SCID::DisplayAnswerList(int nSaveIndex)
{
    ANSWER_VECTOR answer_vec;
    if (! m_pAnCenter->GetAnswerVectorByIndex(nSaveIndex, answer_vec))
    {
        return;
    }
       
    int nRow = answerTableWidget_->rowCount();
    for(int i=nRow; i>=0; --i)
    {
        answerTableWidget_->removeRow(i);
    }

    ANSWER_VECTOR::iterator it = answer_vec.begin();
    for (int row = 0; it != answer_vec.end(); ++it, ++row)
    {
        answerTableWidget_->insertRow(row);
        QTableWidgetItem *item0 = new QTableWidgetItem(it->sQuestionid);
        QTableWidgetItem *item1 = new QTableWidgetItem(it->sAnswer);
        item0->setToolTip(it->sAnswer);
        item1->setToolTip(it->sAnswer);
        answerTableWidget_->setItem(row, 0, item0);
        answerTableWidget_->setItem(row, 1, item1);
        m_nAnsweringIndex = it->nIndex;
    }

    QString strLastQuesId;
    QString strAnswer;
    INS_QUESTION nextQues;
    int answerIndex = -1; 
    if (! answer_vec.isEmpty())
    {
        strLastQuesId = answer_vec.back().sQuestionid;
        strAnswer = answer_vec.back().sAnswer;
        answerIndex = answer_vec.back().nIndex;
    }
    QString strNextQues = m_pData->GetNextQuestionByJumpCondition(strLastQuesId, strAnswer, m_pAnCenter, m_nSaveIndex, nextQues);
    answerPanel_->DiplayQuestion(nextQues, answerIndex);
}

void SCID::LoadTest()
{
	//加载保存的测试
    LoadTestDlg loadTestDlg(this, m_pAnCenter, m_user.sUserName, m_nSaveIndex);
    if (loadTestDlg.exec() == QDialog::Accepted)
    {
        //加载测试
        int nSaveIndex = loadTestDlg.GetAnswerSaveIndex();
        if (m_nSaveIndex != nSaveIndex)
        {
            m_nSaveIndex = nSaveIndex;
            DisplayAnswerList(m_nSaveIndex);
            m_pAnCenter->GetAnswerVectorByIndex(m_nSaveIndex, m_answer_vec);
        } 
        m_bStartTest = true;
    }
    statusBar_->showMessage("开始测验");
}
void SCID::ReturnBack()
{   
	ReturnBackTo(m_nAnsweringIndex - 1);
}

void SCID::CommitAnswer(INS_ANSWER answer)
{
    //查找下一题

    bool bAutoJump = true;
    if (MANUAL_JUMP == CheckJumpMode(answer.sQuestionid, answer.sAnswer))
    {
        //必须手动跳转
        bAutoJump = false;
    }
    else
    {
        if (! m_bAutoJump)
        {
            //可以自动跳转,但选择了手动跳转
            bAutoJump = false;
        }
    }

    INS_QUESTION question;
    if (bAutoJump)
    {
        //自动跳转
        int nRet = m_pData->GetNextQuestionByJumpCondition(answer.sQuestionid, answer.sAnswer, m_pAnCenter, m_nSaveIndex, question);
        if (-1 == nRet)
        {
            //未查找到下一题
            QMessageBox::about(this, "跳转", "查找下一题失败");
            return;
        }
        else if (0 == nRet)
        {
            //最后一题
            QMessageBox::about(this, "SCID", "已完成测试最后一题");
            statusBar_->showMessage("测验最后一题已完成");
            return;
        }
    }
    else
    {
        //手动跳转
        JumpNextQuesitonDlg jumpDlg(question.sID);
        int nRet = jumpDlg.exec();
        if (QDialog::Accepted == nRet)
        {
            jumpDlg.GetNextQeustion(question);
        }
        else
        {
            return;
        }
    }

    answerTableWidget_->insertRow(answerTableWidget_->rowCount());
    QTableWidgetItem *item0 = new QTableWidgetItem(answer.sQuestionid);
    QTableWidgetItem *item1 = new QTableWidgetItem(answer.sAnswer);
    item0->setToolTip(answer.sAnswer);
    item1->setToolTip(answer.sAnswer);
    answerTableWidget_->setItem(answer.nIndex, 0, item0);
    answerTableWidget_->setItem(answer.nIndex, 1, item1);
    m_nAnsweringIndex = answer.nIndex;

    //数据库同步
    m_pAnCenter->CommitAnswer(m_nSaveIndex, answer);
    m_answer_vec.push_back(answer);
    answerPanel_->DiplayQuestion(question, m_nAnsweringIndex);
    int nRow = answerTableWidget_->rowCount();
    answerTableWidget_->setCurrentCell(nRow-1, 0);


//====
    INS_ANSWER sta_answer;
    INS_QUESTION static_jump_question;
    //判断是否为统计题, 返回1为统计题需要自动跳转
    if (1 == m_pData->GetStatisticsJump(question.sID, m_pAnCenter, m_nSaveIndex, sta_answer, static_jump_question))
    {
        QMessageBox::warning(this, "自动统计", question.sID + "自动统计答案为 " + sta_answer.sAnswer);
        if (MANUAL_JUMP == CheckJumpMode(question.sID, sta_answer.sAnswer))
        {
            //必须手动跳转
            //手动跳转
            JumpNextQuesitonDlg jumpDlg(question.sID);
            int nRet = jumpDlg.exec();
            if (QDialog::Accepted == nRet)
            {
                jumpDlg.GetNextQeustion(static_jump_question);
            }
            else
            {
                return;
            }
        }

        //显示统计题
        sta_answer.nIndex = m_nAnsweringIndex+1;

        answerTableWidget_->insertRow(answerTableWidget_->rowCount());
        QTableWidgetItem *item0 = new QTableWidgetItem(sta_answer.sQuestionid);
        QTableWidgetItem *item1 = new QTableWidgetItem(sta_answer.sAnswer);
        item0->setToolTip(sta_answer.sAnswer);
        item1->setToolTip(sta_answer.sAnswer);
        answerTableWidget_->setItem(sta_answer.nIndex, 0, item0);
        answerTableWidget_->setItem(sta_answer.nIndex, 1, item1);
        m_nAnsweringIndex = sta_answer.nIndex;
        
        //数据库同步
        m_pAnCenter->CommitAnswer(m_nSaveIndex, sta_answer);
        m_answer_vec.push_back(sta_answer);
        answerPanel_->DiplayQuestion(static_jump_question, m_nAnsweringIndex);
        int nRow = answerTableWidget_->rowCount();
        answerTableWidget_->setCurrentCell(nRow-1, 0);
    }
}

void SCID::DBClickToShowAnswer(const QModelIndex &index)
{
	int nRow = index.row();
	QTableWidgetItem *item0 = answerTableWidget_->item(nRow, 0);
	QTableWidgetItem *item1 = answerTableWidget_->item(nRow, 1);
    if (!item0 || !item1)
    {
        return;
    }

	QString sQuesID = item0->text();
	QString sAnswer = item1->text();

	QDialog *textDlg = new QDialog();
	QTextBrowser* textBrowser = new QTextBrowser(textDlg);
    textBrowser->setAcceptRichText(true);
    QTextBrowser* textBrowser_answer = new QTextBrowser(textDlg);

	QHBoxLayout* layout = new QHBoxLayout(textDlg);
	
	textDlg->setWindowFlags(Qt::FramelessWindowHint);
	textDlg->setAttribute(Qt::WA_DeleteOnClose);
	textDlg->setWindowFlags(Qt::WindowStaysOnTopHint);
	layout->addWidget(textBrowser);
    layout->addWidget(textBrowser_answer);
	layout->setContentsMargins(0, 0, 0, 0);
	textDlg->setLayout(layout);
	textDlg->setWindowTitle(sQuesID);

    INS_QUESTION ques = m_pData->m_question_map[TransStrToIntID(sQuesID)];
    if (ques.sContent.indexOf("<html>"))
    {
        textBrowser->setHtml(ques.sContent);
    }
    else
    {
        textBrowser->setText(ques.sContent);
    }
	
    textBrowser_answer->setText(sAnswer);
	textDlg->show();
}

void SCID::About()
{
    QMessageBox about(QMessageBox::NoIcon, "关于SCID", "SCID V2.0.1 Release"); 
    about.setIconPixmap(QPixmap("./images/SCID.ico")); 
    about.exec();
}

void SCID::FontSet()
{
    bool bOk = false;
    QFont curFont;
    curFont.setFamily(m_answerPanelFont);
    curFont.setPointSize(m_answerPanelFontSize);

    QFont font = QFontDialog::getFont(&bOk, curFont);
    if (bOk)
    {
        m_answerPanelFont = font.family();
        m_answerPanelFontSize = font.pointSize();
    }
}

void SCID::help()
{
    QMessageBox::about(this, "帮助", "请在安装路径查看《SCID软件说明书》文档");
}

void SCID::CloseApp()
{
    statusBar_->showMessage("退出");
    WriteSettings();
    qApp->quit();
}



//==============================================================================
void SCID::ReturnBackTo(int nAnwserIndex)
{
	if (nAnwserIndex < -1 || nAnwserIndex == m_nAnsweringIndex)
	{
		return;
	}

	//先同步数据库
	if (! m_pAnCenter->ReturnBackTo(m_nSaveIndex, nAnwserIndex))
	{
		QMessageBox::critical(NULL, "数据库错误", "ReturnBackTo 失败", QMessageBox::Yes, QMessageBox::Yes);
        return;
	}

	//撤销到第nAnwserIndex（0开始）次答题
	int nCount = answerTableWidget_->rowCount();

	QString strQuesIdLast;
	for (int i=nCount-1; i>nAnwserIndex; --i)
	{
		strQuesIdLast = answerTableWidget_->item(i, 0)->text();
		answerTableWidget_->removeRow(i);
        m_answer_vec.remove(i);
		m_nAnsweringIndex--;
	}

	answerPanel_->DiplayQuestion(m_pData->m_question_map[TransStrToIntID(strQuesIdLast)], nAnwserIndex);
	answerTableWidget_->setCurrentCell(answerTableWidget_->rowCount()-1, 0);
}

void SCID::ClickReturnTo()
{
    QMessageBox::StandardButton bRet = QMessageBox::question(this, "返回", "返回会将此题后测试删除，确定要返回到选择的测试题？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (bRet == QMessageBox::Yes)
    {
        int nRow = answerTableWidget_->currentRow();
        ReturnBackTo(nRow);
    }
}

void SCID::InitSCID()
{
    //清空界面
    int nRowCount = answerTableWidget_->rowCount();
    for (int i=nRowCount-1; i>=0; --i)
    {	
        answerTableWidget_->removeRow(i);
    }

    answerPanel_->DisplayNothing();
    m_answer_vec.clear();
    m_bStartTest = false;
    m_nAnsweringIndex = -1;
}

void SCID::UserManage()
{
    UserManageDlg userManagDlg;
    userManagDlg.exec();
}

void SCID::SetJumpMode()
{
    m_bAutoJump  = !m_bAutoJump;
    if (m_bAutoJump)
    {
        jumpModeAct_->setIcon(QIcon("./images/autoJump.png"));
        jumpModeAct_->setIconText("自动跳转(&A)");
    }
    else
    {
        jumpModeAct_->setIcon(QIcon("./images/manualJump.png"));
        jumpModeAct_->setIconText("手动跳转(&A)");
    }
}

void SCID::GetDiagnosisMatchList(DIAGNOSIS_VEC &diag_vec)
{
    //### 外部诊断和答案列表必须是排序的,
    //然后按顺序遍历，得到匹配选项的诊断

    ANSWER_VECTOR::iterator it_ans = m_answer_vec.begin();
   
    for (; it_ans != m_answer_vec.end(); ++it_ans)
    {
        DIAGNOSIS_VEC::iterator it_dia = m_pData->m_diagnosis_vec.begin();
        for (; it_dia != m_pData->m_diagnosis_vec.end(); ++it_dia)
        {
            //遍历诊断列表
            if(it_ans->sQuestionid == it_dia->sQuestionid)
            {
                 if (it_ans->sAnswer.indexOf(it_dia->sKeyContent) != -1)
                 {
                     bool bMatchd = true;

                     //一些特殊的诊断的判断F93和F98
                     if (it_dia->sQuestionid == "F93" || it_dia->sQuestionid == "F98")
                     {
                         int nQuesCount = (it_dia->sQuestionid == "F93"? 4:2);
                         
                         QString sKeyCompare = it_dia->sKeyContent;

                        //F93-F96 都选1  诊断“无强迫观念”
                         ANSWER_VECTOR::iterator it_temp = it_ans;
                         for (int i=0; i<nQuesCount; ++i, ++it_temp)
                         {
                             if (it_temp == m_answer_vec.end() || it_temp->sAnswer != sKeyCompare)
                             {
                                 bMatchd = false;
                                 break;
                             }
                         }
                     }//if F93 F98

                     //匹配成功
                     if (bMatchd)
                     {
                        diag_vec.push_back(*it_dia);
                     }
                 }//if indexof
            }//if diagnose
        }//end for
    }
}

int SCID::GetSel3Count(ANSWER_VECTOR &vec, QString strStartQuesId, int nQuesCount)
{
    //得到连续的题中答案是3的个数
    int nSel3Count = 0;
    int nIntId = TransStrToIntID(strStartQuesId);
    QString strQuesId = strStartQuesId;

    for (int i=0; i<nQuesCount; ++i)
    {
        INS_ANSWER ans;
        ans.sQuestionid = strQuesId;
        ans.sAnswer = "3";

        int nIndex = vec.indexOf(ans);
        if (nIndex != -1)
        {
            nSel3Count++;
        }
        strQuesId = TransIntIDToStr(++nIntId);
    }
    return nSel3Count;
}

void SCID::GetLGroupDiagnoseList(DIAGNOSIS_VEC &diag_vec)
{
    ANSWER_VECTOR L_an_Vec; //SCIDII L组的题目
    ANSWER_VECTOR::iterator it_ans = m_answer_vec.begin();
    for (; it_ans != m_answer_vec.end(); ++it_ans)
    {
        if (it_ans->sQuestionid.indexOf('L') != -1)
        {
            L_an_Vec.push_back(*it_ans);
        }
    }

    //回避性 
    if (GetSel3Count(L_an_Vec, "L1", 7) >= 4)
    { 
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "回避性";
        diagnosis.sQuestionid = "L1";
        diag_vec.push_back(diagnosis);
    }

    //依赖性 
    if (GetSel3Count(L_an_Vec, "L8", 8) >= 5)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "依赖性";
        diagnosis.sQuestionid = "L8";
        diag_vec.push_back(diagnosis);
    }
    
    //强迫性 
    if (GetSel3Count(L_an_Vec, "L16", 8) >= 4)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "强迫性";
        diagnosis.sQuestionid = "L16";
        diag_vec.push_back(diagnosis);
    }

    //被动攻击性 
    if (GetSel3Count(L_an_Vec, "L24", 7) >= 4)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "被动攻击性";
        diagnosis.sQuestionid = "L24";
        diag_vec.push_back(diagnosis);
    }

    //抑郁性 
    if (GetSel3Count(L_an_Vec, "L31", 7) >= 5)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "抑郁性";
        diagnosis.sQuestionid = "L31";
        diag_vec.push_back(diagnosis);
    }

    //偏执性 
    if (GetSel3Count(L_an_Vec, "L38", 7) >= 4)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "偏执性";
        diagnosis.sQuestionid = "L38";
        diag_vec.push_back(diagnosis);
    }

    //分裂型 
    if (GetSel3Count(L_an_Vec, "L45", 9) >= 5)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "分裂型";
        diagnosis.sQuestionid = "L45";
        diag_vec.push_back(diagnosis);
    }

    //分裂样 
    if (GetSel3Count(L_an_Vec, "L54", 7) >= 4)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "分裂样";
        diagnosis.sQuestionid = "L54";
        diag_vec.push_back(diagnosis);
    }

    //表演性 
    if (GetSel3Count(L_an_Vec, "L61", 8) >= 5)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "表演性";
        diagnosis.sQuestionid = "L61";
        diag_vec.push_back(diagnosis);
    }

    //自恋性 
    if (GetSel3Count(L_an_Vec, "L69", 9) >= 5)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "自恋性";
        diagnosis.sQuestionid = "L69";
        diag_vec.push_back(diagnosis);
    }

    //边缘性 
    if (GetSel3Count(L_an_Vec, "L78", 9) >= 5)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sDiagnosis = "边缘性";
        diagnosis.sQuestionid = "L78";
        diag_vec.push_back(diagnosis);
    }

    //反社会性A 
    if (GetSel3Count(L_an_Vec, "L87", 7) >= 3)
    {
        // 反社会性C
        if (GetSel3Count(L_an_Vec, "L94", 15) >= 2)
        {
            INS_DIAGNOSIS diagnosis;
            diagnosis.sDiagnosis = "反社会性";
            diagnosis.sQuestionid = "L87";
            diag_vec.push_back(diagnosis);
        }
    }

    //未分型
    INS_ANSWER ans;
    if (! L_an_Vec.isEmpty())
    {
        ans = L_an_Vec.last();
        if (ans.sQuestionid == "L110")
        {
           //过滤掉空格和回车再判断是否为空
           QString strTemp = ans.sAnswer;
           strTemp = strTemp.simplified();
           if (! strTemp.isEmpty())
           {
               INS_DIAGNOSIS diagnosis;
               diagnosis.sDiagnosis = "未分型";
               diagnosis.sQuestionid = "L110";
               diag_vec.push_back(diagnosis);
           }
        }
    }
}

bool SCID::ExportAnswerToExcel()
{
    if (! m_bStartTest)
    {
        QMessageBox::about(this, "导出答案", "没有开始测试");
        return true;
    }
    //导出试题答案
    QString strFileName;
    m_pAnCenter->GetTestNameBySaveIndex(m_nSaveIndex, strFileName);
    strFileName = QFileDialog::getSaveFileName(this, "导出答案", strFileName, tr("Excel (*.xls)"));
    if (strFileName.isEmpty())
    {
        return true;
    }

    YExcel::BasicExcel excel;
    excel.New();
    YExcel::BasicExcelWorksheet* sheet = excel.GetWorksheet("Sheet1");
    if (sheet == NULL)
    {
        QMessageBox::warning(this, "导出答案", "找不到Excel Sheet1 的表");
        return false;
    }

    ANSWER_VECTOR an_vec;
    if (! m_pAnCenter->GetAnswerVectorByIndex(m_nSaveIndex, an_vec))
    {
        QMessageBox::warning(this, "导出答案", "得到答案列表失败");
        return false;
    }

    int nMaxCol = 0;

    //导出答案
    ANSWER_VECTOR::iterator it = an_vec.begin();
    for (; it != an_vec.end(); ++it)
    {
        //A~Z ASCII是 65~90 
        int nNum = (int)GetGroupId(it->sQuestionid).toAscii().at(0);
        int nCol = nNum - 65;
        nMaxCol = nMaxCol < nCol? nCol:nMaxCol;
        if (nCol < 0 || nCol > 25)
        {
            continue;
        }
        QString strRow = it->sQuestionid.remove(0, 1);
        int nRow = strRow.toInt() - 1;
        if (nRow < 0)
        {
            continue;
        }
        sheet->Cell(nRow, nCol)->SetWString(reinterpret_cast<const wchar_t*>(it->sAnswer.unicode()));
    }

    //导出诊断
    if (nMaxCol > 90 - 65 /*Z列*/)
    {
        QMessageBox::about(this, "导出答案", "无法导出诊断，没有剩余列");
    }
    int nDiagnosisCol = nMaxCol + 1;
    ExportDiagnosis(sheet, nDiagnosisCol);
    
    HCURSOR hCursor = GetCursor();
    setCursor(Qt::WaitCursor);
    QMessageBox::warning(this, "导出答案", strFileName.toAscii().constData());

    statusBar_->showMessage("正在导出答案到Excel...", 0);
    if(! excel.SaveAs(strFileName.toAscii().constData()))
    {
        QMessageBox::warning(this, "导出答案", "保存Excel失败, 请注意路径不能有中文。");
        setCursor(hCursor);
        return false;
    }
    
    setCursor(hCursor);
    QMessageBox::about(this, "导出答案", "保存成功");
    statusBar_->clearMessage();
    return true;
}

bool SCID::ExportDiagnosis(YExcel::BasicExcelWorksheet* pSheet, int nCol)
{
    if (! pSheet)
        return false;

    DIAGNOSIS_VEC diagnosis_scid1_vec;  //获得的诊断的rowid链表
    GetDiagnosisMatchList(diagnosis_scid1_vec);
    DIAGNOSIS_VEC diagnosis_scid2_vec;  //获得的诊断的rowid链表
    GetLGroupDiagnoseList(diagnosis_scid2_vec);

    diagnosis_scid1_vec += diagnosis_scid2_vec;

    pSheet->Cell(0, nCol)->SetWString(L"诊断");
    DIAGNOSIS_VEC::iterator it_dia = diagnosis_scid1_vec.begin();
    statusBar_->showMessage("正在导出诊断...");

    for (int i=1; it_dia != diagnosis_scid1_vec.end(); ++it_dia, ++i)
    {
        pSheet->Cell(i, nCol)->SetWString(reinterpret_cast<const wchar_t*>(it_dia->sDiagnosis.unicode()));
    }
    statusBar_->clearMessage();
    return true;
}



void SCID::WriteSettings()
{
    m_setting->beginGroup("system");
    m_setting->setValue("answerPanelFont", m_answerPanelFont);
    m_setting->setValue("answerPanelFontSize", m_answerPanelFontSize);
    m_setting->endGroup();
}

void SCID::ReadSettings()
{
    m_setting->beginGroup("system");
    m_answerPanelFont = m_setting->value("answerPanelFont", qApp->font().family()).toString();
    m_answerPanelFontSize = m_setting->value("answerPanelFontSize", 12).toInt();
    m_setting->endGroup();
}

// JumpNextQuesitonDlg ==================================================
JumpNextQuesitonDlg::JumpNextQuesitonDlg(QString text):m_text(text)
{
    m_pDataCenter = DATACENTER::instance();
    
    nextQuesLabel_ = new QLabel(this);
    nextQuesLabel_->setText(tr("跳转到: "));
   
    OkBtn_ = new QPushButton(this);
    OkBtn_->setText(tr("确定"));
    cancelBtn_ = new QPushButton(this);
    cancelBtn_->setText(tr("取消"));

    quesIdCombo_ = new QComboBox(this);
    quesIdCombo_->setEditable(true);

    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(nextQuesLabel_);
    layout->addWidget(quesIdCombo_);
    layout->setContentsMargins(5, 5, 5, 0);
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(OkBtn_);
    btnLayout->addWidget(cancelBtn_);
    btnLayout->setContentsMargins(20, 0, 20, 0);
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(layout);
    mainLayout->addLayout(btnLayout);
    setLayout(mainLayout);

    QUESTION_MAP::iterator it = m_pDataCenter->m_question_map.begin();
    for (; it != m_pDataCenter->m_question_map.end(); ++it)
    {
        quesIdCombo_->addItem(it->sID);
    }
    
    connect(OkBtn_, SIGNAL(clicked()), this, SLOT(ClickOk()));
    connect(cancelBtn_, SIGNAL(clicked()), this, SLOT(ClickCancel()));

    QString title = text + "手动跳转到";
    setWindowTitle(title);
    setFixedSize(QSize(200, 80));
}

JumpNextQuesitonDlg::~JumpNextQuesitonDlg()
{

}

bool JumpNextQuesitonDlg::GetNextQeustion(INS_QUESTION &nextQues)
{
    nextQues = m_nextQues;
    return true;
}

void JumpNextQuesitonDlg::ClickOk()
{
    QString strQuesId = quesIdCombo_->currentText();
    QUESTION_MAP::iterator it = m_pDataCenter->m_question_map.find(TransStrToIntID(strQuesId));
    if (it != m_pDataCenter->m_question_map.end())
    {
        m_nextQues = *it;
        emit accept();
    }
    else
    {
        QMessageBox::about(this, "跳转", "选择的题号不存在");
    }
}

void JumpNextQuesitonDlg::ClickCancel()
{
    emit reject();
}

