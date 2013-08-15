#ifndef _TEST_ANSWER_SAVE_H_
#define _TEST_ANSWER_SAVE_H_

//�𰸺����ݿⱣ��ͬ��
class AnswerCenter
{
public:
	AnswerCenter();
	~AnswerCenter();
	void SetSqlHelper(SqlHelper *pHelper);
	bool LoadFromDB();
	int  CreateAnswerSave(INS_ANSWER_SAVEINFO& answerSaveInfo);
	bool CommitAnswer(int nSaveIndex, INS_ANSWER& answer);
	bool ReturnBackTo(int nSaveIndex, int nAnswerIndex);
    bool GetAnswerSaveInfoByIndex(int nSaveIndex, INS_ANSWER_SAVEINFO &saveInfo);
    bool GetAnswerSaveInfoList(QList<INS_ANSWER_SAVEINFO>& infolist);
    bool GetAnswerVectorByIndex(int nSaveIndex, ANSWER_VECTOR& vec);
    bool QueryAnswerOfQuestion(int nSaveIndex, QString &strQuesId, QString &strAnswer);
    bool GetTestNameBySaveIndex(int nIndex, QString &strTestName);
    bool DeleteAnswer(int nSaveIndex);
private:
    void Handl_S_Part_Answer();  //S���� ��Ҫ����E���ִ�

	ANSWER_SAVE_MAP m_answerMap;
	SqlHelper* m_pSqlHelper;
};
#endif