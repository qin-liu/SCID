#ifndef _LOGINDLG_H_
#define _LOGINDLG_H_

class LoginDlg: public QDialog
{
    Q_OBJECT
public:
	LoginDlg(QMainWindow *parent);
	virtual ~LoginDlg();

    void GetUser(INS_USER &user);
private:
	void CreateWidget();
	bool Verify();
  
	QLabel *loginNameLabel_;
	QLabel *loginPwdLabel_;
	QLineEdit *loginNameEdit_;
	QLineEdit *loginPwdEdit_;

	QPushButton *loginBtn_;
	QPushButton *exitBtn_;
    QString m_strUserName;
private slots:
	void Login();
	void Exit();

private:
    UserCenter* m_pUserCnter;
};
#endif