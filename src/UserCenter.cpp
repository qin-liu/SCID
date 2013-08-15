#include "stdafx.h"
#include "UserCenter.h"
#include "SqlHelper.h"

UserCenter::UserCenter()
{
    
}

UserCenter::~UserCenter()
{

}

void UserCenter::SetSqlHelper(SqlHelper* pSqlHelper)
{
    m_pSqlHelper = pSqlHelper;
}

bool UserCenter::LoadFromDB()
{
	if (! m_pSqlHelper->get_user_list(m_user_map))
	{
		return false;
	}
	return true;
}

bool UserCenter::Verify(QString &strUserName, QString &strPassword)
{
    USER_MAP::iterator it = m_user_map.find(strUserName);
    if (it == m_user_map.end())
    {
        QMessageBox::about(NULL, "登录", "无此用户");
        return false;
    }

    if (it->sPassword != strPassword)
    {
        QMessageBox::about(NULL, "登录", "密码错误");
        return false;
    }

    return true;
}

bool UserCenter::IsUser(QString &username, int* role)
{
	USER_MAP::iterator it = m_user_map.find(username);
	if (it == m_user_map.end())
	{
		return false;
	}
	
	*role = it.value().nRole;
	return true;
}

bool UserCenter::AddUser(INS_USER &user)
{
    USER_MAP::iterator it = m_user_map.find(user.sUserName);
    if (it != m_user_map.end())
    {
        QMessageBox::about(NULL, "添加用户", "用户已存在");
        return false;
    }

	if (! m_pSqlHelper->add_user(user))
	{
		return false;
	}

	m_user_map.insert(user.sUserName, user);
	return true;
}

bool UserCenter::DelUser(QString &username)
{
	USER_MAP::iterator it = m_user_map.find(username);
	if (it == m_user_map.end())
	{
		//没有此用户
        QMessageBox::about(NULL, "删除用户", "用户不存在");
		return false;
	}

	if (! m_pSqlHelper->del_user(username))
	{
		return false;
	}
	m_user_map.erase(it);
	return true;
}

bool UserCenter::ChangPassword(QString &username, QString &newPassword)
{
	USER_MAP::iterator it = m_user_map.find(username);
	if (it == m_user_map.end())
	{
		//没有此用户
        QMessageBox::about(NULL, "编辑用户", "用户不存在");
		return false;
	}

	if (! m_pSqlHelper->update_user_password(username, newPassword))
	{
		return false;
	}

	it->sPassword = newPassword;
	return true;
}

bool UserCenter::ChangRole(QString &username, int role)
{
	USER_MAP::iterator it = m_user_map.find(username);
	if (it == m_user_map.end())
	{
		//没有此用户
		return false;
	}
	
	if (! m_pSqlHelper->update_user_role(username, role))
	{
		return false;
	}
	
	it->nRole = role;
	return true;
}