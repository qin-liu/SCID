#ifndef _INSPECTDATA_H_
#define _INSPECTDATA_H_
#include "scidutility.h"

#define QUE_ID_LEN           8
#define MAX_NAME_LEN         32
#define MAX_CONTENT_LEN      4000
#define MAX_INTRODUCION_LEN  1024
#define MAX_ANSWER_LEN       1024
#define MAX_KEY_LEN          32
#define MAX_QUESTION_ID      3000
#define BK_RGB RGB(236,233,216) //背景色
//Inspect中的元数据

//题目类型
enum QUESITON_TYPE
{
	QTYPE_SELECTION = 1,
	QTYPE_DESCRIBE  = 2
};


typedef enum _INS_SELECTION
{
	S_QMARK   = 0,
	S_ONE,
	S_TWO,
	S_THREE,
}INS_SELECTION;


typedef struct _INS_USER			//用户
{
	QString sUserName;
	QString sPassword;
	int nRole;        // 0是管理员 1是普通用户
}INS_USER;


typedef struct _INS_QUESTION		//测试题
{
	 QString sID;      //name = group char + id
	 QString sContent;
	 QString sIntroduction;
	 int  nType;		//0为选择题 1为填空题
	 int nValid0;
	 int nValid1;
	 int nValid2;
	 int nValid3;
	 QString sJump0;
	 QString sJump1;
	 QString sJump2;
	 QString sJump3;
}INS_QUESTION;


typedef struct _INS_QUESTION_GROUP  //试题组
{
	QString sName;
	unsigned int ulQuestionCount;

	_INS_QUESTION_GROUP()
	{
		ulQuestionCount = 0;
	}
}INS_QUESTION_GROUP;


typedef struct _INS_ANSWER         //答案
{
	int nIndex;
	QString sQuestionid;
	QString sAnswer;

	_INS_ANSWER()
	{
		nIndex = -1;
	}

    bool operator==(const _INS_ANSWER &other)const
    {
        return (sQuestionid == other.sQuestionid) && (sAnswer == other.sAnswer);
    }
}INS_ANSWER;

typedef struct _INS_ANSWER_SAVEINFO   //保存的答案信息
{
	int nIndex;
	QString sTestName;
	QString sTesterName;
	QString sAnswerName;
    QString sUser;
	QString sDateTime;

	_INS_ANSWER_SAVEINFO()
	{
		nIndex = -1;
	}

	bool operator<(const _INS_ANSWER_SAVEINFO& other)const
	{
		return nIndex < other.nIndex;
	}
}INS_ANSWER_SAVEINFO;

typedef struct _INS_CONDITION      //跳转条件
{
	int nIndex;
	QString sQuestionid;
	int selection;
	QString sCondtionQuestionid;
	int  bJumpSelect0;
	int  bJumpSelect1;
	int  bJumpSelect2;
	int  bJumpSelect3;
	QString sIntroduction;

	_INS_CONDITION()
	{
		nIndex = -1;
		selection = 0;
		bJumpSelect0 = 0;
		bJumpSelect1 = 0;
		bJumpSelect2 = 0;
		bJumpSelect3 = 0;
	}
}INS_CONDITION;

typedef struct _INS_DIAGNOSIS   //诊断
{
    QString sQuestionid;
    QString sKeyContent;
    QString sDiagnosis;
}INS_DIAGNOSIS;
#endif