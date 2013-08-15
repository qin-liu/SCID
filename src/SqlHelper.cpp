#include "stdafx.h"
#include "Transfer.h"
#include "SqlHelper.h"
#include "HTMLUtility.h"

#define MAX_SQL_LEN 512
#define MAX_ERR_MSG 128

const QString ANSWER_TABLE_PREFIX = "T_ANSWERSAVE_";

SqlHelper::SqlHelper()
{
	m_hSql = NULL;
}

SqlHelper::~SqlHelper()
{

}

bool SqlHelper::init_db(QString &filename)
{
	bool bRet = true;
	bool bExit = QFile::exists(filename);

	bRet  = open_sql(filename.toAscii().constData());
	if (! bExit)
	{
		bRet &= create_table_user();
        INS_USER user;
        user.sUserName = "admin";
        user.sPassword = "admin";
        user.nRole = 0;
        add_user(user);

		bRet &= create_table_question_group();
		bRet &= create_table_question();
		bRet &= create_table_jump_condition();
		bRet &= create_table_answer_save();
        bRet &= create_table_diagnosis();
	}
	return bRet;
}

bool SqlHelper::open_sql(const QString sql_name)
{
	if (sql_name == NULL)
		return false;

	if (m_hSql == NULL)
	{
		QString strSql(sql_name); 
		int nRet = sqlite3_open(strSql.toUtf8().constData(), &m_hSql);
		if(nRet == SQLITE_OK)
			return true;
	}
	return false;
}

bool SqlHelper::close_sql()
{
	if (m_hSql != NULL)
	{
		if(SQLITE_OK == sqlite3_close(m_hSql))
			return true;
	}
	return false;
}

bool SqlHelper::create_table_user()
{
	bool bRet = true;
	char* pchError;
	QString strSql = "CREATE TABLE  [T_USER] (\
					  [username]	VARCHAR(32) NOT NULL, \
					  [password]	VARCHAR(32) NOT NULL, \
					  [role]        SMALLINT NOT NULL);";

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

	if (nRet != SQLITE_OK)
		bRet = false;
	sqlite3_free(pchError);
	return bRet;
}

bool SqlHelper::create_table_question()
{
	bool bRet = true;
	QString strSql = "CREATE TABLE  [T_QUESTION] ( \
						[id_name]	VARCHAR(8)  PRIMARY KEY,\
						[type]      INTEGER(1)  NOT NULL,\
						[content]	VARCHAR,\
						[introduction] VARCHAR[512],\
						[jump0]		INTEGER,\
						[jump1]		INTEGER,\
						[jump2]		INTEGER,\
						[jump3]		INTEGER,\
						[valid0]    INTEGER,\
						[valid1]    INTEGER,\
						[valid2]    INTEGER,\
						[valid3]    INTEGER);";
	char*pError = NULL;
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pError);

	if (nRet != SQLITE_OK)
		bRet = false;
	return bRet;
}

bool SqlHelper::create_table_question_group()
{
	bool bRet = true;
	QString strSql = "CREATE TABLE  [T_QUESTION_GROUP] ( \
						[groupname]      VARCHAR(32) PRIMARY KEY NOT NULL,\
						[question_count] INTEGER);";

	char *pErrorMsg;
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pErrorMsg);

	if (nRet != SQLITE_OK)
		bRet = false;
	return bRet;
}

bool SqlHelper::create_table_answers(int nIndex)
{
	bool bRet = true;
	
    QString strTableName = ANSWER_TABLE_PREFIX + QString::number(nIndex);
	QString strSql = QString("CREATE TABLE [%1] ([rowid] INTEGER PRIMARY KEY,[Qid] VARCHAR(8) NOT NULL, [answer] VARCHAR(1024));").arg(strTableName);

	char* pchError;
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

	if (nRet != SQLITE_OK)
		bRet = false;
	return bRet;
}

bool SqlHelper::create_table_answer_save()
{
	bool bRet = true;
	QString strSql =    "CREATE TABLE  [T_ANSWER_SAVE] ( \
						[rowid] INTEGER PRIMARY KEY, \
						[answer_table_name] VARCHAR(32) NOT NULL,\
						[tester_name] VARCHAR(32),\
						[answer_name] VARCHAR(32),\
                        [user]  VARCHAR(32),\
						[date]  VARCHAR(64));";
	char* pchError;
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

	if (nRet != SQLITE_OK)
		bRet = false;
	return bRet;
}

