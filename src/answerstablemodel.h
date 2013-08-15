#ifndef _ANSWERTABLEMODEL_H_
#define _ANSWERTABLEMODEL_H_

class AnswerTableModel : public QStandardItemModel
{
public:
	explicit  AnswerTableModel(/*QVector<ANSWER_ITEM>& answerList, */QObject *parent = 0);

	void SetAnswerList( QVector<INS_ANSWER> &answerList );
	void AddAnswer(INS_ANSWER& answer);
	void InitColumnHeader();

	//getters
	Qt::ItemFlags flags( const QModelIndex& index ) const { return QAbstractItemModel::flags( index ); }
	int rowCount( const QModelIndex& parent = QModelIndex() ) const;
	int columnCount( const QModelIndex& parent = QModelIndex() ) const;
	QVariant data( const QModelIndex& index, int role ) const;
	QVariant headerData( int section, Qt::Orientation orientation, int role = Qt::DisplayRole ) const;

	// Setters

	bool setData( const QModelIndex &index, const QVariant& value, int role = Qt::EditRole );
	bool insertRows( int rows, int nCount, const QModelIndex& index = QModelIndex());
	bool addFields( QStringList aFields );
	bool removeRows( int position, int rows, const QModelIndex& index = QModelIndex() );
private:
	QVector<INS_ANSWER> answerList_;
	QStringList columnNameStringList_;
};

#endif