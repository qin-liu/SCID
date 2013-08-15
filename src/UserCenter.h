#ifndef _USERCENTER_H_
#define _USERCENTER_H_
class SqlHelper;

class UserCenter
{
public:
	UserCenter();
	virtual ~UserCenter();
	
    void SetSqlHelper(SqlHelper* pSqlHelper);
	bool LoadFromDB();
    bool Verify(QString &strUserName, QString &strPassword);
	bool IsUser(QString &username, int* role);
	bool AddUser(INS_USER &user);
	bool DelUser(QString &username);
	bool ChangPassword(QString &username, QString &newPassword);
	bool ChangRole(QString &username, int role);

    USER_MAP m_user_map;
private:
	SqlHelper* m_pSqlHelper;
};
#endif