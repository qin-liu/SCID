#include "stdafx.h"
#include "EditContentDlg.h"
#include <QTextCursor>
#include <QTextCharFormat>

EditContentDlg::EditContentDlg(QString htmlContent, QDialog *parent):QDialog(parent)
{
    bBold_ = false;
    bItalics_ = false;
    bUnderline_ = false;
    CreateToolBar();

    textEdit_ = new QTextEdit(this);
    textEdit_->setAcceptRichText(true);
    textEdit_->setFontPointSize(14);

    okBtn_ = new QPushButton(this);
    okBtn_->setText("����");
    cancelBtn_ = new QPushButton(this);
    cancelBtn_->setText("ȡ��");

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(toolBar_);
    mainLayout->addWidget(textEdit_);

    QHBoxLayout *btnLayout = new QHBoxLayout();
    btnLayout->addStretch();
    btnLayout->addWidget(okBtn_);
    btnLayout->addWidget(cancelBtn_);

    mainLayout->addLayout(btnLayout);
    textEdit_->clear();
    textEdit_->setHtml(htmlContent);
    setLayout(mainLayout);
    

    connect(textEdit_, SIGNAL(currentCharFormatChanged(const QTextCharFormat&)), this, SLOT(slotCurrentFormatChanged(const QTextCharFormat&)));
    connect(sizeCombo_, SIGNAL(currentIndexChanged(QString )), this, SLOT(slotSetFontPointSize(QString )));
    connect(okBtn_, SIGNAL(clicked()), this, SLOT(ClickSave()));
    connect(cancelBtn_, SIGNAL(clicked()), this, SLOT(ClickCancel()));
    setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint | Qt::WindowMinimizeButtonHint);
}

EditContentDlg::~EditContentDlg()
{
    
}

void EditContentDlg::CreateToolBar()
{
    toolBar_ = new QToolBar(this);

    //�����С
    sizeCombo_ = new QComboBox(toolBar_);
    sizeCombo_->setToolTip("�����С");
    for (int i=1; i<=20; ++i)
    {
        sizeCombo_->addItem(QString::number(i), i);
    }

    //����Ӵ�
    setBoldAct_ = new QAction(this);
    setBoldAct_->setIcon(QIcon("./images/bold.png"));
    setBoldAct_->setToolTip("����");
    //б��
    setItalicsAct_ = new QAction(this);
    setItalicsAct_->setIcon(QIcon("./images/Italic.png"));
    setItalicsAct_->setToolTip("б��");
    //������ɫ
    setCorlorAct_ = new QAction(this);
    setCorlorAct_->setIcon(QIcon("./images/fontColor.png"));
    //�»���
    setUnderline_ = new QAction(this);
    setUnderline_->setIcon(QIcon("./images/underline.png"));

    toolBar_->addWidget(sizeCombo_);
    toolBar_->addAction(setBoldAct_);
    toolBar_->addAction(setItalicsAct_);
    toolBar_->addAction(setUnderline_);
    toolBar_->addAction(setCorlorAct_);

    connect(setBoldAct_, SIGNAL(triggered()), this, SLOT(ClickSetBold()));
    connect(setItalicsAct_, SIGNAL(triggered()), this, SLOT(ClickSetItalics()));
    connect(setUnderline_, SIGNAL(triggered()), this, SLOT(ClickSetUnderline()));
    connect(setCorlorAct_, SIGNAL(triggered()), this, SLOT(ClickSetFontCorlor()));
}


void EditContentDlg::ClickSetBold()
{
    QTextCharFormat format;
    if (bBold_)
    {
        format.setFontWeight(QFont::Normal);
        bBold_ = false;
    }
    else
    {
        format.setFontWeight(QFont::Bold);
        bBold_ = true;
    }
    MergeFormat(format);
}

void EditContentDlg::ClickSetItalics()
{
    QTextCharFormat format;
    if (bItalics_)
    {
        format.setFontItalic(false);
        bItalics_ = false;
    }
    else
    {
        bItalics_ = true;
        format.setFontItalic(true);
    }
    MergeFormat(format);
}


void EditContentDlg::ClickSetUnderline()
{
    QTextCharFormat fmt;

    if (bUnderline_)
    {
        fmt.setFontUnderline(false);
        bUnderline_ = false;
    }
    else
    {
        fmt.setFontUnderline(true);
        bUnderline_ = true;
    }

    MergeFormat(fmt);
}

void EditContentDlg::ClickSetFontCorlor()
{
    QColor color = QColorDialog::getColor (Qt::red,this);    
    if(color.isValid())
    {
        QTextCharFormat fmt;
        fmt.setForeground(color);    
        MergeFormat(fmt);
    }
}


void EditContentDlg::MergeFormat(QTextCharFormat format)
{
    QTextCursor cursor = textEdit_->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    textEdit_->mergeCurrentCharFormat(format);
}

void EditContentDlg::slotCurrentFormatChanged(const QTextCharFormat &fmt)
{
    if (fmt.font().bold())
    {
        setBoldAct_->setIcon(QIcon("./images/boldSet.png"));
        bBold_ = true;
    }
    else
    {
        setBoldAct_->setIcon(QIcon("./images/bold.png"));
        bBold_ = false;
    }
    
    if (fmt.fontItalic())
    {
        setItalicsAct_->setIcon(QIcon("./images/ItalicSet.png"));
        bItalics_ = true;
    }
    else
    {
        setItalicsAct_->setIcon(QIcon("./images/Italic.png"));
        bItalics_ = false;
    }

    if (fmt.fontUnderline())
    {
        setUnderline_->setIcon(QIcon("./images/underlineSet.png"));
        bItalics_ = true;
    }
    else
    {
        setUnderline_->setIcon(QIcon("./images/underline.png"));
        bItalics_ = false;
    }

    sizeCombo_->setCurrentIndex(sizeCombo_->findText(QString::number(fmt.fontPointSize())));

//     underBtn->setChecked(fmt.fontUnderline());
}

void EditContentDlg::slotSetFontPointSize(QString size)
{
    QTextCharFormat fmt;
    fmt.setFontPointSize(size.toFloat()); 
    MergeFormat(fmt);
}

void EditContentDlg::ClickSave()
{
    htmlContent_ = textEdit_->toHtml();
    emit accept();
}

void EditContentDlg::ClickCancel()
{
    emit reject();
}

QString EditContentDlg::GetEditHTMLContent()
{
    return htmlContent_;
}