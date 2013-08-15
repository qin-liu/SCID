#include "stdafx.h"
#include "answerstableview.h"

AnswersTableView::AnswersTableView(QWidget * parent /* = 0 */):
	QTableView(parent)
{
	setObjectName("AnswersTableView");
	setWindowTitle("AnswersTableView");
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setFrameStyle(QFrame::Box);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setSelectionBehavior(QAbstractItemView::SelectRows);
	setSelectionMode(QAbstractItemView::SingleSelection);
	

}

void AnswersTableView::InitSize()
{
	setColumnWidth(0, 50);
	setColumnWidth(1, 60);
	setColumnWidth(2, 300);
}
