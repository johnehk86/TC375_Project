/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "DiagItem_CellVoltage.h"
#include "DiagManager.h"
#include "DiagHandler.h"

/***********************************************************************/
/*Define*/
/***********************************************************************/


/***********************************************************************/
/*Typedef*/
/***********************************************************************/


/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static void AppDiag_MainHandlerCellVoltHigh(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus);
static void AppDiag_MainHandlerSocHigh(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus);
static void AppDiag_GetCellVolt(float32_t* pGetCurrentData);
static void AppDiag_GetSoc(float32_t* pGetCurrentData);


/***********************************************************************/
/*Variable*/
/***********************************************************************/
extern float32_t fTerminalVoltage;
extern float32_t fSOC;


/***********************************************************************/
/*Function*/
/***********************************************************************/
static void AppDiag_MainHandlerCellVoltHigh(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus)
{
    if (AppDiag_CheckEnableConditionDefault() == 1u)
    {
        pDiagStatus->ucEnableStatus = 1u;
        AppDiag_CheckTemporaryErrorDetection(pDiagItem, pDiagStatus);
    }
    else
    {
        pDiagStatus->ucEnableStatus = 0u;
    }
}

static void AppDiag_MainHandlerSocHigh(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus)
{
    if (AppDiag_CheckEnableConditionDefault() == 1u)
    {
        pDiagStatus->ucEnableStatus = 1u;
        AppDiag_CheckTemporaryErrorDetection(pDiagItem, pDiagStatus);
    }
    else
    {
        pDiagStatus->ucEnableStatus = 0u;
    }
}


static void AppDiag_GetCellVolt(float32_t* pGetCurrentData)
{
    *(float32_t*)pGetCurrentData = (float32_t)fTerminalVoltage;
}

static void AppDiag_GetSoc(float32_t* pGetCurrentData)
{
    *(float32_t*)pGetCurrentData = (float32_t)fSOC;
}



void AppDiag_InitCellVoltHigh(void)
{
    static t_DiagItem stDiagInitCellVoltHigh = {
        /* static data */
        E_DIAG_ID_CELLVOLT_HIGH,                    /* E_DIAG_ID eDiagID */
        DIAG_CHECK_HIGH_CONDITION,                  /* uint8_t ucCheckConditionType */

        /* diagnosis config */
        4.7f,            							/* float32_t fDetCondition*/
        4.5f,                                       /* float32_t fRecCondition*/
        20u,                       					/* uint32_t ulDetTimeCnt */
        20u,                                        /* uint32_t ulRecTimeCnt */

        /* fail-safe action */
        DIAG_FSA_STOP,                              /* uint8_t ucFailSafeAction */

        /* handler function */
        &AppDiag_GetCellVolt,                  		/* void (*GetCurrentData)(void*) */
        &AppDiag_MainHandlerCellVoltHigh,      		/* void (*MainHandler)(struct DiagItem* const, t_DiagStatus* const) */

        /*tail link*/
        NULL                                        /* t_DiagItem* pNext */
    };

    AppDiag_InitInsert(&stDiagInitCellVoltHigh, &stDiagInfo);
}


void AppDiag_InitSocHigh(void)
{
    static t_DiagItem stDiagInitSocHigh = {
        /* static data */
        E_DIAG_ID_SOC_HIGH,                    		/* E_DIAG_ID eDiagID */
        DIAG_CHECK_HIGH_CONDITION,                  /* uint8_t ucCheckConditionType */

        /* diagnosis config */
        0.8f,            							/* float32_t fDetCondition*/
        0.7f,                                       /* float32_t fRecCondition*/
        20u,                       					/* uint32_t ulDetTimeCnt */
        20u,                                        /* uint32_t ulRecTimeCnt */

        /* fail-safe action */
        DIAG_FSA_STOP,                              /* uint8_t ucFailSafeAction */

        /* handler function */
        &AppDiag_GetSoc,                  			/* void (*GetCurrentData)(void*) */
        &AppDiag_MainHandlerSocHigh,      			/* void (*MainHandler)(struct DiagItem* const, t_DiagStatus* const) */

        /*tail link*/
        NULL                                        /* t_DiagItem* pNext */
    };

    AppDiag_InitInsert(&stDiagInitSocHigh, &stDiagInfo);
}