bool SqlHelper::create_table_jump_condition()
{
	bool bRet = true;
	char* pchError = NULL;
	QString strSql =    "CREATE TABLE  [T_JUMP_CONDITION] ( \
						[rowid]        INTEGER PRIMARY KEY NOT NULL,\
						[questionid]   VARCHAR(8) NOT NULL,\
						[selection]    INTEGER NOT NULL,\
						[condition_questionid] VARCHAR(8) NOT NULL,\
						[jump_when_s0] INTEGER(4),\
						[jump_when_s1] INTEGER(4),\
						[jump_when_s2] INTEGER(4),\
						[jump_when_s3] INTEGER(4));";
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

	if (nRet != SQLITE_OK)
		bRet = false;
	return bRet;
}

bool SqlHelper::create_table_diagnosis()
{
    bool bRet = true;
    char* pchError = NULL;
    QString strSql =    "CREATE TABLE  [T_DIAGNOSIS] ( \
                        [rowid]        INTEGER PRIMARY KEY NOT NULL,\
                        [questionid]   VARCHAR(8) NOT NULL,\
                        [key]          VARCHAR(256),\
                        [diagnosis]    VARCHAR(512) NOT NULL);";
    int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

    if (nRet != SQLITE_OK)
        bRet = false;
    return bRet;
}

bool SqlHelper::add_user(INS_USER& user)
{
	int nRowid = -1;
	char* pchError = NULL;
	QString strSql = QString("INSERT INTO T_USER VALUES('%1', '%2', %3)").arg(user.sUserName).arg(user.sPassword).arg(user.nRole);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		return true;
	else
		return false;
}

int SqlHelper::add_question(INS_QUESTION& question)
{
	int nRowid = -1;
	char* pchError = NULL;
	QString strSql = QString("INSERT INTO T_QUESTION VALUES ('%1', %2, '%3', '%4', '%5', '%6', '%7', '%8', %9, %10, %11, %12)")
		.arg(question.sID)
		.arg(question.nType)
		.arg(question.sContent)
		.arg(question.sIntroduction)
		.arg(question.sJump0)
		.arg(question.sJump1)
		.arg(question.sJump2)
		.arg(question.sJump3)
		.arg(question.nValid0)
		.arg(question.nValid1)
		.arg(question.nValid2)
		.arg(question.nValid3);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		return true;
	return false;
}

bool SqlHelper::add_groupe(INS_QUESTION_GROUP &group)
{
	int nRowid = 0;
	char* pchError = NULL;

	QString strSql = QString("INSERT INTO T_QUESTION_GROUP VALUES ('%1', %2)").arg(group.sName).arg(group.ulQuestionCount);
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

	if (nRet == SQLITE_OK)
		return true;
	return false;
}

bool SqlHelper::add_answer(int nIndex, INS_ANSWER& answer)
{
	int nRowid = -1;
	char* pchError = NULL;
	QString strSql = QString("INSERT INTO %1 VALUES(NULL, '%2', '%3')")
        .arg(ANSWER_TABLE_PREFIX + QString::number(nIndex))
		.arg(answer.sQuestionid)
		.arg(answer.sAnswer);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		nRowid = sqlite3_last_insert_rowid(m_hSql);
	answer.nIndex = nRowid;
	return nRowid != -1;
}

int SqlHelper::add_answer_save(INS_ANSWER_SAVEINFO& answer_save)
{
	int nRowid = 0;
	char* pchError = NULL;

	QString strSql = QString("INSERT INTO T_ANSWER_SAVE VALUES (NULL, '%1', '%2', '%3', '%4', '%5');")
		.arg(answer_save.sTestName)
		.arg(answer_save.sTesterName)
		.arg(answer_save.sAnswerName)
        .arg(answer_save.sUser)
		.arg(answer_save.sDateTime);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

	if (nRet == SQLITE_OK)
		nRowid = sqlite3_last_insert_rowid(m_hSql);
	answer_save.nIndex = nRowid;
	return nRowid;
}

