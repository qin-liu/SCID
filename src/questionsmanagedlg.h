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

	//操作按钮
	QGroupBox *oprBtnGroup_;
	QPushButton *AddQuesBtn_;
	QPushButton *delQuesBtn_;
	QPushButton *importBnt_;
	QPushButton *exportBnt_;

	//测试题列表树
	QTreeWidget* quesTree_;
	
	//测试题编号和类型
	QLabel *quesIdTitle_;
	QTextBrowser *quesIdText_;
	QLabel *quesTypeTitle_;
	QComboBox *quesType_;
	
	//选项设置
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
	
	//内容
	QGroupBox *quesContentGroup_;
	QTextEdit *quesContent_;
    QPushButton *editContentBnt_;

	//跳转设置
	QGroupBox *jumpGroup_;
	QTableWidget *jumpTable_;
	QPushButton *addJumpBtn_;
	QPushButton *delJumpBtn_;

    //保存按钮
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