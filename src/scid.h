#ifndef SCID_H
#define SCID_H

#include <QtGui/QMainWindow>
#include "ui_scid.h"
#include "AnswerCenter.h"


class AnswersTableView;
class AnswerTableModel;
class AnswerPanel;

class SCID : public QMainWindow
{
	Q_OBJECT

public:
	SCID(QWidget *parent = 0, Qt::WFlags flags = 0);
	~SCID();

private:
	Ui::SCIDClass ui;

private:
	void CreateActions();
	void CreateMenu();
	void CreateShotCuts(); 
	void CreateToolBar();
    void CreateStatusBar();
	void ReTranslateStrings();
	void setToolBarIconSize();
	void CreateAnswersTableView();

private:
	QTabWidget *centerWidget_;
	QHBoxLayout *centerLayout_;
	
	QMenu *sysMenu_;
    QMenu *setMenu_;
	QMenu *exitMenu_;
	QMenu *helpMenu_;


	QAction *userManageAct_;
	QAction *exitAct_;
	QAction *helpDocAct_;
	QAction *aboutAct_;

	QToolBar *mainToolbar_;
	QAction *goTestAct_;	     //��ʼ�µĲ���
	QAction *loadTestAct_;	     //���ز���
	QAction *changUserAct_;		 //�л��û�
	QAction *quesManageAct_;	 //�������
    QAction *diagnoseManageAct_;
	QAction *answersExportAct_;  //�𰸵���
	QAction *returnToAct_;       //���ص��˴δ���
    QAction *jumpModeAct_;       //��ת����
    QAction *fontColorAct_;

    QStatusBar *statusBar_;
    QLabel *user_status_labela_;

	QTableWidget *answerTableWidget_;

	QSplitter *splitter_;
	AnswerTableModel *answersTableModel_;
	
	AnswerPanel* answerPanel_;
	
private slots:
	void ShowQuestionManageDlg();
    void DiagnoseManage();
	void StartTest();
    void DisplayAnswerList(int nSaveIndex);
	void LoadTest();
	void CommitAnswer(INS_ANSWER answer);
	void ReturnBack();
	void DBClickToShowAnswer(const QModelIndex& index);
    void ClickUserManage();
    void ClickReturnTo();
    void UserManage();
    void SetJumpMode();
    void GetDiagnosisMatchList(DIAGNOSIS_VEC &diag_vec);
    void GetLGroupDiagnoseList(DIAGNOSIS_VEC &diag_vec);
    int  GetSel3Count(ANSWER_VECTOR &vec, QString strStartQuesId, int nQuesCount);
    bool ExportAnswerToExcel();
    bool ExportDiagnosis(YExcel::BasicExcelWorksheet* pSheet, int nCol);
    void FontSet();
    void About();
    void help();
    void CloseApp();
public:
    void InitSCID();
    void SetLoginUser(INS_USER &user);
private:
	void ReturnBackTo(int nAnwserIndex);
    void WriteSettings();
    void ReadSettings();
private:
    QSettings *m_setting;
    QString m_answerPanelFont;        //��������
    int     m_answerPanelFontSize;    //���������С

    bool m_bAutoJump;
	int  m_nAnsweringIndex; //�ش�����
	int  m_nSaveIndex;
	bool m_bStartTest;
	DataCenter *m_pData;
	AnswerCenter* m_pAnCenter;
    ANSWER_VECTOR m_answer_vec;
    INS_USER m_user;
};

class JumpNextQuesitonDlg: public QDialog
{
    Q_OBJECT
public:
    JumpNextQuesitonDlg(QString text);
    virtual ~JumpNextQuesitonDlg();

    bool GetNextQeustion(INS_QUESTION &nextQues);
private:
    QLabel *nextQuesLabel_;
    QComboBox *quesIdCombo_;
    QPushButton *OkBtn_;
    QPushButton *cancelBtn_;

    INS_QUESTION m_nextQues;
    DataCenter* m_pDataCenter;
    QString m_text;
private slots:
    void ClickOk();
    void ClickCancel();
};
#endif // SCID_H
