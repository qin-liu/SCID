#ifndef _QESTIONSMANAGEDLG_H_
#define _QESTIONSMANAGEDLG_H_
class DataCenter;
class SCID;
class QuestionsManageDlg : public QDialog
{
	Q_OBJECT
public:
	explicit QuestionsManageDlg(SCID *parent = 0);

private:
	void CreateWidget();
	void CreateAction();
	void ReTranslateStrings();
private:
	QVBoxLayout *mainLayout_;

	//������ť
	QGroupBox *oprBtnGroup_;
	QPushButton *AddQuesBtn_;
	QPushButton *delQuesBtn_;
	QPushButton *importBnt_;
	QPushButton *exportBnt_;

	//�������б���
	QTreeWidget* quesTree_;
	
	//�������ź�����
	QLabel *quesIdTitle_;
	QTextBrowser *quesIdText_;
	QLabel *quesTypeTitle_;
	QComboBox *quesType_;
	
	//ѡ������
	QGroupBox *selectionGroup_;
	QLabel * sel0Title_;
	QLabel * sel1Title_;
	QLabel * sel2Title_;
	QLabel * sel3Title_;
	QTextEdit *sel0Jump_;
	QTextEdit *sel1Jump_;
	QTextEdit *sel2Jump_;
	QTextEdit *sel3Jump_;
	QCheckBox *sel0Check_;
	QCheckBox *sel1Check_;
	QCheckBox *sel2Check_;
	QCheckBox *sel3Check_;
	
	//����
	QGroupBox *quesContentGroup_;
	QTextEdit *quesContent_;
    QPushButton *editContentBnt_;

	//��ת����
	QGroupBox *jumpGroup_;
	QTableWidget *jumpTable_;
	QPushButton *addJumpBtn_;
	QPushButton *delJumpBtn_;

    //���水ť
    QPushButton *saveBtn_;
    QPushButton *cancelBtn_;

private:
	virtual void showEvent ( QShowEvent * event );
    bool ExportSheet1(YExcel::BasicExcelWorksheet *pSheet1);
private slots:
	void Import();
    void Export();
	void DisplayQuesTree();
	void ShowSelectQuesItem(QTreeWidgetItem* item, int column);
    void ClickSave();
    void ClickCancel();
    void AddCondition();
    void DelCondition();
    void ClickEditContent();
signals:
	void LoadTreeSignal();

private:
	DataCenter* m_pData;
    SCID *m_scid;
};
#endif