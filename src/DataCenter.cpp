#include "stdafx.h"
#include "DataCenter.h"
#include "SqlHelper.h"
#include "AnswerCenter.h"
#include "StatisticJumpFunction.h"

DataCenter::DataCenter()
{
	    InitSTAFucMap(); //inist statistic function
}	

DataCenter::~DataCenter()
{
	
}

void DataCenter::SetSqlHelper(SqlHelper *pHelper)
{
	m_pSqlHelper = pHelper;
}


bool DataCenter::LoadFromDB()
{
	//����groupe
	do 
	{
		if (! m_pSqlHelper->get_group_map(m_groupMap))
		{
			break;
		}
		if (! m_pSqlHelper->get_question_list(m_question_map))
		{
			break;
		}

        QList<INS_CONDITION> condition_list;
        if (! m_pSqlHelper->get_jump_condition_list(condition_list))
        {
            break;
        }
        else
        {
             InsertConditionListToMap(condition_list);
        }

        QList<INS_DIAGNOSIS> diagnosis_list;
        if (! m_pSqlHelper->get_diagnosis_list(m_diagnosis_vec))
        {
            break;
        }
		return true;
	} while (false);
	m_groupMap.clear();
	m_question_map.clear();
    return false;
}


bool DataCenter::LoadFromExcel(QString &sExcelPathName)
{
	if (! ClearData())
	{
		return false;
	}

	YExcel::BasicExcel excel;
	if (! excel.Load(sExcelPathName.toAscii().constData()))
	{
		return false;
	}

	YExcel::BasicExcelWorksheet* pSheet1 = excel.GetWorksheet("Sheet1");
	if (pSheet1 == NULL)
	{
		return false;
	}
	YExcel::BasicExcelWorksheet* pSheet2 = excel.GetWorksheet("Sheet2");
	if (pSheet2 == NULL)
	{
		return false;
	}
	YExcel::BasicExcelWorksheet* pSheet3 = excel.GetWorksheet("Sheet3");
	if (pSheet3 == NULL)
	{
		return false;
	}
    YExcel::BasicExcelWorksheet* pSheet4 =  excel.GetWorksheet("Sheet4");
    if (pSheet4 == NULL)
    {
        return false;
    }

	if (! LoadSheet1(pSheet1))
	{
		return false;
	}
	if (! LoadSheet2(pSheet2))
	{
		return false;
	}
	if (! LoadSheet3(pSheet3))
	{
		return false;
	}
    if (! LoadSheet4(pSheet4))
    {
        return false;
    }
	SaveToDB();
	return true;
}

bool DataCenter::SaveToDB()
{
	GROUP_MAP::iterator it_group = m_groupMap.begin();
	for (; it_group != m_groupMap.end(); ++it_group)
	{
		m_pSqlHelper->add_groupe(it_group.value());
		
	}

	QUESTION_MAP::iterator it_question = m_question_map.begin();
	for (; it_question != m_question_map.end(); ++it_question)
	{
		m_pSqlHelper->add_question(it_question.value());
	}
    
    QUES_CONDITONMAP_MAP::iterator it_vec_vec = m_conditionmap_map.begin();
    for(; it_vec_vec != m_conditionmap_map.end(); ++it_vec_vec)
    {
        CONDITION_VEC_VEC::iterator it_vec = it_vec_vec->begin();
        for (; it_vec != it_vec_vec->end(); ++it_vec)
        {
            CONDITION_VEC::iterator it_condition = it_vec->begin();
            for (; it_condition != it_vec->end(); ++it_condition)
            {
                m_pSqlHelper->add_jump_condition(*it_condition);
            }
        }
    }

    DIAGNOSIS_VEC::iterator it_dia = m_diagnosis_vec.begin();
    for (; it_dia != m_diagnosis_vec.end(); ++it_dia)
    {
        m_pSqlHelper->add_diagnosis(*it_dia);
    }
	return true;
}

bool DataCenter::ClearData()
{
	m_groupMap.clear();
	m_question_map.clear();
	m_conditionmap_map.clear();
	return m_pSqlHelper->ClearAllData();
}

