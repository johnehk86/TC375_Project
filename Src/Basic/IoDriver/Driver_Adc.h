#ifndef DRIVER_ADC
#define DRIVER_ADC

/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"
#include <Evadc/Std/IfxEvadc.h>
#include <Evadc/Adc/IfxEvadc_Adc.h>

/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef struct
{
    IfxEvadc_Adc vadc; /* VADC handle*/
    IfxEvadc_Adc_Group group0;
}t_EvadcModule;

typedef struct
{
    IfxEvadc_Adc_Channel   Channel;
    IfxEvadc_SrcNr         ServiceResNr;
    Ifx_Priority           IsrPriorityNr;
}t_EvadcChannelInfo;

typedef struct
{
/* G0 Ch0 */
    uint32_t u32nuCurrnet_Raw;
}t_ADCRawVal;

enum
{
    E_EVADC_G0_CH0_AD_BATT_CURRENT,      /* AN0, AD_BATT_CURRENT */
    E_EVADC_G0_CH1_AD_RESERVED,          /* AN1, AD_RESERVED */
    E_EVADC_G0_CH2_AD_RESERVED,          /* AN2, AD_RESERVED */
    E_EVADC_G0_CH3_AD_RESERVED,          /* AN3, AD_RESERVED */
    E_EVADC_G0_CH4_AD_RESERVED,          /* AN4, AD_RESERVED */
    E_EVADC_G0_CH5_AD_RESERVED,          /* AN5, AD_RESERVED */
    E_EVADC_G0_CH6_AD_RESERVED,          /* AN6, AD_RESERVED */
    E_EVADC_G0_CH7_AD_RESERVED,          /* AN7, AD_RESERVED */
    E_EVADC_G0_BUF_NAME_NUMBERS
}; /* E_ADCG0_BUF_NAME */


/***********************************************************************/
/*Define*/
/***********************************************************************/

/***********************************************************************/
/*External Variable*/
/***********************************************************************/
extern t_ADCRawVal stAdcRawInfo;

/***********************************************************************/
/*Global Function Prototype*/
/***********************************************************************/
extern void Driver_Adc_Init(void);
extern void Driver_Adc0_ConvStart(void);




#endif /* DRIVER_STM */
