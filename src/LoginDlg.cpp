#include "stdafx.h"
#include "LoginDlg.h"

LoginDlg::LoginDlg(QMainWindow *parent):QDialog(parent)
{
    SET_FONT
    setWindowTitle(tr("SCIDµ«¬º"));
    
    //…Ë÷√±≥æ∞Õº∆¨
    QPalette pal = palette();
    pal.setBrush(QPalette::Window , QBrush(QPixmap("./images/login_back2.png")));
    setPalette(pal);

    m_pUserCnter = USERCENTER::instance();
    setFixedSize(QSize(600, 400));
	CreateWidget();
	connect(loginBtn_, SIGNAL(clicked()), this, SLOT(Login()));
	connect(exitBtn_, SIGNAL(clicked()), this, SLOT(Exit()));
}

LoginDlg::~LoginDlg()
{

}

void LoginDlg::CreateWidget()
{
	loginNameLabel_ = new QLabel(this);
    loginNameLabel_->setText(tr("µ«¬º√˚≥∆"));
	loginPwdLabel_ = new QLabel(this);
    loginPwdLabel_->setText(tr("µ«¬º√‹¬Î"));
	loginNameEdit_ = new QLineEdit(this);
    loginNameEdit_->setMaximumSize(QSize(200, 30));
	loginPwdEdit_ = new QLineEdit(this);
    loginPwdEdit_->setMaximumSize(QSize(200, 30));
    loginPwdEdit_->setEchoMode(QLineEdit::Password);

	QHBoxLayout *layoutName = new QHBoxLayout();
	layoutName->addWidget(loginNameLabel_);
	layoutName->addWidget(loginNameEdit_);
	layoutName->setContentsMargins(60, 0, 60, 0);
    layoutName->setSpacing(10);

	QHBoxLayout *layoutPwd = new QHBoxLayout();
	layoutPwd->addWidget(loginPwdLabel_);
	layoutPwd->addWidget(loginPwdEdit_);
    layoutPwd->setContentsMargins(60, 0, 60, 0);
    layoutPwd->setSpacing(10);

	loginBtn_ = new QPushButton(this);
    loginBtn_->setText(tr("µ«¬º"));
    loginBtn_->setMaximumSize(QSize(80, 40));
	exitBtn_ = new QPushButton(this);
    exitBtn_->setText(tr("ÕÀ≥ˆ"));
    exitBtn_->setMaximumSize(QSize(80, 40));

	QHBoxLayout *btnLayout = new QHBoxLayout();
	btnLayout->addWidget(loginBtn_);
	btnLayout->addWidget(exitBtn_);
    btnLayout->setContentsMargins(50, 5, 50, 5);
    btnLayout->setSpacing(20);

	QVBoxLayout *mainlayout = new QVBoxLayout();
    mainlayout->setContentsMargins(100, 100, 100, 100);
    mainlayout->setSpacing(20);
    mainlayout->addStretch();
	mainlayout->addLayout(layoutName);
	mainlayout->addLayout(layoutPwd);
	mainlayout->addLayout(btnLayout);

    setLayout(mainlayout);
}

bool LoginDlg::Verify()
{
    m_strUserName = loginNameEdit_->text();
    QString strpassword = loginPwdEdit_->text();
	return m_pUserCnter->Verify(m_strUserName, strpassword);
}

void LoginDlg::GetUser(INS_USER &user)
{
    user = m_pUserCnter->m_user_map[m_strUserName];
}
// SLOT ============================================
void LoginDlg::Login()
{
	if (Verify())
	{
		//—È÷§≥…π¶
		emit accept();
	}
}

void LoginDlg::Exit()
{
    emit reject();
}