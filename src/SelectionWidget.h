#ifndef _SELECTION_WIDGET_H_
#define _SELECTION_WIDGET_H_


class SelectionWdiget : public QWidget
{
public:
    SelectionWdiget();
    SelectionWdiget(int nSelCount, QStringList strSelNameList);
    virtual ~SelectionWdiget();

    void ChangeSelectModel(int nSelCount, QStringList strSelNameList, int nValid0 = 1, int nValid1 = 1, int nValid2 = 1, int nValid3 = 1);
    QString GetSelAnswer();
    void SetAnswer(int nSelected);
private:
    void clear();

    int m_nSelCount;
    QStringList m_strSelNameList;
    QVector<QRadioButton*> m_radioBtnVec;
    QHBoxLayout *layout_;
};
#endif