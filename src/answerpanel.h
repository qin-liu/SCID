#ifndef _ANSWERPANEL_H_
#define _ANSWERPANEL_H_

class SelectionWdiget;

class  AnswerPanel : public QWidget
{
	Q_OBJECT
public:
	explicit AnswerPanel(QMainWindow* parent = NULL);

	void CreateWidget();
	void RetranslateStrings();
	void DisplayNothing();
	void DiplayQuestion(INS_QUESTION& question, int answeringIndex);
	QString GetNextQuestion();
	
	
	INS_QUESTION answeringQues_;
	int answeingIndex_;
private:
	
	QGroupBox *answerPanelGroup_;
	QLabel *idLabel_;
	QTextBrowser *quesText_;
	QStackedWidget *answerStackView_;
	QGroupBox *groupDescribe_;
	QTextEdit *describeText_;
	QGroupBox *groupSelection_;
	QRadioButton *sel0Radio_;
	QRadioButton *sel1Radio_;
	QRadioButton *sel2Radio_;
	QRadioButton *sel3Radio_;

	QPushButton  *returnBackBtn_;
	QPushButton  *commitBtn_;

	QVBoxLayout *mainLayout;
	QVBoxLayout *groupLayout_;
	QHBoxLayout *layoutBottom_;

    SelectionWdiget *selWidget_;
private slots:
	void CommitAnswer();
signals:
	void SendAnswerToParentSignal(INS_ANSWER answer);

private:
    void ChangeSelectWidgt(QString quesID);  //遇到特殊选择，改变选项内容
};
#endif