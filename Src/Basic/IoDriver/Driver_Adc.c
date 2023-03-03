/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Driver_Adc.h"
#include <Cpu/Std/IfxCpu.h>
#include "IfxEvadc.h"


/***********************************************************************/
/*Define*/
/***********************************************************************/
#define REQ_SRC_0                        (IfxEvadc_RequestSource_queue0)
#define ISR_PRIORITY_EVADC0_0		     150u
/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef struct
{
    uint32_t u32nuG0Sr0Cnt;
}t_AdcCycleInfo;


/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static void Driver_Adc_InitModule(void);
static void Driver_Adc0_Init(void);
static void Driver_Adc0_InitChannel(uint8_t num);
static void Driver_Adc0_DataObtain(void);

/***********************************************************************/
/*Variable*/
/***********************************************************************/
static t_EvadcModule stAdc;
t_ADCRawVal stAdcRawInfo;
t_AdcCycleInfo stAdcCycleInfo;

static t_EvadcChannelInfo group0_chInfo[E_EVADC_G0_BUF_NAME_NUMBERS] = {
/*  { {IfxVadc_ChannelId, IfxVadc_ChannelResult}, IfxVadc_SrcNr, Ifx_Priority}*/
    { {E_EVADC_G0_CH0_AD_BATT_CURRENT,       IfxEvadc_ChannelResult_0,}, IfxEvadc_SrcNr_group0, ISR_PRIORITY_EVADC0_0 }, /* AN0, AD_BATT_CURRENT */
    { {E_EVADC_G0_CH1_AD_RESERVED,           IfxEvadc_ChannelResult_1,}, IfxEvadc_SrcNr_group0, 0U }, /* AN1, AD_RESERVED */
    { {E_EVADC_G0_CH2_AD_RESERVED,           IfxEvadc_ChannelResult_2,}, IfxEvadc_SrcNr_group0, 0U }, /* AN2, AD_RESERVED */
    { {E_EVADC_G0_CH3_AD_RESERVED,           IfxEvadc_ChannelResult_3,}, IfxEvadc_SrcNr_group0, 0U }, /* AN3, AD_RESERVED */
    { {E_EVADC_G0_CH4_AD_RESERVED,           IfxEvadc_ChannelResult_4,}, IfxEvadc_SrcNr_group0, 0U }, /* AN4, AD_RESERVED */
    { {E_EVADC_G0_CH5_AD_RESERVED,           IfxEvadc_ChannelResult_5,}, IfxEvadc_SrcNr_group0, 0U }, /* AN5, AD_RESERVED */
    { {E_EVADC_G0_CH6_AD_RESERVED,           IfxEvadc_ChannelResult_6,}, IfxEvadc_SrcNr_group0, 0U }, /* AN6, AD_RESERVED */
    { {E_EVADC_G0_CH7_AD_RESERVED,           IfxEvadc_ChannelResult_7,}, IfxEvadc_SrcNr_group0, 0U }  /* AN7, AD_RESERVED */
};

/***********************************************************************/
/*Function*/
/***********************************************************************/
IFX_INTERRUPT (ADC_G0SR0IntHandler, 0, ISR_PRIORITY_EVADC0_0);

void ADC_G0SR0IntHandler(void)
{
    IfxCpu_enableInterrupts();

    stAdcCycleInfo.u32nuG0Sr0Cnt++;
	Driver_Adc0_DataObtain();
}

void Driver_Adc_Init(void)
{
	Driver_Adc_InitModule();
    Driver_Adc0_Init();
}

static void Driver_Adc_InitModule(void)
{
    /* create configuration*/
    IfxEvadc_Adc_Config adcConfig;
    IfxEvadc_Adc_initModuleConfig(&adcConfig, &MODULE_EVADC);

    adcConfig.startupCalibrationControl = IfxEvadc_StartupCalibration_initiate;

    /* initialize module */
    (void)IfxEvadc_Adc_initModule(&stAdc.vadc, &adcConfig);
}

static void Driver_Adc0_Init(void)
{
    IfxEvadc_Adc_GroupConfig adcGroupConfig;

    IfxEvadc_Adc_initGroupConfig(&adcGroupConfig, &stAdc.vadc);

    /* sampling time setting */
    adcGroupConfig.inputClass[0u].sampleTime = (float32_t)1.0E-7; /* group0 register, sampling time : 100ns */

    /* with group 0 */
    adcGroupConfig.groupId = IfxEvadc_GroupId_0;
    adcGroupConfig.master  = adcGroupConfig.groupId;
    adcGroupConfig.disablePostCalibration = TRUE;

    /* enable queue0 source */
    adcGroupConfig.arbiter.requestSlotQueue0Enabled = TRUE;
    adcGroupConfig.queueRequest[0u].requestSlotPrio = IfxEvadc_RequestSlotPriority_highest;
    adcGroupConfig.queueRequest[0u].requestSlotStartMode = IfxEvadc_RequestSlotStartMode_cancelInjectRepeat;
    adcGroupConfig.queueRequest[0u].triggerConfig.gatingMode = IfxEvadc_GatingMode_always;
    /* enable queue0 source */

    /* initialize the group*/
    (void)IfxEvadc_Adc_initGroup(&stAdc.group0, &adcGroupConfig);

    /* Queue0 scan */
    stAdc.group0.module.evadc->G[stAdc.group0.groupId].Q[REQ_SRC_0].QMR.B.ENGT = 0u;

    Driver_Adc0_InitChannel(0u);
    IfxEvadc_Adc_addToQueue(&group0_chInfo[0u].Channel, REQ_SRC_0, 0xA0u);

    /* restore previous gate config */
    stAdc.group0.module.evadc->G[stAdc.group0.groupId].Q[REQ_SRC_0].QMR.B.ENGT = 1u;
    /* Queue0 scan */
}


static void Driver_Adc0_InitChannel(uint8_t num)
{
    IfxEvadc_Adc_ChannelConfig adcChannelConfig;

    IfxEvadc_Adc_initChannelConfig(&adcChannelConfig, &stAdc.group0);

    adcChannelConfig.channelId      = group0_chInfo[num].Channel.channel;
    adcChannelConfig.resultRegister = group0_chInfo[num].Channel.resultreg;  /* use dedicated result register */
    adcChannelConfig.resultSrcNr    = group0_chInfo[num].ServiceResNr;
    adcChannelConfig.resultServProvider = IfxSrc_Tos_cpu0;
    adcChannelConfig.resultPriority = group0_chInfo[num].IsrPriorityNr;
    adcChannelConfig.inputClass     = IfxEvadc_InputClasses_group0;
    adcChannelConfig.inputClass     = IfxEvadc_InputClasses_group0;

    /* initialize the channel */
    (void)IfxEvadc_Adc_initChannel(&group0_chInfo[num].Channel, &adcChannelConfig);
}

static void Driver_Adc0_DataObtain(void)
{
	stAdcRawInfo.u32nuCurrnet_Raw = group0_chInfo[E_EVADC_G0_CH0_AD_BATT_CURRENT].Channel.group->group->RES[IfxEvadc_ChannelResult_0].B.RESULT;
}

void Driver_Adc0_ConvStart(void)
{
    IfxEvadc_startQueue(stAdc.group0.group, IfxEvadc_RequestSource_queue0);
}
