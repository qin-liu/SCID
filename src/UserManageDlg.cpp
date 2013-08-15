#include "stdafx.h"
#include "UserManageDlg.h"

UserManageDlg::UserManageDlg()
{
    SET_FONT

    setWindowTitle(tr("�û�����"));
    m_pUserCenter = USERCENTER::instance();
    CreateToolBar();

	userTable_ = new QTableWidget(this);
    userTable_->setRowCount(0);
    userTable_->setColumnCount(2);
    userTable_->setColumnWidth(0, 130);
    userTable_->setColumnWidth(1, 200);
    userTable_->setFrameStyle(QFrame::Plain);
    userTable_->setEditTriggers(QAbstractItemView::NoEditTriggers);
    userTable_->setSelectionBehavior(QAbstractItemView::SelectRows);
    userTable_->setSelectionMode(QAbstractItemView::SingleSelection);

	QStringList headList;
	headList << "�û���" << "�û���ɫ";
	userTable_->setHorizontalHeaderLabels(headList);

    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(toolBar_);
    layout->addWidget(userTable_);
    setLayout(layout);

    connect(addUserAct_, SIGNAL(triggered()), this, SLOT(AddUser()));
    connect(delUserAct_, SIGNAL(triggered()), this, SLOT(DelUser()));
    connect(editUserAct_, SIGNAL(triggered()), this, SLOT(EditUser()));

    DisplayUsers();
}

UserManageDlg::~UserManageDlg()
{
	
}

void UserManageDlg::CreateToolBar()
{	
	addUserAct_ = new QAction(this);
    addUserAct_->setText(tr("�����û�"));
    addUserAct_->setIcon(QIcon(":/SCID/images/addUser.png"));
	delUserAct_ = new QAction(this);
    delUserAct_->setText(tr("ɾ���û�"));
    delUserAct_->setIcon(QIcon(":/SCID/images/deleteUser.png"));
	editUserAct_ = new QAction(this);
    editUserAct_->setText(tr("�༭�û�"));
    editUserAct_->setIcon(QIcon(":/SCID/images/editUser.png"));

	toolBar_ = new QToolBar(this);
	toolBar_->addAction(addUserAct_);
	toolBar_->addAction(delUserAct_);
	toolBar_->addAction(editUserAct_);
    toolBar_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    toolBar_->widgetForAction(addUserAct_)->setMinimumWidth(40);
    toolBar_->widgetForAction(addUserAct_)->setMinimumHeight(30);
    toolBar_->widgetForAction(delUserAct_)->setMinimumWidth(40);
    toolBar_->widgetForAction(delUserAct_)->setMinimumHeight(30);
    toolBar_->widgetForAction(editUserAct_)->setMinimumWidth(40);
    toolBar_->widgetForAction(editUserAct_)->setMinimumHeight(30);

    toolBar_->setMovable(false);
    toolBar_->setAllowedAreas(Qt::TopToolBarArea);
    toolBar_->setContextMenuPolicy(Qt::DefaultContextMenu);
    toolBar_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
}

void UserManageDlg::DisplayUsers()
{  
    USER_MAP::iterator it = m_pUserCenter->m_user_map.begin();
    for (int nRow = 0; it != m_pUserCenter->m_user_map.end(); ++it, ++nRow)
    {
        userTable_->insertRow(nRow);
        QTableWidgetItem *item1 = new QTableWidgetItem(it->sUserName);
        QString strRole = (it->nRole == 1?"��ͨ�û�":"����Ա");
        QTableWidgetItem *item2 = new QTableWidgetItem(strRole);
        userTable_->setItem(nRow, 0, item1);
        userTable_->setItem(nRow, 1, item2);
    }   
}

