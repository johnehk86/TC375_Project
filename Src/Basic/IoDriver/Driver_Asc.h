#ifndef DRIVER_ASC
#define DRIVER_ASC

/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"
#include "IfxAsclin_Asc.h"

/***********************************************************************/
/*Define*/
/***********************************************************************/
#define ASC_TX_BUFFER_SIZE 64
#define ASC_RX_BUFFER_SIZE 64


/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef struct
{
    uint8 tx[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
    uint8 rx[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
} AppAscBuffer;

typedef struct
{
    AppAscBuffer ascBuffer;                     /**< \brief ASC interface buffer */
    struct
    {
        IfxAsclin_Asc asc0;                     /**< \brief ASC interface */
    }         drivers;

    uint8     txData[20];
    uint8     rxData[20];
    Ifx_SizeT count;
} App_AsclinAsc;


/***********************************************************************/
/*External Variable*/
/***********************************************************************/
IFX_EXTERN App_AsclinAsc g_AsclinAsc;


/***********************************************************************/
/*Global Function Prototype*/
/***********************************************************************/
extern void Driver_Asc_Init(void);
extern void Driver_Asc0_TxTest(void);


#endif /* DRIVER_STM */
