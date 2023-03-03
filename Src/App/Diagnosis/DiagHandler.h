#ifndef DIAGHANDLER
#define DIAGHANDLER

/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"
#include "DiagManager.h"

/***********************************************************************/
/*Typedef*/
/***********************************************************************/


/***********************************************************************/
/*Define*/
/***********************************************************************/


/***********************************************************************/
/*External Variable*/
/***********************************************************************/



/***********************************************************************/
/*Global Function Prototype*/
/***********************************************************************/
extern void AppDiag_InitInsert(t_DiagItem* pDiagItem, t_DiagMembers* pDiagMembers);
extern void AppDiag_PostHandler(const t_DiagItem*  pDiagItem, const t_DiagStatus*  pDiagStatus);
extern uint8_t AppDiag_CheckEnableConditionDefault(void);
extern void AppDiag_CheckTemporaryErrorDetection(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus);
extern void AppDiag_CheckTemporaryErrorRecovery(const t_DiagItem* pDiagItem, t_DiagStatus* const pDiagStatus);

#endif /* DRIVER_STM */
