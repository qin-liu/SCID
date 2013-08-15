#ifndef _SQLHELPER_H_
#define _SQLHELPER_H_

//为Inspect项目提供sql操作接口
class  SqlHelper
{
public:
	SqlHelper();
	virtual ~SqlHelper();
	bool init_db(QString &filename);
	bool create_table_answers(int nIndex);
	bool add_user(INS_USER& user);
	int  add_question(INS_QUESTION& question);
	bool add_groupe(INS_QUESTION_GROUP &group);
	bool add_answer(int nIndex, INS_ANSWER& answer);
	int  add_answer_save(INS_ANSWER_SAVEINFO& answer_save);
    bool add_diagnosis(INS_DIAGNOSIS& diag);
	bool is_answer_table_exist(QString &strTestName);
	int  add_jump_condition(INS_CONDITION& condition);
	bool update_question(INS_QUESTION& question);
	bool update_user_password(QString &username, QString &password);
	bool update_user_role(QString &username, int role);
	bool get_user_list(USER_MAP& user_list);
	bool get_question_list(QUESTION_MAP &question_list);
	bool get_group_map(GROUP_MAP& group_list);
	bool get_answer_saveinfo_by_index(int nSaveIndex, INS_ANSWER_SAVEINFO &info);
	bool get_answer_list(int nSaveIndex, QVector<INS_ANSWER>& answer_list);
	bool get_answers_save__list(QList<INS_ANSWER_SAVEINFO>& answers_save_list);
	bool get_jump_condition_list(QList<INS_CONDITION>& condition_list);
    bool get_diagnosis_list(DIAGNOSIS_VEC& diagnosis_vec);
	bool del_user(const QString &sUserName);
	bool del_question(QString &sID);
    bool del_answer(int nSaveIndex);
	bool return_back_answers(int nSaveIndex, int nIndex);
	bool SaveAnswerList(std::vector<INS_ANSWER> answers_list, int nIndex, const QString &sTesterName, const QString &sAnswerName);
	bool ClearAllData();	//清空所有Inspect相关数据
private:
	bool open_sql(const QString sql_name);
	bool close_sql();		
	bool create_table_user();
	bool create_table_question();
	bool create_table_question_group();
	bool create_table_answer_save();
	bool create_table_jump_condition();
    bool create_table_diagnosis();
	char** execute_query(sqlite3* pSqlite, QString& sql, int& nRow, int& nColumn);
	void free_table(char** table);
	sqlite3* m_hSql; //sql句柄
};
#endif