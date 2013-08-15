#pragma once
#include <QDialog>

class DiagnoseMangeDlg : public QDialog
{
    Q_OBJECT
public:
    DiagnoseMangeDlg(QWidget *parent = NULL);
    ~DiagnoseMangeDlg(void);
    
    void addDiagnoseItem(QString& strQuesID, QString& strKey, QString& strContent);
private slots:
    void AddDiagnose();
    void DelDiagnose();
private:
    void LoadDiagnose();
    
    QTableWidget *diagnoseTable_;
    QPushButton *addBtn_;
    QPushButton *delBtn_;
};

class AddDiagnoseDlg : public QDialog
{
    Q_OBJECT
public:
    AddDiagnoseDlg(DiagnoseMangeDlg *parent = NULL);
    ~AddDiagnoseDlg();

private:
    DiagnoseMangeDlg *manageDlg;
    QLabel *quesIDLabel_;
    QLineEdit *quesIDEdit_;
    QLabel *contentLabel_;
    QLineEdit *contentEdit_;
    QLabel *keyLabel_;
    QLineEdit *keyEdit_;
    QPushButton *okBtn_;
    QPushButton *cancelBtn_;
    QString strQuesID;
    QString strKey;
    QString strContent;

private slots:
    void Ok();
    void Cancel();

};