bool SqlHelper::add_diagnosis(INS_DIAGNOSIS& diag)
{
    int nRowid = 0;
    char* pchError = NULL;

    QString strSql = QString("INSERT INTO T_DIAGNOSIS VALUES (NULL, '%1', '%2', '%3')")
        .arg(diag.sQuestionid)
        .arg(diag.sKeyContent)
        .arg(diag.sDiagnosis);
    int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);

    if (nRet == SQLITE_OK)
        return true;
    return false;
}

bool SqlHelper::is_answer_table_exist(QString &strTestName)
{
	int nRows = 0;
	int nCol = 0;
	char** pTable = NULL;
	QString strSql = QString("SELECT * FROM T_ANSWER_SAVE WHERE test_name = '%1';").arg(strTestName);

	pTable = execute_query(m_hSql, strSql, nRows, nCol);
	bool bRet = true;
	if (nRows == 0)
	{
		bRet = false;
	}
	free_table(pTable);
	return bRet;
} 

int SqlHelper::add_jump_condition(INS_CONDITION& condition)
{
	int nRowid = -1;
	char* pchError = NULL;

	QString strSql = QString("INSERT INTO T_JUMP_CONDITION VALUES(NULL, '%1', %2, '%3', %4, %5, %6, %7)")
		.arg(condition.sQuestionid)
		.arg(condition.selection)
		.arg(condition.sCondtionQuestionid)
		.arg(condition.bJumpSelect0)
		.arg(condition.bJumpSelect1)
		.arg(condition.bJumpSelect2)
		.arg(condition.bJumpSelect3);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		nRowid = sqlite3_last_insert_rowid(m_hSql);
	condition.nIndex = nRowid;
	return nRowid;
}

bool SqlHelper::update_question(INS_QUESTION& question)
{
	int nRowid = -1;
	char* pchError = NULL;

    QString sConstent = HTMLEncode(question.sContent);
	QString strSql = QString("UPDATE T_QUESTION SET type=%1, content='%2', introduction='%3', jump0='%4', jump1='%5', jump2='%6', jump3='%7', valid0=%8, valid1=%9, valid2=%10, valid3=%11 WHERE id_name = '%12';")
						.arg(question.nType)
						.arg(sConstent)
						.arg(question.sIntroduction)
						.arg(question.sJump0)
						.arg(question.sJump1)
						.arg(question.sJump2)
						.arg(question.sJump3)
						.arg(question.nValid0)
						.arg(question.nValid1)
						.arg(question.nValid2)
						.arg(question.nValid3)
						.arg(question.sID);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet != SQLITE_OK)
		return false;

	return true;
}

bool SqlHelper::update_user_password(QString &username, QString &password)
{
	char* pchError = NULL;
	QString strSql = QString("UPDATE T_USER SET password='%1' WHERE username='%2';")
						.arg(password)
						.arg(username);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet != SQLITE_OK)
		return false;
	return true;
}

bool SqlHelper::update_user_role(QString &username, int role)
{
	char* pchError = NULL;
	QString strSql = QString("UPDATE T_USER SET role='%1' WHERE username='%2';")
		.arg(role)
		.arg(username);

	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet != SQLITE_OK)
		return false;
	return true;
}

bool SqlHelper::get_user_list(USER_MAP& user_list)
{
	int nRows = 0;
	int nCol = 0;
	QString strSql("SELECT * FROM T_USER;");	//查询表T_USER
	char **pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	for (int i=1; i<=nRows; ++i)
	{
		INS_USER user;
		user.sUserName = QString::fromUtf8(pTable[i*nCol+0]);
		user.sPassword = QString::fromUtf8(pTable[i*nCol+1]);
		user.nRole = QString::fromUtf8(pTable[i*nCol+2]).toInt();
		user_list.insert(user.sUserName, user);
	}
	free_table(pTable);
	return true;
}

