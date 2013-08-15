#ifndef _STARTTESTDLG_H_
#define _STARTTESTDLG_H_

class StartTestDlg : public QDialog
{
public:
	StartTestDlg();
	virtual ~StartTestDlg();

	void CreateWidget();
	void ReTranslateString();

private:
	QPushButton *newTestbtn_;
	QPushButton *loadTestbtn_;

private slots:
	void NewTest();
	void LoadTest();
};

#endif