/********************************************************************************
** Form generated from reading UI file 'registerserver.ui'
**
** Created: Sat Apr 13 17:35:28 2013
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERSERVER_H
#define UI_REGISTERSERVER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterServerClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menuBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *RegisterServerClass)
    {
        if (RegisterServerClass->objectName().isEmpty())
            RegisterServerClass->setObjectName(QString::fromUtf8("RegisterServerClass"));
        RegisterServerClass->resize(593, 318);
        centralWidget = new QWidget(RegisterServerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 50, 81, 41));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(200, 50, 271, 31));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(200, 110, 271, 31));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(90, 100, 81, 41));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 200, 121, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(320, 200, 121, 41));
        RegisterServerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(RegisterServerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 593, 19));
        RegisterServerClass->setMenuBar(menuBar);
        statusBar = new QStatusBar(RegisterServerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        RegisterServerClass->setStatusBar(statusBar);

        retranslateUi(RegisterServerClass);

        QMetaObject::connectSlotsByName(RegisterServerClass);
    } // setupUi

    void retranslateUi(QMainWindow *RegisterServerClass)
    {
        RegisterServerClass->setWindowTitle(QApplication::translate("RegisterServerClass", "RegisterServer", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RegisterServerClass", "\345\272\217\345\210\227\345\217\267", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RegisterServerClass", "\346\263\250\345\206\214\347\240\201", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("RegisterServerClass", "\351\200\200\345\207\272", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("RegisterServerClass", "\350\216\267\345\217\226\346\263\250\345\206\214\347\240\201", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RegisterServerClass: public Ui_RegisterServerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERSERVER_H