bool SqlHelper::get_question_list(QUESTION_MAP& question_map)
{
	int nRows = 0;
	int nCol = 0;
	QString strSql("SELECT * FROM T_QUESTION;");	//查询表T_QUESTION
	char** pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	for (int i=1; i<=nRows; ++i)
	{
		INS_QUESTION quesiton;
		quesiton.sID = QString::fromUtf8(pTable[i*nCol+0]);
		quesiton.nType = QString::fromUtf8(pTable[i*nCol+1]).toInt();
		quesiton.sContent =  QString::fromUtf8(pTable[i*nCol+2]);
		quesiton.sIntroduction = QString::fromUtf8(pTable[i*nCol+3]);
		quesiton.sJump0 = QString::fromUtf8(pTable[i*nCol+4]);
		quesiton.sJump1 = QString::fromUtf8(pTable[i*nCol+5]);
		quesiton.sJump2 = QString::fromUtf8(pTable[i*nCol+6]);
		quesiton.sJump3 = QString::fromUtf8(pTable[i*nCol+7]);
		quesiton.nValid0 = QString::fromUtf8(pTable[i*nCol+8]).toInt();
		quesiton.nValid1 = QString::fromUtf8(pTable[i*nCol+9]).toInt();
		quesiton.nValid2 = QString::fromUtf8(pTable[i*nCol+10]).toInt();
		quesiton.nValid3 = QString::fromUtf8(pTable[i*nCol+11]).toInt();
        quesiton.sContent = HTMLDecode(quesiton.sContent);
		question_map.insert(TransStrToIntID(quesiton.sID), quesiton);
	}
	free_table(pTable);
	return true;
}

bool SqlHelper::get_group_map(GROUP_MAP& group_map)
{
	int nRows = 0;
	int nCol = 0;
	char** pTable = NULL;
	QString strSql("SELECT * FROM T_QUESTION_GROUP;");	
	pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	for (int i=1; i<=nRows; ++i)
	{
		INS_QUESTION_GROUP group;
		group.sName  = QString::fromUtf8(pTable[i*nCol+0]);
		group.ulQuestionCount = QString::fromUtf8(pTable[i*nCol+1]).toInt();
		group_map.insert(group.sName, group);
	}
	free_table(pTable);
	return true;
}

bool SqlHelper::get_answer_saveinfo_by_index(int nSaveIndex, INS_ANSWER_SAVEINFO &info)
{
	int nRows = 0;
	int nCol = 0;
	QString strSql = QString("SELECT * FROM T_ANSWER_SAVE WHERE rowid = %1;").arg(nSaveIndex);
	char **pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	bool bRet = false;
	if (nRows == 1)
	{
        info.nIndex = QString::fromUtf8(pTable[1*nCol + 0]).toInt();
        info.sTestName = QString::fromUtf8(pTable[1*nCol + 1]);
        info.sTesterName = QString::fromUtf8(pTable[1*nCol + 2]);
        info.sAnswerName = QString::fromUtf8(pTable[1*nCol + 3]);
        info.sDateTime = QString::fromUtf8(pTable[1*nCol + 4]);
		bRet = true;
	}
	free_table(pTable);
	return bRet;
}

bool SqlHelper::get_answer_list(int nSaveIndex, QVector<INS_ANSWER>& answer_list)
{
	int nRows = 0;
	int nCol = 0;
	char** pTable = NULL;
    QString strTable = ANSWER_TABLE_PREFIX + QString::number(nSaveIndex);
	QString strSql("SELECT * FROM ");
	strSql = strSql + strTable + ";";
	
	pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	for (int i=1; i<=nRows; ++i)
	{
		INS_ANSWER answer;
		answer.nIndex = QString::fromUtf8(pTable[i*nCol+0]).toInt() - 1;
		answer.sQuestionid = QString::fromUtf8(pTable[i*nCol+1]);
		answer.sAnswer = QString::fromUtf8(pTable[i*nCol+2]);
		answer_list.push_back(answer);
	}
	free_table(pTable);
	return true;
}

bool SqlHelper::get_answers_save__list(QList<INS_ANSWER_SAVEINFO>& answers_save_list)
{
	int nRows = 0;
	int nCol = 0;
	char** pTable = NULL;
	QString strSql("SELECT * FROM T_ANSWER_SAVE;");	
	pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	for (int i=1; i<=nRows; ++i)
	{
		INS_ANSWER_SAVEINFO answer_save;
		answer_save.nIndex = QString::fromUtf8(pTable[i*nCol+0]).toInt();
		answer_save.sTestName = QString::fromUtf8(pTable[i*nCol+1]);
		answer_save.sTesterName = QString::fromUtf8(pTable[i*nCol+2]);
		answer_save.sAnswerName = QString::fromUtf8(pTable[i*nCol+3]);
        answer_save.sUser = QString::fromUtf8(pTable[i*nCol+4]);
        answer_save.sDateTime = QString::fromUtf8(pTable[i*nCol+5]);
		answers_save_list.push_back(answer_save);
	}
	free_table(pTable);
	return true;
}

