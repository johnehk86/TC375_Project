#ifndef DIAGITEM
#define DIAGITEM

/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"

/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef enum
{
	E_DIAG_ID_CELLVOLT_HIGH = 0u,
	E_DIAG_ID_SOC_HIGH,
	E_DIAG_ID_MAX
} E_DIAG_INDEX;

/***********************************************************************/
/*Define*/
/***********************************************************************/
/*Diag Check Type Definition*/
#define DIAG_CHECK_HIGH_CONDITION               0x01u
#define DIAG_CHECK_LOW_CONDITION                0x02u
#define DIAG_CHECK_EQUAL_CONDITION              0x03u

/*Diag Fail-Safe Action*/
#define DIAG_FSA_NONE                           0x00u
#define DIAG_FSA_STOP                       	0x01u

/*Diag Status*/
#define DIAG_NO_ERROR                           0u
#define DIAG_TEMPORARY_ERROR                    1u
#define DIAG_CONFIRMED_ERROR                    2u

#define BCLR									0u
#define BSET									1u

/***********************************************************************/
/*External Variable*/
/***********************************************************************/


/***********************************************************************/
/*Global Function Prototype*/
/***********************************************************************/



#endif /* DRIVER_STM */
