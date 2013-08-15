#ifndef _CHECK_JUMP_MODE_H_
#define _CHECK_JUMP_MODE_H_

enum JUMP_MODE
{
   MANUAL_JUMP = 0,
   AUTO_JUMP = 1,
};

QMap<QString, QStringList> check_map;   //������Ҫ�ֶ���ת������
                                    //key-quesID  value-�����Ϊ0����Ϊ�˴������Զ���ת

void InitCheckJumpModeMap()
{
    // ��ѡ��keyʱΪ�ֶ���ת������Ϊ�Զ���ת
    QStringList list;
    check_map.insert("A84", list<<"1");
    list.clear();
    check_map.insert("A85", list<<"1"<<"2");
    list.clear();
    check_map.insert("A86", list<<"?"<<"1");
    list.clear();
    check_map.insert("A87", list<<"1");
    list.clear();
    check_map.insert("A138", list<<"1");
    list.clear();
    check_map.insert("A154", list<<"1");
    list.clear();
    check_map.insert("A157", list<<"?"<<"1");
    list.clear();
    check_map.insert("A173", list<<"1");
    list.clear();
    check_map.insert("A174", list<<"1");
    list.clear();
    check_map.insert("A176", list<<"1");
    list.clear();
    check_map.insert("A178", list<<"1");
    list.clear();
    check_map.insert("A179", list<<"?"<<"1");
    list.clear();
    check_map.insert("A224", list<<"1");
    list.clear();
    check_map.insert("A227", list<<"1");
    list.clear();
    check_map.insert("A228", list<<"1");
    list.clear();
    check_map.insert("A229", list<<"1");
    list.clear();
    check_map.insert("A232", list<<"*"); //*��ʾһ��Ϊ�������ֶ���ת
    list.clear();
    check_map.insert("C8", list<<"1");
    list.clear();
    check_map.insert("C23", list<<"1");
    list.clear();
    check_map.insert("C30", list<<"?"<<"1");
    list.clear();
    check_map.insert("C33", list<<"1");
    list.clear();
    check_map.insert("C35", list<<"1");
    list.clear();
    check_map.insert("C41", list<<"1");
    list.clear();
    check_map.insert("C44", list<<"1");
    list.clear();
    check_map.insert("C55", list<<"1");
    list.clear();
    check_map.insert("C56", list<<"?"<<"1");
    list.clear();
    check_map.insert("C57", list<<"1");
    list.clear();
    check_map.insert("C58", list<<"1");
    list.clear();
    check_map.insert("C61", list<<"*");
    list.clear();
    check_map.insert("D34", list<<"*");
    list.clear();
    check_map.insert("E10", list<<"1"<<"3");
    list.clear();
    check_map.insert("E18", list<<"1");
    list.clear();
    check_map.insert("G70", list<<"3");
    list.clear();
}

JUMP_MODE CheckJumpMode(QString& strQuesID, QString& strAnswer)
{
    QMap<QString, QStringList>::iterator it =  check_map.find(strQuesID);
    if (it != check_map.end())
    {
        if((it->size()) > 0 && ("*" == it->at(0)))
        {
            return MANUAL_JUMP;
        }

        if (-1 != it->indexOf(strAnswer))
        {
            return MANUAL_JUMP;
        }
    }
    return AUTO_JUMP;
}
#endif