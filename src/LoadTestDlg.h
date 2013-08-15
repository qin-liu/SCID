#ifndef _LOADTEST_H_
#define _LOADTEST_H_

class LoadTestDlg: public QDialog
{
    Q_OBJECT
public:
    LoadTestDlg(QWidget* parent, AnswerCenter *pAnCenter, QString& strUserName, int nAmsweringSaveIndex);
    ~LoadTestDlg();
    
    int GetAnswerSaveIndex();
private:
    void CreateWidget();
    void LoadTestList();
    QSize SizeHint();
    QTableWidget *testTable_;
    QPushButton  *loadBtn_;
    QPushButton  *exitBtn_;
    QPushButton  *delBtn_;
private slots:
    void ClickLoad();
    void Exit();
    void ClickDel();
private:
    QString m_strUserName;
    int m_nSaveIndex;
    int m_nAmsweringSaveIndex;
    AnswerCenter *m_pAncenter;
};
#endif