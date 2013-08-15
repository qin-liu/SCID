#ifndef _USER_MANAGE_H_
#define _USER_MANAGE_H_

class UserManageDlg: public QDialog
{
	Q_OBJECT
public:
	UserManageDlg();
	virtual ~UserManageDlg();

private:
	void CreateToolBar();
    void DisplayUsers();

	QTableWidget *userTable_;
	QToolBar *toolBar_;
	QAction *addUserAct_;
	QAction *delUserAct_;
	QAction *editUserAct_;

    UserCenter *m_pUserCenter;
private slots:
    void AddUser();
    void DelUser();
    void EditUser();
};

class UserAddDlg : public QDialog
{
   Q_OBJECT
public:
   UserAddDlg();
   ~UserAddDlg();
    
   void GetUserInfo(QString &strName, QString &strPwd, int &role);
private:
   void CreateAddUserDlg();

   QLabel *nameLabel_;
   QLabel *pwdLabel_;
   QLabel *roleLabel_;
   QLineEdit *nameEdit_;
   QLineEdit *pwdEdit_;
   QComboBox *roleCombo_;
   QPushButton *OkBtn_;
   QPushButton *cancelBtn_;

   QString m_strName;
   QString m_strPwd;
private slots:
    void ClickOk();
    void ClickCancel();
};

class EditUserDlg: public QDialog
{
	Q_OBJECT
public:
	EditUserDlg();
	virtual ~EditUserDlg();
    
    void InitUser(INS_USER &user);
    void GetNewPassword(QString &strNewPassword, int &role);
private:
    QLabel *newPwdLabel_;
    QLineEdit *newPwdEdit_;
    QComboBox *roleCombo_;
    QPushButton *OkBtn_;
    QPushButton *cancelBtn_;

    int m_nRole;
    QString m_strNewPwd;
private slots:
    void ClickOk();
    void ClickCancel();
};
#endif