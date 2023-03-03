#ifndef DRIVER_CAN
#define DRIVER_CAN

/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Ifx_Types.h"
#include <Can/Can/IfxCan_Can.h>

/***********************************************************************/
/*Define*/
/***********************************************************************/
/*CAN0 TX ID*/
#define CAN0_ID_OBC_01_100MS                    (0x2E5u)
#define CAN0_ID_OBC_02_200MS                    (0x3B5u)
#define CAN0_ID_OBC_03_200MS                    (0x2E7u)
#define CAN0_ID_LDC_01_100MS                    (0x255u)
#define CAN0_ID_LDC_02_200MS                    (0x342u)
#define CAN0_ID_LDC_11_100MS                    (0x341u)
#define CAN0_ID_NM_OBC_100MS                    (0x56Eu)

/*CAN0 TX DEBUG ID*/
#define CAN0_ID_TX_EXT_ADD_BASE                 (0x3FF0000u)
#define CAN0_ID_DEBUG_SENS_VAL1_100MS           (CAN0_ID_TX_EXT_ADD_BASE + 0x0001u)
#define CAN0_ID_DEBUG_SENS_VAL2_100MS           (CAN0_ID_TX_EXT_ADD_BASE + 0x0002u)
#define CAN0_ID_DEBUG_SENS_VAL3_100MS           (CAN0_ID_TX_EXT_ADD_BASE + 0x0003u)
#define CAN0_ID_DEBUG_ADC_RAW1_100MS            (CAN0_ID_TX_EXT_ADD_BASE + 0x0004u)
#define CAN0_ID_DEBUG_ADC_RAW2_100MS            (CAN0_ID_TX_EXT_ADD_BASE + 0x0005u)
#define CAN0_ID_DEBUG_OBC_FAULT_100MS           (CAN0_ID_TX_EXT_ADD_BASE + 0x0006u)
#define CAN0_ID_DEBUG_LDC_FAULT_100MS           (CAN0_ID_TX_EXT_ADD_BASE + 0x0007u)
#define CAN0_ID_DEBUG_ICCU_INFO_10MS            (CAN0_ID_TX_EXT_ADD_BASE + 0x0008u)
#define CAN0_ID_DEBUG_TASK_RUNTIME_100MS        (CAN0_ID_TX_EXT_ADD_BASE + 0x000Bu)
#define CAN0_ID_DEBUG_TASK_CYCLETIME_100MS      (CAN0_ID_TX_EXT_ADD_BASE + 0x000Cu)
/* Sensor Calibration */
#define CAN0_ID_TX_EXT_ADD_BASE_2               (0x3FE0000u)
#define CAN0_ID_DEBUG_CAL_INFO_1                (CAN0_ID_TX_EXT_ADD_BASE_2 + 0x0001u)
#define CAN0_ID_DEBUG_CAL_INFO_2                (CAN0_ID_TX_EXT_ADD_BASE_2 + 0x0002u)
#define CAN0_ID_DEBUG_CAL_INFO_3                (CAN0_ID_TX_EXT_ADD_BASE_2 + 0x0003u)
#define CAN0_ID_DEBUG_CAL_INFO_4                (CAN0_ID_TX_EXT_ADD_BASE_2 + 0x0004u)

/*CAN0 RX ID*/
#define CAN0_ID_BMS_01_100MS                    (0x235u)
#define CAN0_ID_BMS_02_100MS                    (0x2FAu)
#define CAN0_ID_CCM_01_100MS                    (0x33Au)
#define CAN0_ID_CCM_02_100MS                    (0x350u)
#define CAN0_ID_ACU_02_00MS                     (0x010u)
#define CAN0_ID_CCP_OBC_RX                      (0x6ACu)
#define CAN0_ID_CLU_02_100MS                    (0x225u)
#define CAN0_ID_DATC_01_20MS                    (0x145u)
#define CAN0_ID_WHL_01_10MS                     (0x0A0u)
#define CAN0_ID_MCU_02_10MS                     (0x120u)
#define CAN0_ID_MCU_01_10MS                     (0x10Au)
#define CAN0_ID_VCMS_01_10MS                    (0x19Au)
#define CAN0_ID_VCMS_02_100MS                   (0x30Au)
#define CAN0_ID_VCU_01_10MS                     (0x035u)
#define CAN0_ID_BMS_06_100MS                    (0x325u)
#define CAN0_ID_ICU_09_200MS                    (0x419u)
#define CAN0_ID_ICU_10_200MS                    (0x410u)
#define CAN0_ID_VCU_07_100MS                    (0x357u)
#define CAN0_ID_NM_CGW_CCU                      (0x570u)

