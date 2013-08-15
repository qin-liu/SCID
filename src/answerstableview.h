#ifndef _ANSWERSTABLEVIEW_H_
#define _ANSWERSTABLEVIEW_H_

#include <QTableView>
#include <QSplitter>

class AnswersTableView : public QTableView
{
	Q_OBJECT
public:
	AnswersTableView(QWidget * parent = 0);
	
	void InitSize();
private:
	
};
#endif
