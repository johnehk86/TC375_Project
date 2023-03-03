/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "RteScheduler.h"
#include "Driver_Stm.h"
#include "Driver_Asc.h"
#include "Driver_Adc.h"
#include "Driver_Can.h"
#include "SensorHandler.h"
#include "DiagManager.h"

/***********************************************************************/
/*Define*/
/***********************************************************************/

/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef struct
{
    uint32_t u32nuCnt1ms;
    uint32_t u32nuCnt10ms;
    uint32_t u32nuCnt100ms;
}TestCnt;


/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static void RteTask1ms(void);
static void RteTask10ms(void);
static void RteTask100ms(void);

/***********************************************************************/
/*Variable*/
/***********************************************************************/
TestCnt stTestCnt;

/***********************************************************************/
/*Function*/
/***********************************************************************/
static void RteTask1ms(void)
{
    stTestCnt.u32nuCnt1ms++;
	Driver_Adc0_ConvStart();
	Unit_SensorHandler();
}

static void RteTask10ms(void)
{
    stTestCnt.u32nuCnt10ms++;
	Driver_Asc0_TxTest();

	AppDiag_Manager();
	DrvCan_TxTest();
}

static void RteTask100ms(void)
{
    stTestCnt.u32nuCnt100ms++;
}


void RteScheduler(void)
{
    if(stRteSchedulerInfo.u8nuRteScheduler1msFlag == 1u)
    {
        stRteSchedulerInfo.u8nuRteScheduler1msFlag = 0u;
        RteTask1ms();

        if(stRteSchedulerInfo.u8nuRteScheduler10msFlag == 1u)
        {
            stRteSchedulerInfo.u8nuRteScheduler10msFlag = 0u;
            RteTask10ms();
        }

        if(stRteSchedulerInfo.u8nuRteScheduler100msFlag == 1u)
        {
            stRteSchedulerInfo.u8nuRteScheduler100msFlag = 0u;
            RteTask100ms();
        }
    }
}
