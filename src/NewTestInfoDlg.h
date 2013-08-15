#ifndef _NEWTESTINFODLG_H_
#define _NEWTESTINFODLG_H_

class  NewTestInfoDlg: public QDialog
{
	Q_OBJECT
public:
	NewTestInfoDlg();
	virtual ~NewTestInfoDlg();

	void GetNewTestInfo(QString &strTestName, QString &strTesterName, QString &strAnswerName);

private slots:
	void ClickOk();
	void ClickCancel();

private:
	void CreateWidget();
    void CreateWidget2();

	QLabel *testNameLabel_;
	QLabel *testerNameLabel_;
	QLabel *answerNameLabel_;

	QLineEdit *testNameEdit_;
	QLineEdit *testerNameEdit_;
	QLineEdit *answerNameEdit_;

	QPushButton *okBtn_;
	QPushButton *cancelBtn_;

	QString m_strTestName;
	QString m_strTesterName;
	QString m_strAnswerName;


    //===================ªÒ»°±‡¬Î∞Ê±æ
    QLabel *areaLabel_;
    QLabel *testerLabel_;
    QLabel *groupLabel_;
    QLabel *answerLabel_;

    QComboBox *areaBox_;
    QComboBox *testerBox_;
    QComboBox *groupBox_;
    QComboBox *answerBox_;

    QString m_strTestCode;
};
#endif