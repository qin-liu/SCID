#include "stdafx.h"
#include "Register.h"
#include <QMessageBox>

extern bool g_register;
const QString DECRYPT_FILE_NAME = "data"; 

Register::Register()
{
    widget();

    InitKeyMap();
    InitInverseKeyMap();
    
    connect(m_registerBtn, SIGNAL(clicked()), this, SLOT(InputRegisterVerify()));
    connect(m_cancelBtn, SIGNAL(clicked()), this, SLOT(Cancel()));
}

void Register::widget()
{
    m_serialNumEdit = new QLineEdit(this);
    m_serialNumEdit->setReadOnly(true);
    m_serialNumEdit->setMinimumHeight(30);
    m_registerNumEdit = new QLineEdit(this); 
    m_registerNumEdit->setObjectName("registerNumEdit");
    m_registerNumEdit->setMinimumHeight(30);
    m_serialNumLabel = new QLabel(this);
    m_serialNumLabel->setText("���к�");
    m_registerNumLabel = new QLabel(this);
    m_registerNumLabel->setText("ע����");

    QHBoxLayout *serialLayout = new QHBoxLayout();
    serialLayout->setContentsMargins(10, 0, 10, 0);
    serialLayout->addWidget(m_serialNumLabel);
    serialLayout->addWidget(m_serialNumEdit);
    QHBoxLayout *registerLayout = new QHBoxLayout();
    registerLayout->setContentsMargins(10, 0, 10, 0);
    registerLayout->addWidget(m_registerNumLabel);
    registerLayout->addWidget(m_registerNumEdit);
    m_registerBtn = new QPushButton(this);
    m_registerBtn->setText("ע��");
    m_cancelBtn = new QPushButton(this);
    m_cancelBtn->setText("ȡ��");

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->setSpacing(10);
    btnLayout->addWidget(m_cancelBtn);
    btnLayout->addWidget(m_registerBtn);


    //center layout
    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->setContentsMargins(10, 0, 10, 0);
    mainLayout->addLayout(serialLayout);
    mainLayout->addLayout(registerLayout);
    mainLayout->addLayout(btnLayout);

    setLayout(mainLayout);
    setFixedSize(230, 130);
    hide();
}

void Register::InitInverseKeyMap()
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

void Register::InitKeyMap()
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

Register::~Register()
{

}

bool Register::Verify()
{
    unsigned int disk_serial = GetCDriverSerial();
    QString strSerial = TransToRegString(disk_serial);
    
    QString temp;
    for (int i=0; i<strSerial.length(); ++i)
    {
        temp.push_back(strSerial.at(i));
        if (i%4 == 3)
        {
            //add '-'
            temp.push_back('-');
        }
    }
    m_serialNumEdit->setText(temp);

    unsigned int encryput_ret = Encryption(disk_serial);
    QString regStr = TransToRegString(encryput_ret);

    if (QFile::exists(DECRYPT_FILE_NAME))
    {
        //����ע���ļ�����򿪺�ȥ��֤���
        QFile dataFile(DECRYPT_FILE_NAME);
        dataFile.open(QIODevice::ReadOnly | QIODevice::Text);
        QString decript_str = dataFile.readLine();
        if (regStr == decript_str)
        {
            return true;
        }
        QMessageBox::information(this, "SCIDע��", "��Чע���룬������ע�����");
    }
    QMessageBox::information(this, "SCIDע��", "�������ע����ע�᷽��ʹ��");
    show();
    return false; 
}

int Register::ShowRegisterDlg()
{
    return exec();
}

unsigned int Register::GetCDriverSerial()
{
    //��ȡӲ�����кţ�����ֻ����Ӳ�����кţ���ͨ��
    DWORD VolumeSerialNumber = 0;
    if (! GetVolumeInformation(L"c:\\", NULL, 12, &VolumeSerialNumber, NULL, NULL, NULL, 10))
    {
        QMessageBox::warning(this, "����", "�޷���ȡC�����к�,��������Ƿ����C��");
        return 0;
    }
    m_serial = VolumeSerialNumber;
    return VolumeSerialNumber;//�����˿ͺ�.������
}

unsigned int Register::Encryption(unsigned int serialNum)
{
    return serialNum ^= 0x12345678; //����c�����кż�����
}

QString Register::TransToRegString(unsigned int encryptionNum)
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

void Register::InputRegisterVerify()
{
    QString strRegister = m_registerNumEdit->text();
    strRegister.remove('-');

    unsigned int disk_serial = GetCDriverSerial();
  
    unsigned int encryput_ret = Encryption(disk_serial);
    QString regStr = TransToRegString(encryput_ret);

    if (regStr == strRegister)
    {
        QFile data("data");
        data.open(QIODevice::WriteOnly);
        data.write(strRegister.toAscii().constData());
        data.close();
        g_register = true;
        hide();
        accept();
    } 
    else
    {
        accept();
    }
}

void Register::Cancel()
{
    reject();
}