bool DataCenter::LoadSheet1(YExcel::BasicExcelWorksheet *pSheet1)
{
	if (! pSheet1)
	{
		return false;
	}
	//��ȡGroup �� Question����
	//��ȡSheet1, sContent=�����ڵ�ֵ ID = (Group=����ĸ + ulorderid=��ţ���A������Z��))
	int nRow_Sheet1 = pSheet1->GetTotalRows();
	int nCol_Sheet1 = pSheet1->GetTotalCols();

	//�ȶ��� �ٶ���
	unsigned long ulorderid = 0;
	for (int i=0; i<nCol_Sheet1; ++i)
	{
		//�õ�����
		QString strGroupName = GetExcelColumnCharName(i);
		if (strGroupName.isNull())
		{
			continue;
		}

		int j = 0;
		for (; j<nRow_Sheet1; ++j)
		{
			YExcel::BasicExcelCell* pCell =  pSheet1->Cell(j, i);
			if (pCell != NULL)
			{
				QString strCell = QString::fromWCharArray(pCell->GetWString());
				if(! strCell.isNull())
				{
					INS_QUESTION question;
					question.sID = strGroupName + QString::number(j+1); //����+����
					question.sContent = strCell;
					m_question_map.insert(TransStrToIntID(question.sID), question);
				}
				else
				{
					break; //�հ��У�����һ��
				}
			}
		}

        if(j != 0)
        {
            INS_QUESTION_GROUP group;
            group.sName = strGroupName;
            group.ulQuestionCount = j; //��������
            m_groupMap.insert(group.sName, group);
        }
	}
	return true;
}

bool DataCenter::LoadSheet2(YExcel::BasicExcelWorksheet *pSheet2)
{
	if(! pSheet2)
		return false;

	//��ȡSheet2������
	//����˵����orderid	type���������ͣ�jump0��ѡ���ת��	jump1��ѡ��1��ת��	jump2��ѡ��2��ת��	jump3��ѡ��3��ת��	valid0��ѡ���Ч��	valid1��ѡ��1��Ч��	valid2��ѡ��2��Ч��	valid3��ѡ��3��Ч��	other_condition��������ת��

	int nRow_Sheet2 = pSheet2->GetTotalRows();
	int nCol_Sheet2 = pSheet2->GetTotalCols();

	if (nCol_Sheet2 < 10)
	{
		return false;
	}
	
	for (int r=0; r<nRow_Sheet2; ++r)
	{
		QString sQuesID; 

		YExcel::BasicExcelCell* pCell =  pSheet2->Cell(r, 0);
		if (pCell != NULL)
		{
			char sID[8] = {0};
			if (pCell->Get(sID))
			{
				sQuesID = sID;
			}
			else
			{
				continue; //û��ID����������
			}
		}

		QUESTION_MAP::iterator it = m_question_map.find(TransStrToIntID(sQuesID));
		if (it == m_question_map.end())
		{
			continue;  //û�д�ID��question
		}

		pCell =  pSheet2->Cell(r, 1);
		if (pCell != NULL)
		{
			int nType = 2;
			if (pCell->Get(nType))
			{
				it.value().nType = nType;
			}
		}
		pCell =  pSheet2->Cell(r, 2);
		if (pCell != NULL)
		{
			char sID[8] = {0};
			if (pCell->Get(sID))
			{
				it.value().sJump0 = sID;
			}
		}
		pCell =  pSheet2->Cell(r, 3);
		if (pCell != NULL)
		{
			char sID[8] = {0};
			if (pCell->Get(sID))
			{
				it.value().sJump1 = sID;
			}
		}
		pCell =  pSheet2->Cell(r, 4);
		if (pCell != NULL)
		{
			char sID[8] = {0};
			if (pCell->Get(sID))
			{
				it.value().sJump2 = sID;
			}
		}
		pCell =  pSheet2->Cell(r, 5);
		if (pCell != NULL)
		{
			char sID[8] = {0};
			if (pCell->Get(sID))
			{
				it.value().sJump3 = sID;
			}
		}
		pCell =  pSheet2->Cell(r, 6);
		if (pCell != NULL)
		{
			int nValid0 = 0;
			if (pCell->Get(nValid0))
			{
				it.value().nValid0 = nValid0? 1:0;
			}
		}
		pCell =  pSheet2->Cell(r, 7);
		if (pCell != NULL)
		{
			int nValid1 = 0;
			if (pCell->Get(nValid1))
			{
				it.value().nValid1 = nValid1? 1:0;
			}
		}
		pCell =  pSheet2->Cell(r, 8);
		if (pCell != NULL)
		{
			int nValid2 = 0;
			if (pCell->Get(nValid2))
			{
				it.value().nValid2 = nValid2? 1:0;
			}
		}
		pCell =  pSheet2->Cell(r, 9);
		if (pCell != NULL)
		{
			int nValid3 = 0;
			if (pCell->Get(nValid3))
			{
				it.value().nValid3 = nValid3? 1:0;
			}
		}
	}
	return true;
}

