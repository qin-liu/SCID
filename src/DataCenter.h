#ifndef _DATACENTER_H_
#define _DATACENTER_H_
#include "BasicExcel.hpp"

class SqlHelper;
class AnswerCenter;

class DataCenter
{
public:
	DataCenter();
	virtual ~DataCenter();

public:
	void SetSqlHelper(SqlHelper *pHelper);
	GROUP_MAP GetGroupMap(){ return m_groupMap; }
	QUESTION_MAP GetQuesMap(){return m_question_map; }
	bool LoadFromDB();									//从数据库加载数据
	bool LoadFromExcel(QString &sExcelPathName);		//从Excel加载数据
	bool ClearData();									//清空所有数据，和数据库数据
	
	int GetNextQuestionByJumpCondition(QString& strQuesId, QString& sAnswer, AnswerCenter *pAncenter, int nSaveIndex, INS_QUESTION& question/*out*/);
    int GetStatisticsJump(QString& strQuesId, AnswerCenter *pAncenter, int nSaveIndex, INS_ANSWER &answer, INS_QUESTION& question/*out*/); //判断统计题的跳转
    bool SaveQuestion(INS_QUESTION &ques);
    bool addDiagnose(INS_DIAGNOSIS& diagnose);
private:
	bool SaveToDB();   //写入数据库
	bool LoadSheet1(YExcel::BasicExcelWorksheet *pSheet1); 
	bool LoadSheet2(YExcel::BasicExcelWorksheet *pSheet2);
	bool LoadSheet3(YExcel::BasicExcelWorksheet *pSheet3);
    bool LoadSheet4(YExcel::BasicExcelWorksheet *pSheet4);
	QString GetExcelColumnCharName(int nColum);
    void InsertCondition(INS_CONDITION &condition);
    bool IsMatchCondition(INS_QUESTION &question, int nSelection, AnswerCenter *pAncenter, int nSaveIndex);
    int  TranAnswerToSelection(QString &strAnswer);
    void InsertConditionListToMap(QList<INS_CONDITION> condition_list);
public:
	GROUP_MAP m_groupMap;	
	QUESTION_MAP m_question_map;
	QUES_CONDITONMAP_MAP m_conditionmap_map;
    DIAGNOSIS_VEC m_diagnosis_vec;
private:
	SqlHelper* m_pSqlHelper;
};

#endif