bool SqlHelper::get_jump_condition_list(QList<INS_CONDITION>& condition_list)
{
	int nRows = 0;
	int nCol = 0;
	char** pTable = NULL;
	QString strSql("SELECT * FROM T_JUMP_CONDITION;");	
	pTable = execute_query(m_hSql, strSql, nRows, nCol);
	if (pTable == NULL)
	{
		return false;
	}

	for (int i=1; i<=nRows; ++i)
	{
		INS_CONDITION condition;
		condition.nIndex = QString::fromUtf8(pTable[i*nCol+0]).toUInt();
		condition.sQuestionid = QString::fromUtf8(pTable[i*nCol+1]);
		condition.selection = (INS_SELECTION)QString::fromUtf8(pTable[i*nCol+2]).toInt();
		condition.sCondtionQuestionid  = QString::fromUtf8(pTable[i*nCol+3]);
		condition.bJumpSelect0 = QString::fromUtf8(pTable[i*nCol+4]).toInt();
		condition.bJumpSelect1 = QString::fromUtf8(pTable[i*nCol+5]).toInt();
		condition.bJumpSelect2 = QString::fromUtf8(pTable[i*nCol+6]).toInt();
		condition.bJumpSelect3 = QString::fromUtf8(pTable[i*nCol+7]).toInt();
		condition_list.push_back(condition);
	}
	free_table(pTable);
	return true;
}

bool SqlHelper::get_diagnosis_list(DIAGNOSIS_VEC& diagnosis_vec)
{
    int nRows = 0;
    int nCol = 0;
    QString strSql = QString("SELECT * FROM T_DIAGNOSIS;");
    char **pTable = execute_query(m_hSql, strSql, nRows, nCol);
    if (pTable == NULL)
    {
        return false;
    }

    for (int i=1; i<=nRows; ++i)
    {
        INS_DIAGNOSIS diagnosis;
        diagnosis.sQuestionid = QString::fromUtf8(pTable[i*nCol+1]);
        diagnosis.sKeyContent = QString::fromUtf8(pTable[i*nCol+2]);
        diagnosis.sDiagnosis = QString::fromUtf8(pTable[i*nCol+3]);
        diagnosis_vec.push_back(diagnosis);
    }
    free_table(pTable);
    return true;
}