/*CAN0 RX DEBUG ID*/
#define CAN0_ID_RX_EXT_ADD_BASE                 (0x3AA0000u)
#define CAN0_ID_DEBUG_CMD                       (CAN0_ID_RX_EXT_ADD_BASE+0x0002u)

/*CAN0 RX Calibration ID*/
#define CAN0_ID_RX_EXT_ADD_BASE_02              (0x3AB0000u)
#define CAN0_ID_RX_CAL_CMD1                     (CAN0_ID_RX_EXT_ADD_BASE_02 + 0x0001u)
#define CAN0_ID_RX_CAL_CMD2                     (CAN0_ID_RX_EXT_ADD_BASE_02 + 0x0002u)

/*CAN0 RX DLC*/
#define CAN0_DLC_BMS_01_100MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_BMS_02_100MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_CCM_01_100MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_CCM_02_100MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_ACU_02_00MS                    (IfxCan_DataLengthCode_8)
#define CAN0_DLC_CLU_02_100MS                   (IfxCan_DataLengthCode_16)
#define CAN0_DLC_DATC_01_20MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_WHL_01_10MS                    (IfxCan_DataLengthCode_24)
#define CAN0_DLC_MCU_02_10MS                    (IfxCan_DataLengthCode_32)
#define CAN0_DLC_MCU_01_10MS                    (IfxCan_DataLengthCode_32)
#define CAN0_DLC_VCMS_01_10MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_VCMS_02_100MS                  (IfxCan_DataLengthCode_32)
#define CAN0_DLC_VCU_01_10MS                    (IfxCan_DataLengthCode_32)
#define CAN0_DLC_BMS_06_100MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_ICU_09_200MS                   (IfxCan_DataLengthCode_8)
#define CAN0_DLC_ICU_10_200MS                   (IfxCan_DataLengthCode_8)
#define CAN0_DLC_VCU_07_100MS                   (IfxCan_DataLengthCode_32)
#define CAN0_DLC_NM_CGW_CCU                     (IfxCan_DataLengthCode_32)


/*CAN0 RX DEBUG DLC*/
#define CAN0_DLC_DEBUG_CMD                      (IfxCan_DataLengthCode_8)
/*CAN0 RX Calibration DLC*/
#define CAN0_DLC_DEBUG_CAL_CMD1                 (IfxCan_DataLengthCode_8)
#define CAN0_DLC_DEBUG_CAL_CMD2                 (IfxCan_DataLengthCode_8)

#define CAN0_WORD                               (16u)
#define CAN0_BYTE                               (64u)

#define STANDARD_ID                             (0u)
#define EXTENDED_ID                             (1u)

/*CAN0 TX MSG BUFFER*/
#define CAN0_OBC_01_TX_MSG_BUF                  (IfxCan_TxBufferId_0)        /* Normal MSG */
#define CAN0_OBC_02_TX_MSG_BUF                  (IfxCan_TxBufferId_1)        /* Normal MSG */
#define CAN0_OBC_03_TX_MSG_BUF                  (IfxCan_TxBufferId_2)        /* Normal MSG */
#define CAN0_LDC_01_TX_MSG_BUF                  (IfxCan_TxBufferId_3)        /* Normal MSG */
#define CAN0_LDC_02_TX_MSG_BUF                  (IfxCan_TxBufferId_4)        /* Normal MSG */
#define CAN0_LDC_11_TX_MSG_BUF                  (IfxCan_TxBufferId_5)        /* Normal MSG */
#define CAN0_FAC_CAL_1_TX_MSG_BUF               (IfxCan_TxBufferId_6)        /* Normal MSG */
#define CAN0_FAC_CAL_2_TX_MSG_BUF               (IfxCan_TxBufferId_7)        /* Normal MSG */

