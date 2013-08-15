#ifndef _STATISTICS_JUMP_FUNCTION_H_
#define _STATISTICS_JUMP_FUNCTION_H_
#include "AnswerCenter.h"

QString STA_A24(AnswerCenter *pAnswer, int nSaveIndex)
{
    bool A1_or_A2 = false;
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A1"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        A1_or_A2 = true;
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A2"), answer))
    {
        A1_or_A2 = true;
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A3"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A9"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A12"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A13"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A19"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (nSelect_3_Count >= 5 && A1_or_A2)
    {
//        QMessageBox::warning("自动跳转", "A24自动跳转");
        return "3";
    }
    return "1";
};

QString STA_A28(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString bRet = false;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A24"), answer))
    {
        return "1";
    }
    if (answer != "3")
    {
        return "1";
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A25"), answer))
    {
        return "1";
    }
    if (answer != "3")
    {
        return "1";
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A26"), answer))
    {
        return "1";
    }
    if (answer != "3")
    {
        return "1";
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A27"), answer))
    {
        return "1";
    }
    if (answer != "3")
    {
        return "1";
    }
    return "3";
}

QString STA_A41(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A30"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A30"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A31"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A33"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A35"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A37"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A39"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
}

QString STA_A50(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A44"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A44"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A45"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A46"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A47"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A48"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A49"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_A51(AnswerCenter *pAnswer, int nSaveIndex)
{
    bool A42_OR_A43 = false;
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A42"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        A42_OR_A43 = true;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A43"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        A42_OR_A43 = true;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A50"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 1 && A42_OR_A43)
    {
        return "3";
    }
    return "1";
}

QString STA_A58(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A54"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A55"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A56"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A57"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
}

QString STA_A60(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A53"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A58"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A59"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if(nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_A84(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    bool sel_A61_A62 = false;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A61"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        sel_A61_A62 = true;
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A62"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        sel_A61_A62 = true;
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A63"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A66"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A69"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A72"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A73"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A76"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A79"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count>=5 && sel_A61_A62)
    {
        return "3";
    }
    return "1";
}

QString STA_A88(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A84"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A85"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A86"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A87"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_A105(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A96"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A97"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A98"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A99"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A100"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A101"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A104"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_A109(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A92"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A105"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A106"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A108"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_A121(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A112"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A114"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A116"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A118"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A120"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
}

QString STA_A135(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A126"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A127"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A128"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A129"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A130"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A131"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A134"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}


QString STA_A140(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A123"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A135"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A136"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A137"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A138"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A139"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}


QString STA_A154(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A145"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A146"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A147"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A148"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A149"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A150"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A153"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_A158(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A141"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A154"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A155"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A157"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_A173(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A164"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A165"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A166"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A167"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A168"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A169"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A172"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_A180(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A161"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A173"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A174"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A176"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A178"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A179"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_A200(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A194"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A195"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A196"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A197"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A198"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A199"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
}



QString STA_A208(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A184"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A200"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A201"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A202"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A204"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A205"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A206"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A207"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 8)
    {
        return "3";
    }
    return "1";
}

QString STA_A215(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A211"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A212"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A213"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A214"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
}

QString STA_A216(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A210"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("A215"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
}

QString STA_C29(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("C25"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("C26"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("C27"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("C28"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";     
}

QString STA_E10(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E7"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E8"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E9"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 1)
    {
        return "3";
    }
    return "1";
}

QString STA_E18(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E11"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E12"), answer))
    {
        return "1"; 
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E13"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E14"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E15"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E17"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_E65(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E34"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E39"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E44"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E49"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E54"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E59"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("E64"), answer))
    {
        return "1";
    }
    if (answer == "3" || answer == "2")
    {
        return "3";
    }
    return "1";
}

QString STA_F18(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F5"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F7"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F8"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F9"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F10"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F11"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F12"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F13"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F14"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F15"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F17"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_F24(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F21"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F22"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F23"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_F43(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F32"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F41"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F42"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_F67(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F52"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F59"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F60"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F61"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F62"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F63"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F64"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F66"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 8)
    {
        return "3";
    }
    return "1";
}

QString STA_F81(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F74"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F75"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F76"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F76"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F76"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F76"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F77"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F78"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F79"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F80"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 7)
    {
        return "3";
    }
    return "1";
}


QString STA_F107(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F93"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F94"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F95"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F96"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F102"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F104"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F105"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F106"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 8)
    {
        return "3";
    }
    return "1";
}


QString STA_F150(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F145"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F146"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F147"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F148"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F149"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 1)
    {
        return "3";
    }
    return "1";
}


QString STA_F158(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F151"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F152"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F153"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F154"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F155"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F156"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F157"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    return QString::number(nSelect_3_Count);
}

QString STA_F164(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F159"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F160"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F161"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F162"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F163"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    return QString::number(nSelect_3_Count);
}

QString STA_F167(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F143"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F144"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F150"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F158"), answer))
    {
        return "1";
    }
    if (answer >= "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F164"), answer))
    {
        return "1";
    }
    if (answer >= "2")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F150"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_F184(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F178"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F179"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F180"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F181"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F182"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F183"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_F188(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F175"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F176"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F177"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F184"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F185"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F186"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_G18(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G5"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G7"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G8"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G9"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G10"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G11"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G12"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G13"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G14"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G15"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G17"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 1)
    {
        return "3";
    }
    return "1";
}

QString STA_G30(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G19"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G20"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G21"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G22"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G23"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G24"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G25"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G26"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G27"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G28"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G29"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_G36(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G31"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G32"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G33"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G34"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G35"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 2)
    {
        return "3";
    }
    return "1";
} 

QString STA_G42(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G37"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G38"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G39"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G40"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G41"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 1)
    {
        return "3";
    }
    return "1";
}

QString STA_G43(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G3"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G18"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G36"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G42"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_G49(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G44"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G45"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G46"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G47"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G48"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_G61(AnswerCenter *pAnswer, int nSaveIndex)
{
    bool B1_OR_B2 = false;
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G53"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G54"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        B1_OR_B2 = true;
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G55"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        if (! B1_OR_B2)
        {
            B1_OR_B2 = true;
            nSelect_3_Count++;
        }
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G56"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G57"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G59"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G60"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_G70(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G62"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G64"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G65"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G66"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G67"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G69"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_G75(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G72"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G73"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("G74"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_H6(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H2"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H3"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H4"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_H21(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H15"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H17"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H18"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H19"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H20"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_H33(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H28"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H29"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H30"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H31"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H32"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_H37(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H33"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H34"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H35"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("H36"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_I8(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("I2"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("I4"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("I5"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("I6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("I7"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_J6(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J1"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J2"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J3"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J4"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J5"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_J13(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J8"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J9"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J10"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J11"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J12"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F143"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("F144"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 8)
    {
        return "3";
    }
    return "1";
}

QString STA_J23(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J17"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J18"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J19"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J20"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J21"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J22"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 7)
    {
        return "3";
    }
    return "1";
}

QString STA_J37(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J27"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J28"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J29"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J30"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J31"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J32"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J33"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J34"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J35"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J36"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 4)
    {
        return "3";
    }
    return "1";
}

QString STA_J41(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J26"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J37"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J38"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J39"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("J40"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_K12(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K2"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K3"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K4"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K5"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K6"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K7"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K8"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K9"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K10"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K11"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_K19(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K16"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K17"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K18"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_K32(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K23"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K24"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K25"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K26"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K27"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K28"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K29"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K30"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K31"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_K42(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K33"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K34"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K35"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K36"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K37"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K38"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K39"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K40"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K41"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 6)
    {
        return "3";
    }
    return "1";
}

QString STA_K43(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K32"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K42"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (nSelect_3_Count >= 1)
    {
        return "3";
    }
    return "1";
}

QString STA_K48(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K43"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K44"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K45"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K46"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K47"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 5)
    {
        return "3";
    }
    return "1";
}

QString STA_K68(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K53"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K54"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K55"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K56"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K57"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K58"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K59"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K60"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K61"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K62"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K63"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K64"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K65"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K66"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K67"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }

    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_K81(AnswerCenter *pAnswer, int nSaveIndex)
{
    int nSelect_3_Count = 0;
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K73"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K74"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K75"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K76"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K77"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K78"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K79"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("K80"), answer))
    {
        return "1";
    }
    if (answer == "3")
    {
        nSelect_3_Count++;
    }
    if (nSelect_3_Count >= 3)
    {
        return "3";
    }
    return "1";
}

QString STA_E1(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S1"), answer))
    {
        return "?";
    }
    
    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_E29(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer1 = "?";
    QString answer2 = "?";

    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S2"), answer1))
    {
        return "?";
    }
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S3"), answer2))
    {
        return "?";
    }

    if (answer1 == "1" && answer2 == "1")
    {
        return "1";
    }
    return "3";
}

QString STA_F1(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S4"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_F31(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S5"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_F51(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S6"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_F73(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S7"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_F174(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S10"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_H1(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S11"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}

QString STA_H14(AnswerCenter *pAnswer, int nSaveIndex)
{
    QString answer;
    if (! pAnswer->QueryAnswerOfQuestion(nSaveIndex, QString("S12"), answer))
    {
        return "?";
    }

    if (answer == "1")
    {
        return "1";
    }

    if (answer == "2" || answer == "3")
    {
        return "3";
    }
    return "?";
}


//==================
typedef QString (*STA_FUN)(AnswerCenter *pAnswer, int nSaveIndex);
QMap<QString, STA_FUN> sta_func_map;

void InitSTAFucMap()
{
    sta_func_map.insert("A24", STA_A24);
    sta_func_map.insert("A28", STA_A28);
    sta_func_map.insert("A41", STA_A41);
    sta_func_map.insert("A50", STA_A50);
    sta_func_map.insert("A51", STA_A51);
    sta_func_map.insert("A58", STA_A58);
    sta_func_map.insert("A60", STA_A60);
    sta_func_map.insert("A84", STA_A84);
    sta_func_map.insert("A88", STA_A88);
    sta_func_map.insert("A105", STA_A105);
    sta_func_map.insert("A109", STA_A109);
    sta_func_map.insert("A121", STA_A121);
    sta_func_map.insert("A135", STA_A135);
    sta_func_map.insert("A140", STA_A140);
    sta_func_map.insert("A154", STA_A158);
    sta_func_map.insert("A173", STA_A173);
    sta_func_map.insert("A180", STA_A180);
    sta_func_map.insert("A200", STA_A200);
    sta_func_map.insert("A208", STA_A208);
    sta_func_map.insert("A215", STA_A215);
    sta_func_map.insert("A216", STA_A216);
    sta_func_map.insert("C29", STA_C29);
    sta_func_map.insert("E10", STA_E10);
    sta_func_map.insert("E18", STA_E18);
    sta_func_map.insert("E65", STA_E65);
    sta_func_map.insert("F18", STA_F18);
    sta_func_map.insert("F24", STA_F24);
    sta_func_map.insert("F43", STA_F43);
    sta_func_map.insert("F67", STA_F67);
    sta_func_map.insert("F81", STA_F81);
    sta_func_map.insert("F107", STA_F107);
    sta_func_map.insert("F150", STA_F150);
    sta_func_map.insert("F158", STA_F158);
    sta_func_map.insert("F164", STA_F164);
    sta_func_map.insert("F167", STA_F167);
    sta_func_map.insert("F184", STA_F184);
    sta_func_map.insert("F188", STA_F188);
    sta_func_map.insert("G18", STA_G18);
    sta_func_map.insert("G30", STA_G30);
    sta_func_map.insert("G36", STA_G36);
    sta_func_map.insert("G42", STA_G42);
    sta_func_map.insert("G43", STA_G43);
    sta_func_map.insert("G49", STA_G49);
    sta_func_map.insert("G61", STA_G61);
    sta_func_map.insert("G70", STA_G70);
    sta_func_map.insert("G75", STA_G75);
    sta_func_map.insert("H6", STA_H6);
    sta_func_map.insert("H21", STA_H21);
    sta_func_map.insert("H33", STA_H33);
    sta_func_map.insert("H37", STA_H37);
    sta_func_map.insert("I8", STA_I8);
    sta_func_map.insert("J6", STA_J6);
    sta_func_map.insert("J13", STA_J13);
    sta_func_map.insert("J23", STA_J23);
    sta_func_map.insert("J37", STA_J37);
    sta_func_map.insert("J41", STA_J41);
    sta_func_map.insert("K12", STA_K12);
    sta_func_map.insert("K19", STA_K19);
    sta_func_map.insert("K32", STA_K32);
    sta_func_map.insert("K42", STA_K42);
    sta_func_map.insert("K43", STA_K43);
    sta_func_map.insert("K48", STA_K48);
    sta_func_map.insert("K68", STA_K68);
    sta_func_map.insert("K81", STA_K81);


    sta_func_map.insert("E1", STA_E1);
    sta_func_map.insert("E29", STA_E29);
    sta_func_map.insert("F1", STA_F1);
    sta_func_map.insert("F31", STA_F31);
    sta_func_map.insert("F51", STA_F51);
    sta_func_map.insert("F73", STA_F73);
    sta_func_map.insert("F174", STA_F174);
    sta_func_map.insert("H1", STA_H1);
    sta_func_map.insert("H14", STA_H14);
}


bool GetStaticAnswer(QString &quesID, AnswerCenter *pAnswer, int nSaveIndex, QString &answer)
{
    QMap<QString, STA_FUN>::iterator it = sta_func_map.find(quesID);
    if (it == sta_func_map.end())
    {
        return false;
    }

    STA_FUN func = it.value();
    answer = func(pAnswer, nSaveIndex);
    return true; //继续做下题
}


#endif