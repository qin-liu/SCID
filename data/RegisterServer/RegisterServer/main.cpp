#include "registerserver.h"
#include <QtGui/QApplication>
#include <QTextCodec>
int main(int argc, char *argv[])
{
    //�����ַ���
    QTextCodec *codec = QTextCodec::codecForName("System");    //��ȡϵͳ����
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);

    QApplication a(argc, argv);
    RegisterServer w;
    w.show();
    w.setWindowTitle("SCIDע���");
    return a.exec();
}
