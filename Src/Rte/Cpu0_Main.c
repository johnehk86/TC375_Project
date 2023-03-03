/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "Driver_Watchdog.h"
#include "Driver_Stm.h"
#include "Driver_Port.h"
#include "Driver_Asc.h"
#include "Driver_Adc.h"
#include "Driver_Can.h"
#include "RteScheduler.h"
#include "DiagManager.h"

/***********************************************************************/
/*Typedef*/
/***********************************************************************/

/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/


/***********************************************************************/
/*Variable*/
/***********************************************************************/

/***********************************************************************/
/*Function*/
/***********************************************************************/
int core0_main(void)
{
    /*Driver Init*/
    Driver_Watchdog_Init();
    Driver_Port_Init();
    Driver_Stm_Init();
	Driver_Asc_Init();
	Driver_Adc_Init();

Driver_Can_Init();

    /*Application Init*/
	AppDiag_Init();

    /*Global Interrupt Enable*/
    IfxCpu_enableInterrupts();

    while(1)
    {
        RteScheduler();
    }
    return (1);
}
