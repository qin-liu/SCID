// ���ݱ༭����

#ifndef _EDIT_CONTENT_H_
#define _EDIT_CONTENT_H_

class EditContentDlg : public QDialog
{
    Q_OBJECT
public:
    EditContentDlg(QString htmlContent = QString(), QDialog *parent = NULL);
    virtual ~EditContentDlg();
    
    QString GetEditHTMLContent();
private:
    void CreateToolBar();
    void MergeFormat(QTextCharFormat fomat);
    

    QToolBar *toolBar_;
    QTextEdit *textEdit_;
    QPushButton *okBtn_;
    QPushButton *cancelBtn_;

    //�༭����
    QComboBox *sizeCombo_;
    QAction *setItalicsAct_;
    QAction *setCorlorAct_;
    QAction *setBoldAct_;
    QAction *setUnderline_;
    //������
    bool bBold_;
    bool bItalics_;
    bool bUnderline_;

    QString htmlContent_;
private slots:
    void ClickSetBold();
    void ClickSetItalics();
    void ClickSetUnderline();
    void ClickSetFontCorlor();
    void ClickSave();
    void ClickCancel();
    void slotCurrentFormatChanged(const QTextCharFormat &fmt);
    void slotSetFontPointSize(QString size);
    
};
#endif  //_EDIT_CONTENT_H_