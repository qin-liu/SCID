#include "stdafx.h"
#include "scid.h"
#include <QtGui/QApplication>
#include "loginDlg.h"
#include "Register.h"

bool g_register = false;

int main(int argc, char *argv[])
{
    //设置字符集
    QTextCodec *codec = QTextCodec::codecForName("System");    //获取系统编码
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    
	//初始化
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

    //样式表
    QFile qss("scid.qss");
    qss.open(QFile::ReadOnly);
    qApp->setStyleSheet(qss.readAll());

    bool bExit = false;

    //检测是否注册
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
                    QMessageBox::about(&reg, "SCID注册", "注册成功");
                    break;
                }
                QMessageBox::about(&reg, "SCID注册", "注册失败，请从软件提供方获取注册码。");
            }
            else if (ret == QDialog::Rejected)
            {
                //退出
                bExit = true;
                break;
            }
        }
    }
    
    if (! bExit)
    {
        //登录
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
 
    //释放内存
    USERCENTER::cleanup();
    ANCENTER::cleanup();
    DATACENTER::cleanup();
    SQLHELPER::cleanup();
	return 0;
}