bool SqlHelper::del_question(QString &sID)
{
	char* pchError = NULL;
	TCHAR sql[256] = {0};

	QString strSql = QString("DELETE FROM T_QUESTION WHERE orderid = %1;").arg(sID);
	int nRet = sqlite3_exec(m_hSql, strSql.toUtf8().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		return true;
	return false;
}

bool SqlHelper::del_user(const QString &sUserName)
{
	char* pchError = NULL;

	QString strSql = QString("DELETE FROM T_USER WHERE username = '%1';").arg(sUserName);
	int nRet = sqlite3_exec(m_hSql, strSql.toAscii().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		return true;
	return false;
}

bool SqlHelper::del_answer(int nSaveIndex)
{
    char* pchError = NULL;
    QString strSql = QString("DELETE FROM T_ANSWER_SAVE WHERE rowid = %1;").arg(nSaveIndex);
    int nRet1 = sqlite3_exec(m_hSql, strSql.toAscii().constData(), NULL, NULL, &pchError);

    QString strTableName = ANSWER_TABLE_PREFIX + QString::number(nSaveIndex);
    strSql = QString("DROP TABLE %1;").arg(strTableName);
    int nRet2 = sqlite3_exec(m_hSql, strSql.toAscii().constData(), NULL, NULL, &pchError);
    if (nRet1 == SQLITE_OK && nRet2 == SQLITE_OK)
        return true;
    return false;
}

bool SqlHelper::return_back_answers(int nSaveIndex, int nIndex)
{
	char* pchError = NULL;
    QString strTable = ANSWER_TABLE_PREFIX + QString::number(nSaveIndex);
	QString strSql = QString("DELETE FROM  %1 WHERE  rowid > %2;").arg(strTable).arg(nIndex+1); //第一行为1
	int nRet = sqlite3_exec(m_hSql, strSql.toAscii().constData(), NULL, NULL, &pchError);
	if (nRet == SQLITE_OK)
		return true;
	return false;
}

bool SqlHelper::SaveAnswerList(std::vector<INS_ANSWER> answers_list, int nIndex, const QString &sTesterName, const QString &sAnswerName)
{
	if (! create_table_answers(nIndex))
	{
		return false;
	}
	
    QString strTableName = ANSWER_TABLE_PREFIX + QString::number(nIndex);
	std::vector<INS_ANSWER>::iterator it_a = answers_list.begin();
	for (; it_a != answers_list.end(); ++it_a)
	{
		add_answer(nIndex, *it_a);
	}

	QDateTime datetime = QDateTime::currentDateTime();
	QString strDateTime = datetime.toString("yyyy-mm-dd hh:mm:ss");

	INS_ANSWER_SAVEINFO answer_save;
	answer_save.sTestName = strTableName;
	answer_save.sTesterName = sTesterName;
	answer_save.sAnswerName = sAnswerName;
	answer_save.sDateTime = strDateTime;
	add_answer_save(answer_save);
	return true;
}

bool SqlHelper::ClearAllData()
{
	bool bRet = true;
	QString strDel("DELETE FROM T_QUESTION;");
	int nRet = sqlite3_exec(m_hSql, strDel.toUtf8().constData(), NULL, NULL, NULL);
	if (nRet != SQLITE_OK)
		bRet = false;		

	strDel = "DELETE FROM T_QUESTION_GROUP;";
	nRet = sqlite3_exec(m_hSql, strDel.toUtf8().constData(), NULL, NULL, NULL);
	if (nRet != SQLITE_OK)
		bRet &= false;	

	strDel = "DELETE FROM T_JUMP_CONDITION;";
	nRet = sqlite3_exec(m_hSql, strDel.toUtf8().constData(), NULL, NULL, NULL);
	if (nRet != SQLITE_OK)
		bRet &= false;	

//  不删除答案
// 	QList<INS_ANSWER_SAVEINFO> answer_save_list;
// 	if (get_answers_save__list(answer_save_list))
// 	{
// 		//删除所有保存答案表
// 		QList<INS_ANSWER_SAVEINFO>::iterator it_answer_save = answer_save_list.begin();
// 		for(; it_answer_save != answer_save_list.end(); ++it_answer_save)
// 		{
// 			QString strTableName = ANSWER_TABLE_PREFIX + it_answer_save->sTesterName;
// 			QString strSqlDel = "DROP TABLE " + strTableName;
// 			int nRet = sqlite3_exec(m_hSql, strSqlDel.toAscii().constData(), NULL, NULL, NULL);
// 			if (nRet != SQLITE_OK)
// 				bRet &= false;
// 		}
// 	}
    
// 	strDel = "DELETE FROM T_ANSWER_SAVE;";
// 	nRet = sqlite3_exec(m_hSql, strDel.toAscii().constData(), NULL, NULL, NULL);
// 	if (nRet != SQLITE_OK)
// 		bRet &= false;	

    strDel = "DELETE FROM T_DIAGNOSIS;";
    nRet = sqlite3_exec(m_hSql, strDel.toUtf8().constData(), NULL, NULL, NULL);
    if (nRet != SQLITE_OK)
        bRet &= false;
	return bRet;
}


char** SqlHelper::execute_query(sqlite3* pSqlite, QString& sql, int& nRow, int& nColumn)
{
	if (pSqlite == NULL || sql == NULL)
		return NULL;

	char **azTable = NULL;
	int nRet = sqlite3_get_table(pSqlite, sql.toUtf8().constData(), &azTable, &nRow, &nColumn, NULL);
	if(nRet != SQLITE_OK)
	{
		return NULL;
	}
	return azTable;
}

void SqlHelper::free_table(char** table)
{
	if (table)
	{
		sqlite3_free_table(table);
	}
}