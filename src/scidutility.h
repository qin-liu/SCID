#ifndef _INSPECTUTILITY_H_
#define _INSPECTUTILITY_H_

#define SAFE_DELETE(p) { if (p) delete p; p = NULL; }
#define SAFE_DELETE_ARRAY(p) { if(p) delete []p; p = NULL; }

static inline QString GetGroupId(QString &quesName)
{
	if (! quesName.isNull())
	{
		return quesName.at(0);
	}
	return QString();
}

static inline int TransStrToIntID(QString &quesName)
{
	if (quesName.isEmpty())
	{
		return -1;
	}

    //生成groupID*1000 + quesIndex 的一个值 用于排序
    int nGroupInt = 0;
    if (GetGroupId(quesName) == "P")
    {
        //P为概述，放在第一组,使其值等于A-2
        char A = 'A';
        nGroupInt = ((int)(A)-2)*1000;
    }
    else if(GetGroupId(quesName) == "S")
    {
        //S放在第二组,使其值等于A-1
        char A = 'A';
        nGroupInt = ((int)(A)-1)*1000;
    }
    else
    {
        nGroupInt = (int)(*GetGroupId(quesName).toAscii().constData())*1000;
    }
	return nGroupInt + quesName.right(quesName.length()-1).toInt();
}

static inline QString TransIntIDToStr(int nID)
{
    QString strGroup; 
    QString strIndex;
    int nFirstChar = nID/1000;
    int nIndex = nID - nFirstChar*1000;
    
    if (nFirstChar == ((int)('A') - 1))
    {
        //P
        strGroup = "P";
    }
    else if (nFirstChar == ((int)('A') - 2))
    {
        strGroup = "S";
    }
    else
    {
        strGroup = (char)nFirstChar;
    }

    strIndex = QString::number(nIndex);
    return strGroup+strIndex;
}
#endif