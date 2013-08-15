#ifndef _REGISTER_H_
#define _REGISTER_H_



class Register : public QDialog
{
    Q_OBJECT;

public:
    Register();
    virtual ~Register();
    
    int ShowRegisterDlg();
    bool Verify();
private:
    void widget();
    unsigned int GetCDriverSerial();
    unsigned int Encryption(unsigned int serialNum);
    QString TransToRegString(unsigned int encryptionNum);
    void InitKeyMap();
    void InitInverseKeyMap();
    

private:
    QLineEdit *m_serialNumEdit;
    QLineEdit *m_registerNumEdit;
    QLabel *m_serialNumLabel;
    QLabel *m_registerNumLabel;
    QPushButton *m_registerBtn;
    QPushButton *m_cancelBtn;

    QMap<int, char> m_keyMap;  //数字和字母的映射表
    QMap<char, int> m_InversekeyMap;
    unsigned int m_serial;

private slots:
    void InputRegisterVerify();
    void Cancel();
    
};
#endif