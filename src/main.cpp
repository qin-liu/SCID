#include "stdafx.h"
#include "scid.h"
#include <QtGui/QApplication>
#include "loginDlg.h"
#include "Register.h"

bool g_register = false;

int main(int argc, char *argv[])
{
    //�����ַ���
    QTextCodec *codec = QTextCodec::codecForName("System");    //��ȡϵͳ����
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    
	//��ʼ��
	QString strDBName = "scid.db";
	SQLHELPER::instance()->init_db(strDBName);
	DATACENTER::instance()->SetSqlHelper(SQLHELPER::instance());
	DATACENTER::instance()->LoadFromDB();
	ANCENTER::instance()->SetSqlHelper(SQLHELPER::instance());
    ANCENTER::instance()->LoadFromDB();
    USERCENTER::instance()->SetSqlHelper(SQLHELPER::instance());
    USERCENTER::instance()->LoadFromDB();

    QApplication a(argc, argv);
    a.setApplicationName("SCID");
    a.setOrganizationDomain("SCID");

    //��ʽ��
    QFile qss("scid.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());

    bool bExit = false;

    //����Ƿ�ע��
    Register reg;
    if (! reg.Verify())
    {
        while (1)
        {
            int ret = reg.ShowRegisterDlg();
            if (ret == QDialog::Accepted)
            {
                if (g_register)
                {
                    QMessageBox::about(&reg, "SCIDע��", "ע��ɹ�");
                    break;
                }
                QMessageBox::about(&reg, "SCIDע��", "ע��ʧ�ܣ��������ṩ����ȡע���롣");
            }
            else if (ret == QDialog::Rejected)
            {
                //�˳�
                bExit = true;
                break;
            }
        }
    }
    
    if (! bExit)
    {
        //��¼
        SCID mainWindow;
        LoginDlg *loginDlg = new LoginDlg(&mainWindow);
        int nLogin = loginDlg->exec();

        do 
        {
            if (nLogin != QDialog::Accepted)
            {
                break;
            }
            INS_USER loginUser;
            loginDlg->GetUser(loginUser);
            mainWindow.showMaximized();
            mainWindow.SetLoginUser(loginUser);
            a.exec();
        } while (false);
    }
 
    //�ͷ��ڴ�
    USERCENTER::cleanup();
    ANCENTER::cleanup();
    DATACENTER::cleanup();
    SQLHELPER::cleanup();
	return 0;
}
