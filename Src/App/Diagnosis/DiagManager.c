/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "DiagManager.h"
#include "DiagHandler.h"
#include "DiagItem_CellVoltage.h"


/***********************************************************************/
/*Define*/
/***********************************************************************/

/***********************************************************************/
/*Typedef*/
/***********************************************************************/

/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static void AppDiag_InitItem(void);

/***********************************************************************/
/*Variable*/
/***********************************************************************/
t_DiagMembers stDiagInfo;

/***********************************************************************/
/*Function*/
/***********************************************************************/
void AppDiag_Init(void)
{
    AppDiag_InitItem();
}

void AppDiag_Manager(void)
{
    const t_DiagItem* pDiagItem = NULL;

	pDiagItem = stDiagInfo.stDiagControl.pHead;

    while(pDiagItem != NULL)
	{
		pDiagItem->MainHandler(pDiagItem, &stDiagInfo.stDiagStatus[pDiagItem->eDiagID]);
		pDiagItem = pDiagItem->pNext;
	}
}

static void AppDiag_InitItem(void)
{
	AppDiag_InitCellVoltHigh();
	AppDiag_InitSocHigh();
}