bool DataCenter::LoadSheet3(YExcel::BasicExcelWorksheet *pSheet3)
{
    if (! pSheet3)
        return false;

    int nRow_Sheet3 = pSheet3->GetTotalRows();
    int nCol_Sheet3 = pSheet3->GetTotalCols();
    if (nCol_Sheet3 < 7)
    {
        //��������
        return false;
    }

    for (int r=0; r<nRow_Sheet3; ++r)
    {
        QString sQuesID; 

        YExcel::BasicExcelCell* pCell =  pSheet3->Cell(r, 0);
        if (pCell != NULL)
        {
            char sID[8] = {0};
            if (pCell->Get(sID))
            {
                sQuesID = sID;
            }
            else
            {
                continue; //û��ID����������
            }
        }

        QUESTION_MAP::iterator it = m_question_map.find(TransStrToIntID(sQuesID));
        if (it == m_question_map.end())
        {
            continue;  //û�д�ID��question
        }

        INS_CONDITION condition;
        condition.sQuestionid = sQuesID;

        pCell =  pSheet3->Cell(r, 1);
        if (pCell != NULL)
        {
            int nSel = 0;
            if (pCell->Get(nSel))
            {
                condition.selection = nSel;
            }
        }
        pCell =  pSheet3->Cell(r, 2);
        if (pCell != NULL)
        {
            char sID[8] = {0};
            if (pCell->Get(sID))
            {
                condition.sCondtionQuestionid = sID;
            }
        }
        pCell =  pSheet3->Cell(r, 3);
        if (pCell != NULL)
        {
            int nJunmWhenS0 = 0;
            if (pCell->Get(nJunmWhenS0))
            {
                condition.bJumpSelect0 = nJunmWhenS0;
            }
        }
        pCell =  pSheet3->Cell(r, 4);
        if (pCell != NULL)
        {
            int nJunmWhenS1 = 0;
            if (pCell->Get(nJunmWhenS1))
            {
                condition.bJumpSelect1 = nJunmWhenS1;
            }
        }
        pCell =  pSheet3->Cell(r, 5);
        if (pCell != NULL)
        {
            int nJunmWhenS2 = 0;
            if (pCell->Get(nJunmWhenS2))
            {
                condition.bJumpSelect2 = nJunmWhenS2;
            }
        }
        pCell =  pSheet3->Cell(r, 6);
        if (pCell != NULL)
        {
            int nJunmWhenS3 = 0;
            if (pCell->Get(nJunmWhenS3))
            {
                condition.bJumpSelect3 = nJunmWhenS3;
            }
        }
        
        InsertCondition(condition);
    }//end for
	return true;
}

bool DataCenter::LoadSheet4(YExcel::BasicExcelWorksheet *pSheet4)
{
    if (! pSheet4)
        return false;

    int nRow_Sheet4 = pSheet4->GetTotalRows();
    int nCol_Sheet4 = pSheet4->GetTotalCols();
    if (nCol_Sheet4 < 3)
    {
        //��������
        return false;
    }

    //���
    m_diagnosis_vec.clear();

    for (int i=0; i<nRow_Sheet4; ++i)
    {
        //������ID
        QString sQuesID;
        YExcel::BasicExcelCell* pCell =  pSheet4->Cell(i, 0);
        if (pCell != NULL)
        {
            char sID[8] = {0};
            if (pCell->Get(sID))
            {
                sQuesID = sID;  
                QUESTION_MAP::iterator it = m_question_map.find(TransStrToIntID(sQuesID));
                if (it == m_question_map.end())
                {
                    continue; //û�д�ID����������
                }
            }
            else
            {
                continue; //û��ID����������
            }
        }


        //��
        QString sKey;
        pCell =  pSheet4->Cell(i, 1);
        if (pCell != NULL)
        {
            int nType = pCell->Type();
            if (YExcel::BasicExcelCell::INT == nType || YExcel::BasicExcelCell::eDOUBLE == nType)
            {
                int nAnswer = -1;
                pCell->Get(nAnswer);
                sKey = QString::number(nAnswer);
            }
            else if (YExcel::BasicExcelCell::eSTRING == nType)
            {
                char *temp = const_cast<char*>(pCell->GetString()); 
                if (temp)
                {
                    sKey = QString::fromAscii(temp);
                }
            }
            else
            {
                wchar_t *temp = const_cast<wchar_t*>(pCell->GetWString());
                if (temp)
                {
                   sKey = QString::fromWCharArray(temp);
                }
            }                     
        }

        //���
        QString sDiagnosis;
        pCell =  pSheet4->Cell(i, 2);
        if (pCell != NULL)
        {
            sDiagnosis = QString::fromWCharArray(pCell->GetWString());
        }
        else
        {
            continue;
        }

        INS_DIAGNOSIS diagnosis;
        diagnosis.sQuestionid = sQuesID;
        diagnosis.sKeyContent = sKey;
        diagnosis.sDiagnosis = sDiagnosis;
        m_diagnosis_vec.push_back(diagnosis);
    }
    return true;
}

