#include "registerserver.h"
#include <QMessageBox>

QMap<char, int> m_InversekeyMap;
QMap<int, char> m_keyMap;  //数字和字母的映射表

RegisterServer::RegisterServer(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
    InitKeyMap();
    InitInverseKeyMap();
    ui.setupUi(this);
    //设置背景图片

//     QPalette pal = palette();
//     pal.setBrush(QPalette::Window , QBrush(QPixmap(":/RegisterServer/back.png")));
//     setPalette(pal);
//    setStyleSheet("background: url(:/RegisterServer/back.png)");
//    ui.label->setStyleSheet("background-color: rgb(0, 0, 0)");
    connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(DisplayRegister()));
    connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(Exit()));
}

RegisterServer::~RegisterServer()
{

}

void RegisterServer::InitInverseKeyMap()
{
    m_InversekeyMap['W'] = 0;
    m_InversekeyMap['D'] = 1;
    m_InversekeyMap['J'] = 2;
    m_InversekeyMap['A'] = 3;
    m_InversekeyMap['P'] = 4;
    m_InversekeyMap['C'] = 5;
    m_InversekeyMap['K'] = 6;
    m_InversekeyMap['V'] = 7;
    m_InversekeyMap['B'] = 8;
    m_InversekeyMap['M'] = 9;
}

void RegisterServer::InitKeyMap()
{
    m_keyMap[0] = 'W';
    m_keyMap[1] = 'D';
    m_keyMap[2] = 'J';
    m_keyMap[3] = 'A';
    m_keyMap[4] = 'P';
    m_keyMap[5] = 'C';
    m_keyMap[6] = 'K';
    m_keyMap[7] = 'V';
    m_keyMap[8] = 'B';
    m_keyMap[9] = 'M';

}
QString RegisterServer::GenerateRegisterStr(QString strSerial)
{
    strSerial.remove('-');

    unsigned int nSerial = GetMappingInt(strSerial);
    nSerial  = Encryption(nSerial);
    return TransToRegString(nSerial);
}

unsigned int RegisterServer::GetMappingInt(QString serial)
{
    QString encryptionStr;
    for (int i=0; i<serial.length(); ++i)
    {
        char s = serial.at(i).toAscii();
        int n = m_InversekeyMap[s];
        encryptionStr.push_back(QString::number(n));
    }
    return encryptionStr.toUInt();
}

unsigned int RegisterServer::Encryption(unsigned int serialNum)
{
    return serialNum ^= 0x12345678; //本机c盘序列号简单运算

}
QString RegisterServer::TransToRegString(unsigned int encryptionNum)
{
    QString registerStr;
    QString temp = QString::number(encryptionNum);

    for (int i=0; i<temp.length(); ++i)
    {
        QString str = temp.at(i);
        char regChar = m_keyMap[str.toUInt()];
        registerStr.append(regChar);
    }

    return registerStr;
}

bool RegisterServer::DisplayRegister()
{
    if (ui.lineEdit->text().isEmpty())
    {
        QMessageBox::warning(this, "注册码", "序列号不能为空");
        return false;
    }

    QString strSerial = ui.lineEdit->text();
    QString strRegister = GenerateRegisterStr(strSerial);
    

    QString temp;
    for (int i=0; i<strRegister.length(); ++i)
    {
        temp.push_back(strRegister.at(i));
        if (i%4 == 3)
        {
            temp.push_back('-');
        }
    }

    ui.lineEdit_2->setText(temp);
    return true;
}

void RegisterServer::Exit()
{
    close();
}