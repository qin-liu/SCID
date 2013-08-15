#ifndef REGISTERSERVER_H
#define REGISTERSERVER_H

#include <QtGui/QMainWindow>
#include "ui_registerserver.h"

class RegisterServer : public QMainWindow
{
    Q_OBJECT

public:
    RegisterServer(QWidget *parent = 0, Qt::WFlags flags = 0);
    ~RegisterServer();

private:
    void InitKeyMap();
    void InitInverseKeyMap();
    
    unsigned int Encryption(unsigned int serialNum);
    QString GenerateRegisterStr(QString strSerial);
    QString TransToRegString(unsigned int encryptionNum);
    unsigned int GetMappingInt(QString serial);
    Ui::RegisterServerClass ui;

private slots:
    bool DisplayRegister();
    void Exit();
};

#endif // REGISTERSERVER_H
