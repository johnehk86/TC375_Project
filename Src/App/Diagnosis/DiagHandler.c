/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "DiagHandler.h"
#include "DiagManager.h"

/***********************************************************************/
/*Define*/
/***********************************************************************/


/***********************************************************************/
/*Typedef*/
/***********************************************************************/


/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static uint8_t AppDiag_CheckDetection(const t_DiagItem* pDiagItem);
static uint8_t AppDiag_CheckRecovery(const t_DiagItem* pDiagItem);


/***********************************************************************/
/*Variable*/
/***********************************************************************/


/***********************************************************************/
/*Function*/
/***********************************************************************/
void AppDiag_InitInsert(t_DiagItem* pDiagItem, t_DiagMembers* pDiagMembers)
{
    if (pDiagItem != NULL)
    {
        if (pDiagMembers->stDiagControl.pTail == NULL)
        {
            pDiagMembers->stDiagControl.pHead = pDiagItem;
        }
        else
        {
            pDiagMembers->stDiagControl.pTail->pNext = pDiagItem;
        }

        pDiagItem->pNext = NULL;
        pDiagMembers->stDiagControl.pTail = pDiagItem;

        pDiagMembers->stDiagStatus[pDiagItem->eDiagID].eDiagIndex = pDiagItem->eDiagID;
    }
}


void AppDiag_PostHandler(const t_DiagItem*  pDiagItem, const t_DiagStatus*  pDiagStatus)
{

}

uint8_t AppDiag_CheckEnableConditionDefault(void)
{
    uint8_t ucRtn = 0u;

	ucRtn = 1u;

    return ucRtn;
}


void AppDiag_CheckTemporaryErrorDetection(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus)
{
    if (pDiagStatus->ucDiagStatus == DIAG_NO_ERROR)
    {
        if (AppDiag_CheckDetection(pDiagItem) != BCLR)
        {
            pDiagStatus->ulDetCntTemporary++;

            if (pDiagStatus->ulDetCntTemporary >= pDiagItem->ulDetTimeCnt)
            {
                pDiagStatus->ulDetCntTemporary = 0u;
				pDiagStatus->ucDiagStatus = DIAG_TEMPORARY_ERROR;
            }
        }
        else
        {
            pDiagStatus->ulDetCntTemporary = 0u;
        }
    }
}

void AppDiag_CheckTemporaryErrorRecovery(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus)
{
    if (pDiagStatus->ucDiagStatus == DIAG_TEMPORARY_ERROR)
    {
        if (AppDiag_CheckRecovery(pDiagItem) != BCLR)
        {
            pDiagStatus->ulRecCntTemporary++;

            if (pDiagStatus->ulRecCntTemporary >= pDiagItem->ulRecTimeCnt)
            {
                pDiagStatus->ulRecCntTemporary = 0u;
				pDiagStatus->ucDiagStatus = DIAG_NO_ERROR;
            }
        }
        else
        {
            pDiagStatus->ulRecCntTemporary = 0u;
        }
    }
}

static uint8_t AppDiag_CheckDetection(const t_DiagItem* pDiagItem)
{
    uint8_t ucRtn = BCLR;
    float32_t fMeasureData = 0.0f;

    pDiagItem->GetCurrentData(&fMeasureData);

    if (pDiagItem->ucCheckConditionType == DIAG_CHECK_HIGH_CONDITION)
    {
        if(pDiagItem->fDetCondition <= fMeasureData)
        {
            ucRtn = BSET;
        }
    }
    else if (pDiagItem->ucCheckConditionType == DIAG_CHECK_LOW_CONDITION)
    {
        if(pDiagItem->fDetCondition >= fMeasureData)
        {
            ucRtn = BSET;
        }
    }
    else if (pDiagItem->ucCheckConditionType == DIAG_CHECK_EQUAL_CONDITION)
    {
        if(pDiagItem->fDetCondition <= fMeasureData)
        {
            ucRtn = BSET;
        }
    }
    else
    {
        /* Do Nothing */
    }

    return ucRtn;
}

static uint8_t AppDiag_CheckRecovery(const t_DiagItem* pDiagItem)
{
    uint8_t ucRtn = BCLR;
    float32_t fMeasureData = 0.0f;

    pDiagItem->GetCurrentData(&fMeasureData);

    if (pDiagItem->ucCheckConditionType == DIAG_CHECK_HIGH_CONDITION)
    {
        if(pDiagItem->fRecCondition >= fMeasureData)
        {
            ucRtn = BSET;
        }
    }
    else if (pDiagItem->ucCheckConditionType == DIAG_CHECK_LOW_CONDITION)
    {
        if(pDiagItem->fRecCondition <= fMeasureData)
        {
            ucRtn = BSET;
        }
    }
    else if (pDiagItem->ucCheckConditionType == DIAG_CHECK_EQUAL_CONDITION)
    {
        if(pDiagItem->fRecCondition >= fMeasureData)
        {
            ucRtn = BSET;
        }
    }
    else
    {
        /* Do Nothing */
    }

    return ucRtn;
}