QString DataCenter::GetExcelColumnCharName(int nColum)
{
	if (nColum >= 0 && nColum <= 25)
	{
		char name(65+nColum);
		return QString(name);
	}
	return QString();
}

int DataCenter::GetNextQuestionByJumpCondition(QString& strQuesId, QString& strAnswer, AnswerCenter *pAncenter, int nSaveIndex, INS_QUESTION& nextQuestion/*out*/)
{
    if (strQuesId.isNull())
    {
        //��һ��
        nextQuestion = m_question_map.begin().value();
        return 1;
    }

	QUESTION_MAP::iterator it = m_question_map.find(TransStrToIntID(strQuesId));
	if (it == m_question_map.end())
	{
		//δ�ҵ���ID
		return -1;
	}

    QUESTION_MAP::iterator it_next = it + 1;
    if (it_next == m_question_map.end())
    {
        //�������һ��
        return 0;
    }

    QString strNextQuesId;

    //�������ת
    if(it->nType == QTYPE_DESCRIBE)
    {
        if (! it->sJump0.isEmpty())
        {
            strNextQuesId = it->sJump0;
        }
    }
    else
    {
        int nSelection = TranAnswerToSelection(strAnswer);
        if (nSelection != -1)
        {
            if (IsMatchCondition(*it, nSelection, pAncenter, nSaveIndex))
            {
                //����ĳ����ת��������ת
                switch(nSelection)
                {
                case 0:
                    strNextQuesId = it->sJump0;
                    break;
                case 1:
                    strNextQuesId = it->sJump1;
                    break;
                case 2:
                    strNextQuesId = it->sJump2;
                    break;
                case 3:
                    strNextQuesId = it->sJump3;   
                    break;
                }
            }
        }
    }

    if (strNextQuesId.isEmpty())
    {
        //û��Ҫ��ת�����⣬�������һ��
        strNextQuesId = it_next->sID;
    }

    //�ж���ת�Ƿ���Ч
    QUESTION_MAP::iterator it_find = m_question_map.find(TransStrToIntID(strNextQuesId));
    if (it_find == m_question_map.end())
    {
        //δ�ҵ���ת������ţ��������һ��
        strNextQuesId = it_next->sID;
    }

	nextQuestion = m_question_map[TransStrToIntID(strNextQuesId)];
	return 1; //�ҵ���һ��
}

void DataCenter::InsertCondition(INS_CONDITION &condition)
{
    QUES_CONDITONMAP_MAP::iterator it_quesId = m_conditionmap_map.find(condition.sQuestionid);
    if ( it_quesId != m_conditionmap_map.end())
    {
        //�ҵ�quesId
  
        if (condition.selection >= 0 || condition.selection <= 3)
        {
            it_quesId->value(condition.selection).push_back(condition);
        }
    }
    else
    {
        //������quesId�Ĺ�����
        CONDITION_VEC_VEC vec_vec;
        for (int i=0; i<4; ++i)
        {
            CONDITION_VEC vec;
            if (condition.selection == i)
            {
                //����condition
                vec.push_back(condition);
            }

            vec_vec.push_back(vec);
        }

        m_conditionmap_map.insert(condition.sQuestionid, vec_vec);
    }
}

