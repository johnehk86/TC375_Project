/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Driver_Asc.h"
#include "DiagManager.h"

/***********************************************************************/
/*Define*/
/***********************************************************************/
#define ISR_PRIORITY_ASC_0_TX       53
#define ISR_PRIORITY_ASC_0_RX       55
#define ISR_PRIORITY_ASC_0_EX       51

/***********************************************************************/
/*Typedef*/
/***********************************************************************/


/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/


/***********************************************************************/
/*Variable*/
/***********************************************************************/
App_AsclinAsc g_AsclinAsc; /**< \brief Demo information */

extern float32_t fBattCurrent;
extern float32_t fAmbientTemperautre;

uint32_t u32nuNewData = 0u;
uint32_t u32nuOldData = 0u;
uint32_t aRealData[4];
uint32_t BattVoltageData;
uint32_t SocData;

float32_t fTerminalVoltage;
float32_t fSOC;


/***********************************************************************/
/*Function*/
/***********************************************************************/
IFX_INTERRUPT(ASC_Tx0IntHandler, 0, ISR_PRIORITY_ASC_0_TX);
IFX_INTERRUPT(ASC_Rx0IntHandler, 0, ISR_PRIORITY_ASC_0_RX);
IFX_INTERRUPT(ASC_Err0IntHandler, 0, ISR_PRIORITY_ASC_0_EX);

void ASC_Tx0IntHandler(void)
{
    IfxAsclin_Asc_isrTransmit(&g_AsclinAsc.drivers.asc0);
}

void ASC_Rx0IntHandler(void)
{
	static Ifx_SizeT counttemp = 1u;;
	static uint32_t u32nuFlag = 0u;

    IfxAsclin_Asc_isrReceive(&g_AsclinAsc.drivers.asc0);
    IfxAsclin_Asc_read(&g_AsclinAsc.drivers.asc0, g_AsclinAsc.rxData, &counttemp, TIME_INFINITE);
	u32nuNewData = g_AsclinAsc.rxData[0];

	if(u32nuFlag == 1u)
	{
		aRealData[0] = u32nuNewData;
		u32nuFlag = 2u;
	}
	else if(u32nuFlag == 2u)
	{
		aRealData[1] = u32nuNewData;
		BattVoltageData = (aRealData[1] << 8u) | (aRealData[0]);
		fTerminalVoltage = (float32_t)BattVoltageData/100.0f;
		u32nuFlag = 3u;
	}
	else if(u32nuFlag == 3u)
	{
		aRealData[2] = u32nuNewData;
		u32nuFlag = 4u;
	}
	else if(u32nuFlag == 4u)
	{
		aRealData[3] = u32nuNewData;
		SocData = (aRealData[3] << 8u) | (aRealData[2]);
		fSOC = (float32_t)SocData/1000.0f;
		u32nuFlag = 0u;
	}
	else
	{
		/*No Code*/
	}


	if((u32nuNewData == 10) && (u32nuOldData == 13))
	{
		u32nuFlag = 1u;
	}

	u32nuOldData = u32nuNewData;
}

void ASC_Err0IntHandler(void)
{
    IfxAsclin_Asc_isrError(&g_AsclinAsc.drivers.asc0);
}


static void Driver_Asc0_Init(void)
{
    /* create module config */
    IfxAsclin_Asc_Config ascConfig;
    IfxAsclin_Asc_initModuleConfig(&ascConfig, &MODULE_ASCLIN0);

    /* set the desired baudrate */
    ascConfig.baudrate.prescaler    = 1;
    ascConfig.baudrate.baudrate     = 115200; /* FDR values will be calculated in initModule */
    ascConfig.baudrate.oversampling = IfxAsclin_OversamplingFactor_4;
	ascConfig.frame.stopBit = IfxAsclin_StopBit_1;
    ascConfig.frame.parityBit               = TRUE;                             /* enable parity*/
    ascConfig.frame.parityType              = IfxAsclin_ParityType_even;         /* even parity (if parity enabled)*/
	ascConfig.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_2;   /* sample point position at 2*/

    /* ISR priorities and interrupt target */
    ascConfig.interrupt.txPriority    = ISR_PRIORITY_ASC_0_TX;
    ascConfig.interrupt.rxPriority    = ISR_PRIORITY_ASC_0_RX;
    ascConfig.interrupt.erPriority    = ISR_PRIORITY_ASC_0_EX;
    ascConfig.interrupt.typeOfService = (IfxSrc_Tos)IfxCpu_getCoreIndex();

    /* FIFO configuration */
    ascConfig.txBuffer     = g_AsclinAsc.ascBuffer.tx;
    ascConfig.txBufferSize = ASC_TX_BUFFER_SIZE;

    ascConfig.rxBuffer     = g_AsclinAsc.ascBuffer.rx;
    ascConfig.rxBufferSize = ASC_RX_BUFFER_SIZE;

    /* pin configuration */
    const IfxAsclin_Asc_Pins pins = {
        NULL_PTR,                     IfxPort_InputMode_pullUp,        // CTS pin not used
        &IfxAsclin0_RXB_P15_3_IN, IfxPort_InputMode_pullUp,        // Rx pin
        NULL_PTR,                     IfxPort_OutputMode_pushPull,     //RTS pin not used
        &IfxAsclin0_TX_P15_2_OUT, IfxPort_OutputMode_pushPull,     // Tx pin
        IfxPort_PadDriver_cmosAutomotiveSpeed1
    };

    ascConfig.pins = &pins;

    /* initialize module */
    IfxAsclin_Asc_initModule(&g_AsclinAsc.drivers.asc0, &ascConfig);

    g_AsclinAsc.count = 8;
}

void Driver_Asc_Init(void)
{
    Driver_Asc0_Init();
}

void Driver_Asc0_TxTest(void)
{
	float32_t fnuTemp = 0.0f;
	uint16_t u16nuTemp = 0u;

    g_AsclinAsc.count = 8;

	/*Battery Current Setting*/
	fnuTemp = (fBattCurrent + 30.0f) * 100.0f;
	u16nuTemp = (uint16_t)fnuTemp;

    g_AsclinAsc.txData[0] = (uint8_t)(u16nuTemp & 0x00FF);
    g_AsclinAsc.txData[1] = (uint8_t)((u16nuTemp & 0xFF00) >> 8);

	/*Ambient Temperautre Setting*/
	fnuTemp = (fAmbientTemperautre + 50.0f) * 10.0f;
	u16nuTemp = (uint16_t)fnuTemp;

    g_AsclinAsc.txData[2] = (uint8_t)(u16nuTemp & 0x00FF);
    g_AsclinAsc.txData[3] = (uint8_t)((u16nuTemp & 0xFF00) >> 8);

	/*Fault Result*/
	u16nuTemp = (uint16_t)stDiagInfo.stDiagStatus[E_DIAG_ID_CELLVOLT_HIGH].ucDiagStatus;

    g_AsclinAsc.txData[4] = (uint8_t)(u16nuTemp & 0x00FF);
    g_AsclinAsc.txData[5] = (uint8_t)((u16nuTemp & 0xFF00) >> 8);


	/*Terminator Setting*/
	g_AsclinAsc.txData[6] = (uint8_t)('\r');
	g_AsclinAsc.txData[7] = (uint8_t)('\n');

    /* Transmit data */
    IfxAsclin_Asc_write(&g_AsclinAsc.drivers.asc0, &g_AsclinAsc.txData[0], &g_AsclinAsc.count, TIME_INFINITE);
}

