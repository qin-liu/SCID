#include "stdAfx.h"
#include "answerstablemodel.h"
#include <QStandardItemModel>

AnswerTableModel::AnswerTableModel(/*QVector<ANSWER_ITEM>& answerList, */QObject *parent):
	QStandardItemModel(parent)
{
	columnNameStringList_ << "ÐòºÅ" << "ÌâºÅ" << "´ð°¸";
}

void AnswerTableModel::InitColumnHeader()
{
	setColumnCount(2);
	setHeaderData(0,  Qt::Horizontal, "²âÊÔÌâ", Qt::DisplayRole);
	setHeaderData(1,  Qt::Horizontal, "´ð°¸", Qt::DisplayRole);
}

void AnswerTableModel::SetAnswerList( QVector<INS_ANSWER>& answerList )
{
	beginResetModel();
	answerList_ = answerList; 
	endResetModel();
} 

void AnswerTableModel::AddAnswer(INS_ANSWER& answer)
{
	beginResetModel();
	answerList_.push_back(answer);
	endResetModel();
}

int AnswerTableModel::rowCount( const QModelIndex& parent ) const
{
	return answerList_.count();
}

int AnswerTableModel::columnCount( const QModelIndex& parent ) const
{
	return 3;
}

QVariant AnswerTableModel::data( const QModelIndex& index, int role ) const
{
	if (! index.isValid() 
		|| index.row() > answerList_.count() 
		|| index.column() > columnNameStringList_.count() 
		|| role != Qt::EditRole)
	{
		return QVariant();
	}
	
	switch(role)
	{
	case Qt::EditRole:
		{
			if (index.column() == 0)
			{
				return QVariant(answerList_[index.row()-1].nIndex);
			}
			else if (index.column() == 1)
			{
				return QVariant(answerList_[index.row()-1].sQuestionid);
			}
			else if (index.column() == 2)
			{
				return QVariant(answerList_[index.row()-1].sAnswer);
			}
		}
	case Qt::DisplayRole:
		{
			return QVariant(columnNameStringList_.at(index.column()));
		}
	default:
		return QVariant();
	}
}

QVariant AnswerTableModel::headerData( int section, Qt::Orientation orientation, int role) const
{
	switch( role )
	{
	case Qt::DisplayRole:
		if( orientation == Qt::Horizontal )
			return columnNameStringList_.at(section);
		else // Vortical
		{
			if( section < rowCount() )
				return answerList_[section].nIndex + 1;
			else 
				return QVariant();
		}	
	default:
		return QVariant();
	}
}

bool AnswerTableModel::setData( const QModelIndex &index, const QVariant& value, int role)
{
	if( !index.isValid())
		return false;
	if( value == data( index, role ) )
		return false;

	switch( role )
	{
	case Qt::DisplayRole:
		{
			columnNameStringList_[index.column()] = value.toString();
			break;
		}
	case Qt::EditRole:
		{
			if (index.column() == 0)
			{
				answerList_[index.row()-1].nIndex = value.toInt();
			}
			else if (index.column() == 1)
			{
				answerList_[index.row()-1].sQuestionid = value.toString();
			}
			else if (index.column() == 2)
			{
				answerList_[index.row()-1].sAnswer = value.toString();
			}
			break;
		}
	default:
		return false;
	}
	emit dataChanged( index, index );
	return true;
}

bool AnswerTableModel::insertRows( int rows, int nCount, const QModelIndex& index )
{
	if( !index.isValid() )
		return false;
	beginInsertRows( QModelIndex(), rows, rows + nCount - 1 );
	endInsertRows();
	return true;
}

bool AnswerTableModel::addFields( QStringList aFields )
{
	beginInsertColumns( QModelIndex(), columnCount(), columnCount() + aFields.size() - 1 );
	columnNameStringList_.append(aFields);
	endInsertColumns();
	return true;
}

bool AnswerTableModel::removeRows( int position, int counts, const QModelIndex& index )
{
	if( !index.isValid() )
		return false;
	beginRemoveRows( QModelIndex(), position, position + counts - 1 );
	for (int i=position; i < position+counts; ++i)
	{
		answerList_.erase(answerList_.begin() + i);
	}
	endRemoveRows();
	return true;
}