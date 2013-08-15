#include "stdafx.h"
#include "AnswerCenter.h"

AnswerCenter::AnswerCenter()
{
	m_pSqlHelper = NULL;
}

AnswerCenter::~AnswerCenter()
{

}
void AnswerCenter::SetSqlHelper(SqlHelper *pHelper)
{
	m_pSqlHelper = pHelper;
}

bool AnswerCenter::LoadFromDB()
{
	if (!m_pSqlHelper)
		return false;

	QList<INS_ANSWER_SAVEINFO> saveInfoList;
	if (! m_pSqlHelper->get_answers_save__list(saveInfoList))
	{
		return false;
	}
	
	QList<INS_ANSWER_SAVEINFO>::iterator it = saveInfoList.begin();
	for (; it != saveInfoList.end(); ++it)
	{
		QVector<INS_ANSWER> answerVector;
		if (! m_pSqlHelper->get_answer_list(it->nIndex, answerVector))
		{
			continue;
		}

		m_answerMap.insert(it->nIndex, answerVector);
	}
	return true;
}

int AnswerCenter::CreateAnswerSave(INS_ANSWER_SAVEINFO& answerSaveInfo)
{
	if (! m_pSqlHelper)
		return false;

	if (m_pSqlHelper->is_answer_table_exist(answerSaveInfo.sTestName))
	{
		return -2; //±íÒÑ´æÔÚ
	}

	int nIndex = m_pSqlHelper->add_answer_save(answerSaveInfo);
	if (nIndex == -1)
	{
		return -1;
	}

	if (! m_pSqlHelper->create_table_answers(nIndex))
	{
		return -1;
	}

	QVector<INS_ANSWER> answerVector;
	m_answerMap.insert(nIndex, answerVector);
	return nIndex;
}

bool AnswerCenter::CommitAnswer(int nSaveIndex, INS_ANSWER& answer)
{
	if (! m_pSqlHelper)
		return false;

	if (! m_pSqlHelper->add_answer(nSaveIndex, answer))
	{
		return false;
	}

	m_answerMap[nSaveIndex].push_back(answer);
	return true;
}

bool AnswerCenter::ReturnBackTo(int nSaveIndex, int nAnswerIndex)
{
	if (! m_pSqlHelper->return_back_answers(nSaveIndex, nAnswerIndex))
	{
		return false;
	}

	int nCount = m_answerMap[nSaveIndex].size();
	for (int i=nCount-1; i>nAnswerIndex; --i)
	{
		m_answerMap[nSaveIndex].remove(i);
	}
	return true;
}

bool AnswerCenter::GetAnswerSaveInfoByIndex(int nSaveIndex, INS_ANSWER_SAVEINFO &saveInfo)
{
      if (! m_pSqlHelper->get_answer_saveinfo_by_index(nSaveIndex, saveInfo))
      {
          return false;
      }
      return true;
}

bool AnswerCenter::GetAnswerSaveInfoList(QList<INS_ANSWER_SAVEINFO>& infolist)
{
    if (! m_pSqlHelper->get_answers_save__list(infolist))
    {
        return false;
    }
    return true;
}

bool AnswerCenter::GetAnswerVectorByIndex(int nSaveIndex, ANSWER_VECTOR& vec)
{
    ANSWER_SAVE_MAP::iterator it = m_answerMap.find(nSaveIndex);
    if (it == m_answerMap.end())
    {
        return false;
    }
    vec = *it;
    return true;
}

bool AnswerCenter::QueryAnswerOfQuestion(int nSaveIndex, QString &strQuesId, QString &strAnswer)
{
    ANSWER_SAVE_MAP::iterator it_answer_vec = m_answerMap.find(nSaveIndex);
    if (it_answer_vec == m_answerMap.end())
    {
        return false;
    }

    ANSWER_VECTOR::iterator it_answer = it_answer_vec->begin();
    for (; it_answer != it_answer_vec->end(); ++it_answer)
    {
        if (it_answer->sQuestionid == strQuesId)
        {
            strAnswer = it_answer->sAnswer;
            return true;
        }
    }
    return false;
}

bool AnswerCenter::GetTestNameBySaveIndex(int nIndex, QString &strTestName)
{
    INS_ANSWER_SAVEINFO saveInfo;
    if (m_pSqlHelper->get_answer_saveinfo_by_index(nIndex, saveInfo))
    {
        strTestName = saveInfo.sTestName;
        return true;
    }
    return false;
}

bool AnswerCenter::DeleteAnswer(int nSaveIndex)
{
    if (m_pSqlHelper->del_answer(nSaveIndex))
    {
        return true;
    }
    return false;
}

void AnswerCenter::Handl_S_Part_Answer()
{
    
}