bool DataCenter::IsMatchCondition(INS_QUESTION &question, int nSelection, AnswerCenter *pAncenter, int nSaveIndex) //�Ƿ������ת����
{
    QUES_CONDITONMAP_MAP::iterator it_conditon_map = m_conditionmap_map.find(question.sID);
    if (it_conditon_map == m_conditionmap_map.end())
    {
        //û��������������
        return true;
    }
    
    if (it_conditon_map->value(nSelection).empty())
    {
        //�б�Ϊ�գ�û��������������
        return true;
    }

    //����������Ŀѡ��
    bool bJump = false;

    CONDITION_VEC vec = it_conditon_map->value(nSelection);
    CONDITION_VEC::iterator it_conditon = vec.begin();

    for (; it_conditon !=  vec.end(); ++it_conditon)
    {
        QString strAnswer;
        if (pAncenter->QueryAnswerOfQuestion(nSaveIndex, it_conditon->sCondtionQuestionid, strAnswer))
        {
            if ((strAnswer == "?") && it_conditon->bJumpSelect0)
            {
                //ѡ���ʺ�
                return true;
            }
            else if ((strAnswer == "1") && it_conditon->bJumpSelect1)
            {
                //ѡ��1
                return true;
            }
            else if ((strAnswer == "2") && it_conditon->bJumpSelect2)
            {
                //ѡ��2
                return true;
            }
            else if ((strAnswer == "3") && it_conditon->bJumpSelect3)
            {
                //ѡ��3
                return true;
            }
        }
    }

    if (it_conditon ==  vec.end())
    {
        //������ת������������
        return false;
    }

    return true;
}

int DataCenter::TranAnswerToSelection(QString &strAnswer)
{
    if (strAnswer == "?")
    {
        return 0;
    }
    else if (strAnswer == "1")
    {
        return 1;
    }
    else if (strAnswer == "2")
    {
        return 2;
    }
    else if (strAnswer == "3")
    {
        return 3;
    }
    else
    {
        return -1;
    }
}

void DataCenter::InsertConditionListToMap(QList<INS_CONDITION> condition_list)
{
    QList<INS_CONDITION>::iterator it = condition_list.begin();
    for (; it != condition_list.end(); ++it)
    {
        InsertCondition(*it);
    }
}
   
bool DataCenter::SaveQuestion(INS_QUESTION &ques)
{
    return m_pSqlHelper->update_question(ques);
}

int DataCenter::GetStatisticsJump(QString& strQuesId, AnswerCenter *pAncenter, int nSaveIndex, INS_ANSWER &answer, INS_QUESTION& question/*out*/) //�ж�ͳ�������ת
{
    QString strAnswer;
    if (! GetStaticAnswer(strQuesId, pAncenter, nSaveIndex, strAnswer))
    {
        //δ�õ�ͳ�����
        return 0; //0 ��ʾ����������
    }

    QUESTION_MAP::iterator it = m_question_map.find(TransStrToIntID(strQuesId));
    if (it == m_question_map.end())
    {
        //δ�ҵ���ID
        return 0;
    }

    INS_ANSWER ins_answer;
    ins_answer.sAnswer = strAnswer;
    ins_answer.sQuestionid = strQuesId;

    //���ݴ��ж���ת
    QString jumpQuesID;
    if (strAnswer == "?")
    {
        jumpQuesID = it->sJump0;
    }
    else if (strAnswer == "1")
    {
        jumpQuesID = it->sJump1;
    }
    else if (strAnswer == "2")
    {
        jumpQuesID = it->sJump2;
    }
    else if(strAnswer == "3")
    {
        jumpQuesID = it->sJump3;
    }
    else
    {
        return 0;
    }
    
    QUESTION_MAP::iterator it_ret = m_question_map.find(TransStrToIntID(jumpQuesID));
    if (it_ret == m_question_map.end())
    {
        //��һ��
        question = *(++it);
    }
    else
    {
        //��ת��
        question = *it_ret;
    }
    answer = ins_answer;
    return 1;
}

bool DataCenter::addDiagnose(INS_DIAGNOSIS& diagnose)
{
    if (m_pSqlHelper->add_diagnosis(diagnose))
    {
        m_diagnosis_vec.push_back(diagnose);
        return true;
    }
    return false;
}