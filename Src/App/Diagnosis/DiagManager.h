#ifndef DIAGMANAGER
#define DIAGMANAGER

/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"
#include "DiagItem.h"


/***********************************************************************/
/*Typedef*/
/***********************************************************************/
/*========== Diagnostic Struct ==========*/
typedef struct
{
    uint8_t ucTotalStatus;
}t_DiagData;

typedef struct
{
    E_DIAG_INDEX eDiagIndex;
    uint8_t ucDiagStatus;
    uint8_t ucEnableStatus;
    uint32_t ulDetCntTemporary;
    uint32_t ulRecCntTemporary;
    uint32_t ulDetCntConfirmed;
    uint32_t ulRecCntConfirmed;
}t_DiagStatus;

typedef struct DiagItem
{
    /*static data*/
    E_DIAG_INDEX eDiagID;
    uint8_t ucCheckConditionType;

    /* diagnosis config */
    float32_t fDetCondition;
    float32_t fRecCondition;
    uint32_t ulDetTimeCnt;
    uint32_t ulRecTimeCnt;

    /* Fail-Safe Action */
    uint8_t ucFailSafeAction;

    /* handler function */
    void (*GetCurrentData)(float32_t* a);
    void (*MainHandler)(const struct DiagItem*  a, t_DiagStatus* const b);

    /*tail link*/
    struct DiagItem* pNext;
} t_DiagItem;

typedef struct
{
    t_DiagItem* pHead;
    t_DiagItem* pTail;
}t_DiagCtrl;


typedef struct
{
    t_DiagCtrl stDiagControl;
    t_DiagData stDiagData;
    t_DiagStatus stDiagStatus[E_DIAG_ID_MAX];
}t_DiagMembers;

/***********************************************************************/
/*Define*/
/***********************************************************************/

/***********************************************************************/
/*External Variable*/
/***********************************************************************/
extern t_DiagMembers stDiagInfo;;

/***********************************************************************/
/*Global Function Prototype*/
/***********************************************************************/
extern void AppDiag_Init(void);
extern void AppDiag_Manager(void);


#endif /* DIAGMANAGER */