#define CAN0_ADC_RAW_1_TX_MSG_BUF               (IfxCan_TxBufferId_10)       /* Debug MSG */
#define CAN0_ADC_RAW_2_TX_MSG_BUF               (IfxCan_TxBufferId_11)       /* Debug MSG */
#define CAN0_SENS_VAL1_TX_MSG_BUF               (IfxCan_TxBufferId_12)       /* Debug MSG */
#define CAN0_SENS_VAL2_TX_MSG_BUF               (IfxCan_TxBufferId_13)       /* Debug MSG */
#define CAN0_SENS_VAL3_TX_MSG_BUF               (IfxCan_TxBufferId_14)       /* Debug MSG */
#define CAN0_OBC_FAULT_TX_MSG_BUF               (IfxCan_TxBufferId_15)       /* Debug MSG */
#define CAN0_LDC_FAULT_TX_MSG_BUF               (IfxCan_TxBufferId_16)       /* Debug MSG */
#define CAN0_ICCU_INFO_TX_MSG_BUF               (IfxCan_TxBufferId_17)       /* Debug MSG */
#define CAN0_CAL_INFO_1_TX_MSG_BUF              (IfxCan_TxBufferId_18)       /* Debug MSG */
#define CAN0_CAL_INFO_2_TX_MSG_BUF              (IfxCan_TxBufferId_19)       /* Debug MSG */
#define CAN0_CAL_INFO_3_TX_MSG_BUF              (IfxCan_TxBufferId_20)       /* Debug MSG */
#define CAN0_CAL_INFO_4_TX_MSG_BUF              (IfxCan_TxBufferId_21)       /* Debug MSG */

#define NUM_CAN0_STD_FILTERS                    (sizeof(gstCan0StandardFilter) / sizeof(IfxCan_Filter))
#define EVENT_FIFO_BASE_ADDR                    (0xF0201700u)

/***********************************************************************/
/*Typedef*/
/***********************************************************************/
typedef struct
{
    uint32_t ulRxIndication;
    uint32_t ulTxConfirmation;
    uint32_t ulBusOffNotification;
}t_CanIsrCycleInfo;

/** \brief Can information */
typedef struct
{
    struct
    {
        IfxCan_Can can[2];             /* brief CAN handle */
        IfxCan_Can_Node canNode[2];    /* brief CAN Node handles */
    }drivers;

    Ifx_SizeT count;
} App_CanBasic;

typedef union
{
    uint32 dataWord[CAN0_WORD];
    uint8 dataByte[CAN0_BYTE];
} Can0_Msg;

typedef struct
{
    uint32_t dataWord[CAN0_WORD];
} Can0_Msg_Word;

typedef struct
{
    uint8_t dataByte[CAN0_BYTE];
} Can0_Msg_Byte;

/***********************************************************************/
/*External Variable*/
/***********************************************************************/

/***********************************************************************/
/*Global Function Prototype*/
/***********************************************************************/
extern void Driver_Can_Init(void);
extern void DrvCan0_Transmit(const uint8_t* msgData, uint32_t msgID, uint8_t bufNum, IfxCan_DataLengthCode msgDLC, uint8_t idType);
extern void DrvCan_RegisterCallbackFn(void(*fpCallback)(const uint8_t* const msgData, uint32_t msgID, uint8_t msgDLC, uint8_t msgDLCResult));
extern void DrvCan_RegTxMsgCpltCallbackFn(void(*fpCallback)(void));
extern void DrvCan_RegCanBusOffCallbackFn(void(*fpCallback)(void));
extern void DrvCan_BusOffRecovery(void);
extern void DrvCan_TxTest(void);
#endif /* DRIVER_CAN */