void UserManageDlg::AddUser()
{
    int nRole = 1;
    QString strName, strPwd;

    UserAddDlg *addUserDlg = new UserAddDlg();
    int nRet = addUserDlg->exec();
    if (nRet == QDialog::Accepted)
    {
        addUserDlg->GetUserInfo(strName, strPwd, nRole);
        INS_USER newUser;
        newUser.sUserName = strName;
        newUser.sPassword = strPwd;
        newUser.nRole = 1;
        if (! m_pUserCenter->AddUser(newUser))
        {
            QMessageBox::about(NULL, "����û�", "����û�ʧ��");
        }
        else
        {
            QMessageBox::about(NULL, "����û�", "����û��ɹ�");

            //��ʾ
            int nRow = userTable_->rowCount();
            QTableWidgetItem *newItem1 = new QTableWidgetItem(newUser.sUserName);
            QString strRole = (newUser.nRole == 1? "��ͨ�û�":"����Ա");
            QTableWidgetItem *newItem2 = new QTableWidgetItem(strRole);
            userTable_->insertRow(nRow);
            userTable_->setItem(nRow, 0, newItem1);
            userTable_->setItem(nRow, 1, newItem2);
        }
    }
}

void UserManageDlg::DelUser()
{
    int nRow = userTable_->currentRow();
    QTableWidgetItem *item = userTable_->currentItem();
    QString strName = item->text();
    if (strName == "admin")
    {
        QMessageBox::about(this, "ɾ���û�", "����ɾ��admin�û�");
        return;
    }

    QMessageBox::StandardButton ret = QMessageBox::question(this, "ɾ���û�", "�Ƿ�Ҫɾ�����û�", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
    if (ret == QMessageBox::Yes)
    {
        if (m_pUserCenter->DelUser(strName))
        {
            userTable_->removeRow(nRow);
        }
        else
        {
            QMessageBox::about(this, "ɾ���û�", "ɾ�����û�ʧ��");
        }
    } 
}

void UserManageDlg::EditUser()
{
    int nRow = userTable_->currentRow();
    QTableWidgetItem *item1 = userTable_->item(nRow, 0);
    QTableWidgetItem *item2 = userTable_->item(nRow, 1);

    QString strName = item1->text();
    QString strRole = item2->text();
    int nRole = strRole.compare("��ͨ�û�")? 1:0;
    if (strName == "admin")
    {
        QMessageBox::about(this, "�༭�û�", "���ܱ༭admin�û�");
        return;
    }
    
    QString strNewPwd;
    int nNewRoel;
    EditUserDlg *editUserDlg = new EditUserDlg();
    int nRet = editUserDlg->exec();
    if (nRet == QDialog::Accepted)
    {
        editUserDlg->GetNewPassword(strNewPwd, nNewRoel);
        INS_USER newUser;
        newUser.sUserName = strName;
        newUser.sPassword = strNewPwd;
        newUser.nRole = nRole;
        if (! m_pUserCenter->ChangPassword(newUser.sUserName, newUser.sPassword))
        {
            QMessageBox::about(NULL, "�༭�û�", "�༭�û�ʧ��");
            return;
        }
        
        if (nNewRoel != nRole)
        {
            if (! m_pUserCenter->ChangRole(newUser.sUserName, nNewRoel))
            {
                QMessageBox::about(NULL, "�༭�û�", "�༭�û�ʧ��");
            }
        }
     
        QMessageBox::about(NULL, "�༭�û�", "�༭�û��ɹ�");
    }
}


// UserAddDlg ===========================================
UserAddDlg::UserAddDlg()
{
    setFont(QFont("Times New Roman", 12));

    setWindowTitle(tr("����û�"));
    CreateAddUserDlg();
    connect(OkBtn_, SIGNAL(clicked()), this, SLOT(ClickOk()));
    connect(cancelBtn_, SIGNAL(clicked()), this, SLOT(ClickCancel()));

    setFixedSize(QSize(200, 180));
}

UserAddDlg::~UserAddDlg()
{

}

void UserAddDlg::GetUserInfo(QString &strName, QString &strPwd, int &role)
{
    strName = m_strName;
    strPwd = m_strPwd;
    role = roleCombo_->currentIndex();
}

void UserAddDlg::CreateAddUserDlg()
{   
    nameLabel_ = new QLabel(this);
    nameLabel_->setText(tr("�û���"));
    pwdLabel_ = new QLabel(this);
    pwdLabel_->setText(tr("    ����"));
    roleLabel_ = new QLabel(this);
    roleLabel_->setText(tr("    ��ɫ"));

    nameEdit_ = new QLineEdit(this);
    pwdEdit_ = new QLineEdit(this);
    pwdEdit_->setEchoMode(QLineEdit::Password);
    
    roleCombo_ = new QComboBox(this);
    roleCombo_->addItem("����Ա");
    roleCombo_->addItem("��ͨ�û�");

    OkBtn_ = new QPushButton(this);
    OkBtn_->setText(tr("ȷ��"));
    cancelBtn_ = new QPushButton(this);
    cancelBtn_->setText(tr("ȡ��"));

    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->addWidget(nameLabel_);
    nameLayout->addWidget(nameEdit_);
    nameLayout->setContentsMargins(10, 5, 10, 0);
    QHBoxLayout *pwdLayout = new QHBoxLayout();
    pwdLayout->addWidget(pwdLabel_);
    pwdLayout->addWidget(pwdEdit_);
    pwdLayout->setContentsMargins(10, 0, 10, 0);
    QHBoxLayout *roleLayout = new QHBoxLayout();
    roleLayout->addWidget(roleLabel_);
    roleLayout->addWidget(roleCombo_);
    roleLayout->setContentsMargins(10, 0, 10, 0);

    
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(OkBtn_);
    btnLayout->addWidget(cancelBtn_);
    btnLayout->setContentsMargins(50, 0, 50, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(nameLayout);
    mainLayout->addLayout(pwdLayout);
    mainLayout->addLayout(roleLayout);
    mainLayout->addLayout(btnLayout);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    setLayout(mainLayout);
}

void UserAddDlg::ClickOk()
{
    m_strName = nameEdit_->text();
    m_strPwd = pwdEdit_->text();
    emit accept();
}

void UserAddDlg::ClickCancel()
{
    emit reject();
}

// EditUserDlg============================================================
EditUserDlg::EditUserDlg()
{
    newPwdLabel_ = new QLabel(this);
    newPwdLabel_->setText(tr("�������µ�����: "));
    newPwdEdit_ = new QLineEdit(this);
    newPwdEdit_->setEchoMode(QLineEdit::Password);
    QHBoxLayout *layout = new QHBoxLayout();
    layout->addWidget(newPwdLabel_);
    layout->addWidget(newPwdEdit_);
    layout->setContentsMargins(0, 5, 0, 0);
    roleCombo_ = new QComboBox(this);
    roleCombo_->addItem("����Ա");
    roleCombo_->addItem("��ͨ�û�");

    OkBtn_ = new QPushButton(this);
    OkBtn_->setText(tr("ȷ��"));
    cancelBtn_ = new QPushButton(this);
     cancelBtn_->setText(tr("ȡ��"));
    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addWidget(OkBtn_);
    btnLayout->addWidget(cancelBtn_);
    btnLayout->setContentsMargins(50, 0, 50, 0);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(layout);
    mainLayout->addWidget(roleCombo_);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);

    connect(OkBtn_, SIGNAL(clicked()), this, SLOT(ClickOk()));
    connect(cancelBtn_, SIGNAL(clicked()), this, SLOT(ClickCancel()));
}   

EditUserDlg::~EditUserDlg()
{

}

void EditUserDlg::InitUser(INS_USER &user)
{
    roleCombo_->setCurrentIndex(user.nRole);
}

void EditUserDlg::GetNewPassword(QString &strNewPassword, int &role)
{
    strNewPassword = m_strNewPwd;
    role = m_nRole;
}

void EditUserDlg::ClickOk()
{
    m_nRole = roleCombo_->currentIndex();
    m_strNewPwd = newPwdEdit_->text();
    if (m_strNewPwd.isEmpty())
    {
        QMessageBox::about(this, "��������", "��������벻��Ϊ��");
        return;
    }
    emit accept();
}

void EditUserDlg::ClickCancel()
{
    emit reject();
}

