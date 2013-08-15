#include "stdafx.h"
#include "SelectionWidget.h"

SelectionWdiget::SelectionWdiget()
{
    m_nSelCount = 4;
    m_strSelNameList<<"? 资料不足"<<"1 无或否"<<"2 阈下"<<"3 阈上或是";
    layout_ = new QHBoxLayout();
    layout_->setSpacing(30);
    for (int i=0; i<m_nSelCount; ++i)
    {
        QRadioButton *radio = new QRadioButton(m_strSelNameList.at(i), this);
        m_radioBtnVec.push_back(radio);
        layout_->addWidget(radio);
        if (i == 1)
        {
            radio->setChecked(true);
        }
        else
        {
            radio->setChecked(false);
        }
    }
    setLayout(layout_);
    QFont f = font();
    f.setPointSize(15);
    setFont(f);
}

SelectionWdiget::SelectionWdiget(int nSelCount, QStringList strSelNameList):m_nSelCount(nSelCount),m_strSelNameList(strSelNameList)
{
    layout_ = new QHBoxLayout();
    layout_->setSpacing(30);
    for (int i=0; i<m_nSelCount; ++i)
    {
        QRadioButton *radio = new QRadioButton(m_strSelNameList.at(i), this);
        m_radioBtnVec.push_back(radio);
        layout_->addWidget(radio);
        if (i=0)
        {
            radio->setChecked(true);
        }
        else
        {
            radio->setChecked(false);
        }
    }
    setLayout(layout_);
}

SelectionWdiget::~SelectionWdiget()
{

}

QString SelectionWdiget::GetSelAnswer()
{
    for (int i=0; i<m_nSelCount; ++i)
    {
        if (m_radioBtnVec[i]->isChecked())
        {
            if (m_nSelCount == 4)
            {
                QString strRet;
                switch(i)
                {
                    case 0:
                        strRet = "?";
                        break;
                    case 1:
                        strRet = "1";
                        break;
                    case 2:
                        strRet = "2";
                        break;
                    case 3:
                        strRet = "3";
                        break;
                    default:
                        strRet = "?";
                }
                return strRet;
            }
            else
            {
                return m_strSelNameList[i].at(0);
            }
        }
    }
    return "";
}
 
void SelectionWdiget::ChangeSelectModel(int nSelCount, QStringList strSelNameList, int nValid0, int nValid1, int nValid2, int nValid3)
{
    clear();
    m_nSelCount = nSelCount;
    m_strSelNameList = strSelNameList;
    int nDefaultSel = 0;
    
    //如果首选项是"?"，设置默认选项为"1"
    QString str1 = strSelNameList.first();
    if (str1.at(0) == '?')
    {
        nDefaultSel = 1;
    }

    for (int i=0; i<m_nSelCount; ++i)
    {
        bool bValid = true;

        switch(i)
        {
        case 0:
            if (nValid0 == 0)
            {
                bValid = false;
            }
            break;
        case 1:
            if (nValid1 == 0)
            {
                bValid = false;
            }
            break;
        case 2:
            if (nValid2 == 0)
            {
                bValid = false;
            }
            break;
        case 3:
            if (nValid3 == 0)
            {
                bValid = false;
            }
            break;
        }


        QRadioButton *radio = new QRadioButton(m_strSelNameList.at(i), this);
        m_radioBtnVec.push_back(radio);
        layout_->addWidget(radio);

        if (i == nDefaultSel)
        {
            radio->setChecked(true);
        }
        else
        {
            radio->setChecked(false);
        }

        if(bValid == 0)
        {
            radio->setEnabled(false); 
        }
    }//end for

    setLayout(layout_);
}

void SelectionWdiget::SetAnswer(int nSelected)
{
    for (int i=0; i<m_nSelCount; ++i)
    {
        m_radioBtnVec[i]->setChecked(false);
    }
    m_radioBtnVec[nSelected]->setChecked(true);
}

void SelectionWdiget::clear()
{
   for (int i=0; i<m_nSelCount; ++i)
   {
       delete m_radioBtnVec[i];
       m_radioBtnVec[i] = NULL;
   }

   m_radioBtnVec.clear();
}
