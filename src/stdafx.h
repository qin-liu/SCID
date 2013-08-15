#ifndef _STDAFX_H_
#define _STDAFX_H_

#define _BIND_TO_CURRENT_VCLIBS_VERSION 1

//QT
#include <QtCore>
#include <QtGui>
#include <QList>
#include <QtAlgorithms>
#include <QFont>
#include <QSettings>
//windows
#include <windows.h>


//sqlite3
#include "sqlite3.h"
#pragma comment(lib, "sqlite3.lib")


//SCID
#include "scidData.h"
#include "scidutility.h"


typedef QMap<QString, INS_USER> USER_MAP;
typedef QVector<INS_CONDITION> CONDITION_VEC;
typedef QVector<CONDITION_VEC> CONDITION_VEC_VEC;
typedef QMap<QString, CONDITION_VEC_VEC> QUES_CONDITONMAP_MAP;  //map<quesId, �ĸ�ѡ���vec>
typedef QMap<QString, INS_QUESTION_GROUP> GROUP_MAP;	
typedef QMap<int, INS_QUESTION> QUESTION_MAP;
typedef QVector<INS_ANSWER> ANSWER_VECTOR;
typedef QMap<int, ANSWER_VECTOR> ANSWER_SAVE_MAP;
typedef QVector<INS_DIAGNOSIS> DIAGNOSIS_VEC;

#include "Singlton.h"
#include "DataCenter.h"
typedef Singleton<DataCenter> DATACENTER;

#include "SqlHelper.h"
typedef Singleton<SqlHelper> SQLHELPER;

#include "AnswerCenter.h"
typedef Singleton<AnswerCenter> ANCENTER;

#include "UserCenter.h"
typedef Singleton<UserCenter> USERCENTER;

#define SET_FONT setFont(QFont("����", 12));
#endif


//�����û��汾���߼������������ȹ��ܣ���ͨ�������Щ����
#define  CLIENT_VERSION