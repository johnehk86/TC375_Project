/***********************************************************************/
/*Include*/
/***********************************************************************/
#include "Driver_Can.h"
#include "IfxCpu.h"
#include "Cpu/Irq/IfxCpu_Irq.h"
#include <string.h>
#include "IfxPort.h"
#include "IfxPort_PinMap.h"


/***********************************************************************/
/*Define*/
/***********************************************************************/
#define ISR_PRIORITY_CAN0_RX		20u
#define ISR_PRIORITY_CAN0_TX		19u
#define ISR_PRIORITY_CAN0_BUSOFF	18u

/***********************************************************************/
/*Typedef*/
/***********************************************************************/


/***********************************************************************/
/*Static Function Prototype*/
/***********************************************************************/
static void DrvCan_InitCan0(void);
static void DrvCan0_Recieve(void);
static uint32_t DrvCan_NewDataReceived(const IfxCan_Can_Node *node, uint8_t rxBufferId);
static void(*DrvCAN_ReceiveMsgCan0Callback)(const uint8_t* const msgData, uint32_t msgID, uint8_t msgDLC, uint8_t msgDLCResult) = (void*)0;
static void(*DrvCAN_TxMsgCpltCallback)(void) = (void*)0;
static void(*DrvCAN_CanBusOffNotiCallback)(void) = (void*)0;


/***********************************************************************/
/*Variable*/
/***********************************************************************/
static App_CanBasic gstCanBasic;
static uint8_t gucCan0TxStop;

/* Filter configurations */
static IfxCan_Filter gstCan0StandardFilter[] =
{
        {  0, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_BMS_01_100MS,        0x00,    IfxCan_RxBufferId_0},
        {  1, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_BMS_02_100MS,        0x00,    IfxCan_RxBufferId_1},
        {  2, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_CCM_01_100MS,        0x00,    IfxCan_RxBufferId_2},
        {  3, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_CCM_02_100MS,        0x00,    IfxCan_RxBufferId_3},
        {  4, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_ACU_02_00MS,         0x00,    IfxCan_RxBufferId_4},
        {  5, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_CLU_02_100MS,        0x00,    IfxCan_RxBufferId_5},
        {  6, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_DATC_01_20MS,        0x00,    IfxCan_RxBufferId_6},
        {  7, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_WHL_01_10MS,         0x00,    IfxCan_RxBufferId_7},
        {  8, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_MCU_02_10MS,         0x00,    IfxCan_RxBufferId_8},
        {  9, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_MCU_01_10MS,         0x00,    IfxCan_RxBufferId_9},
        { 10, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_VCMS_01_10MS,        0x00,    IfxCan_RxBufferId_10},
        { 11, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_VCMS_02_100MS,       0x00,    IfxCan_RxBufferId_11},
        { 12, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_VCU_01_10MS,         0x00,    IfxCan_RxBufferId_12},
        { 13, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_BMS_06_100MS,        0x00,    IfxCan_RxBufferId_13},
        { 14, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_ICU_09_200MS,        0x00,    IfxCan_RxBufferId_14},
        { 15, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_ICU_10_200MS,        0x00,    IfxCan_RxBufferId_15},
        { 16, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_VCU_07_100MS,        0x00,    IfxCan_RxBufferId_16},
        { 17, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_NM_CGW_CCU,          0x00,    IfxCan_RxBufferId_17},
        { 18, IfxCan_FilterElementConfiguration_storeInRxBuffer,    IfxCan_FilterType_none,    CAN0_ID_CCP_OBC_RX,          0x00,    IfxCan_RxBufferId_18}
};


static uint8_t gstCan0StandardFilterDlc[] =
{
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_8,
	IfxCan_DataLengthCode_16,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_24,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_8,
	IfxCan_DataLengthCode_8,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_32,
	IfxCan_DataLengthCode_8
};


/***********************************************************************/
/*Function*/
/***********************************************************************/
/***************************** ISR Declaration******************************/
IFX_INTERRUPT(Isr_Can0_RxIndication, 0, ISR_PRIORITY_CAN0_RX);
IFX_INTERRUPT(Isr_Can0_TxConfirmation, 0, ISR_PRIORITY_CAN0_TX);
IFX_INTERRUPT(Isr_Can0_BusOffNotification, 0, ISR_PRIORITY_CAN0_BUSOFF);


/***************************** ISR Functions********************************/
void Isr_Can0_RxIndication(void)
{
    Ifx_CAN   *canSfr =  &MODULE_CAN0;

    IfxCpu_enableInterrupts();

    if(CAN0_IR0.B.DRX == 1)
    {
        Ifx_CAN_N *nodeSfr = IfxCan_getNodePointer(canSfr,IfxCan_NodeId_0);
        IfxCan_Node_clearInterruptFlag(nodeSfr,IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);

        /*Read Recieved Message from CAN0*/
        DrvCan0_Recieve();
    }
}

void Isr_Can0_TxConfirmation(void)
{
    Ifx_CAN *canSfr = &MODULE_CAN0;
    Ifx_CAN_N *nodeSfr = IfxCan_getNodePointer(canSfr,IfxCan_NodeId_0);

    IfxCpu_enableInterrupts();
    IfxCan_Node_clearInterruptFlag(nodeSfr,IfxCan_Interrupt_transmissionCompleted); /*Transmission Completed Interrupt Clear*/
}

void Isr_Can0_BusOffNotification(void)
{
    IfxCpu_enableInterrupts();
}

/***************************** Driver API Functions********************************/
void DrvCan_RegisterCallbackFn(void(*fpCallback)(const uint8_t* const msgData, uint32_t msgID, uint8_t msgDLC, uint8_t msgDLCResult))
{
    DrvCAN_ReceiveMsgCan0Callback = fpCallback;
}

void DrvCan_RegTxMsgCpltCallbackFn(void(*fpCallback)(void))
{
    DrvCAN_TxMsgCpltCallback = fpCallback;
}

void DrvCan_RegCanBusOffCallbackFn(void(*fpCallback)(void))
{
    DrvCAN_CanBusOffNotiCallback = fpCallback;
}

static void DrvCan0_Recieve(void)
{
    IfxCan_Message stCanRxMsg;
    Can0_Msg_Word stCan0RxDataWord;
    Can0_Msg_Byte stCan0RxDataByte;

    uint8_t ucFltNum = 0u;
    uint32_t ulResult = 0u;
    uint8_t ucDlcResult = 0u;

    IfxCan_Can_initMessage(&stCanRxMsg);
    stCanRxMsg.frameMode = IfxCan_FrameMode_fdLongAndFast;

    for(ucFltNum=0; ucFltNum < NUM_CAN0_STD_FILTERS; ucFltNum++)
    {
        ulResult = DrvCan_NewDataReceived(&gstCanBasic.drivers.canNode[0], ucFltNum);

        if(ulResult != 0u)
        {
            /*read message*/
            stCanRxMsg.bufferNumber = ucFltNum;
            IfxCan_Can_readMessage(&gstCanBasic.drivers.canNode[0], &stCanRxMsg, stCan0RxDataWord.dataWord);

            (void)memcpy(stCan0RxDataByte.dataByte,(uint8_t*)stCan0RxDataWord.dataWord,sizeof(stCan0RxDataByte.dataByte));

            /*DLC Inspection*/

            if(ucFltNum < NUM_CAN0_STD_FILTERS)
            {
                if(gstCan0StandardFilterDlc[ucFltNum] == stCanRxMsg.dataLengthCode)
                {
                    ucDlcResult = 1u;
                }
            }
            else
            {
                ucDlcResult = 1u;
            }

            /*Recieve Callback*/
            DrvCAN_ReceiveMsgCan0Callback(&stCan0RxDataByte.dataByte[0], stCanRxMsg.messageId, stCanRxMsg.dataLengthCode, ucDlcResult);
        }
    }
}

void DrvCan0_Transmit(const uint8_t* msgData, uint32_t msgID, uint8_t bufNum, IfxCan_DataLengthCode msgDLC, uint8_t idType)
{
    IfxCan_Message stCan0TxMsg;
    Can0_Msg_Word stCan0TxData;
    IfxCan_Status stStatus;

    /*Init TxMsg*/
    IfxCan_Can_initMessage(&stCan0TxMsg);

    stCan0TxMsg.messageId = msgID;
    stCan0TxMsg.bufferNumber = bufNum;

    if(bufNum <= (uint8_t)CAN0_LDC_11_TX_MSG_BUF)
    {
        stCan0TxMsg.txEventFifoControl = TRUE;
    }

    stCan0TxMsg.dataLengthCode = msgDLC;
    stCan0TxMsg.frameMode = IfxCan_FrameMode_fdLongAndFast;
    if(idType == EXTENDED_ID)
    {
        stCan0TxMsg.messageIdLength = IfxCan_MessageIdLength_extended;
    }
    else
    {
        stCan0TxMsg.messageIdLength = IfxCan_MessageIdLength_standard;
    }

    (void)memcpy(stCan0TxData.dataWord, (const uint32_t*)msgData, sizeof(stCan0TxData.dataWord));

    if(gucCan0TxStop == 0u)
    {
        stStatus = IfxCan_Can_sendMessage(&gstCanBasic.drivers.canNode[0], &stCan0TxMsg, stCan0TxData.dataWord);
    }
}

void Driver_Can_Init(void)
{
    /*CAN0 Module Init*/
    DrvCan_InitCan0();

    /*CAN0 Tranceiver Enable (Low)*/
	IfxPort_setPinLow(IfxPort_P20_6.port, IfxPort_P20_6.pinIndex);
}

static void DrvCan_InitCan0(void)
{
    uint8_t ucFltNum = 0u;

    /* disable interrupts */
    boolean interruptState = IfxCpu_disableInterrupts();

    /* CAN0 initilaisation */
    {
        /* create module configuration */
        IfxCan_Can_Config canConfig;
        IfxCan_Can_initModuleConfig(&canConfig, &MODULE_CAN0);

        /* initialize module */
        IfxCan_Can_initModule(&gstCanBasic.drivers.can[0], &canConfig);
    }

    /*create node configuration*/
    /*CAN0 Node0 Initialization*/
    {
        IfxCan_Can_NodeConfig nodeConfig;
        IfxCan_Can_initNodeConfig(&nodeConfig, &gstCanBasic.drivers.can[0]);

        nodeConfig.nodeId = IfxCan_NodeId_0;
        nodeConfig.frame.type = IfxCan_FrameType_transmitAndReceive;
        nodeConfig.txConfig.dedicatedTxBuffersNumber = 32u;
        nodeConfig.txConfig.txEventFifoSize = 32u;

        nodeConfig.frame.mode = IfxCan_FrameMode_fdLongAndFast;
        nodeConfig.txConfig.txBufferDataFieldSize = IfxCan_DataFieldSize_64;
        nodeConfig.rxConfig.rxBufferDataFieldSize = IfxCan_DataFieldSize_64;

        nodeConfig.messageRAM.standardFilterListStartAddress = 0x100u;
        nodeConfig.messageRAM.extendedFilterListStartAddress = 0x300u;
        nodeConfig.messageRAM.rxBuffersStartAddress          = 0x500u;
        nodeConfig.messageRAM.txEventFifoStartAddress        = 0x1700u;
        nodeConfig.messageRAM.txBuffersStartAddress          = 0x1900u;
        nodeConfig.messageRAM.baseAddress                    = (uint32)&MODULE_CAN0;

        /* Filter config to List Size*/
        nodeConfig.filterConfig.messageIdLength = IfxCan_MessageIdLength_both;
        nodeConfig.filterConfig.standardListSize = NUM_CAN0_STD_FILTERS;

        IfxCan_Can_Pins pins;

        pins.rxPin = &IfxCan_RXD00B_P20_7_IN;
        pins.rxPinMode = IfxPort_InputMode_pullUp;
        pins.txPin = &IfxCan_TXD00_P20_8_OUT;
        pins.txPinMode = IfxPort_OutputMode_pushPull;
        pins.padDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1;
        nodeConfig.pins = &pins;

        /* For interrupt configuration user needs to configure the priority and select one of the 16 interrupt lines*/
        nodeConfig.interruptConfig.reint.priority = ISR_PRIORITY_CAN0_RX;
        nodeConfig.interruptConfig.reint.interruptLine = IfxCan_InterruptLine_14;
        nodeConfig.interruptConfig.reint.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

        nodeConfig.interruptConfig.traco.priority = ISR_PRIORITY_CAN0_TX;
        nodeConfig.interruptConfig.traco.interruptLine = IfxCan_InterruptLine_15;
        nodeConfig.interruptConfig.traco.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

        nodeConfig.interruptConfig.boff.priority = ISR_PRIORITY_CAN0_BUSOFF;
        nodeConfig.interruptConfig.boff.interruptLine = IfxCan_InterruptLine_6;
        nodeConfig.interruptConfig.boff.typeOfService = IfxCpu_Irq_getTos(IfxCpu_getCoreIndex());

        /*initialize module*/
        (void)IfxCan_Can_initNode(&gstCanBasic.drivers.canNode[0], &nodeConfig);

        Ifx_CAN_N *nodeSfr = IfxCan_getNodePointer(gstCanBasic.drivers.canNode[0].can, nodeConfig.nodeId);

        IfxCan_Node_enableConfigurationChange(nodeSfr);

        /* Arbitration Phase Bit Timing                                 */
        /* 1. CAN0 Normal Baud Rate : 500Kbps                           */
        /*  - Tq = (NBRP + 1)/fCAN                                      */
        /*  - Tq = 2/80MHz = 25ns                                       */
        /*  - Tsync =  1 x Tq = 25ns                                    */
        /*  - Tseg1 =  (NTSEG1 + 1) x Tq = (62 + 1) x 25ns = 1575ns     */
        /*  - Tseg2 =  (NTSEG2 + 1) x Tq = (15 + 1) x 25ns = 400ns      */
        /*  - bit time = Tsync + Tseg1 + Tseg2 = 2000ns = 2us (500Kbps) */
        /* 2. CAN0 Normal Sampling Point: 80%                           */
        /*  - Sampling Point = (1 + Tseg1)/(1 + Tseg1 + Tseg2) x 100    */
        /*                   = (1 + 63) / (1 + 63 + 16) x 100 = 80%     */
        CAN0_NBTP0.B.NTSEG1 = 63u-1u;
        CAN0_NBTP0.B.NTSEG2 = 16u-1u;
        CAN0_NBTP0.B.NSJW = 16u;
        CAN0_NBTP0.B.NBRP = 2u-1u;

        /* Data Phase Bit Timing */
        /* 1. CAN0 Normal Baud Rate : 2Mbps                             */
        /*  - Tq = (DBRP + 1)/fCAN                                      */
        /*  - Tq = 2/80MHz = 25ns                                       */
        /*  - Tsync =  1 x Tq = 25ns                                    */
        /*  - Tseg1 =  (DTSEG1 + 1) x Tq = (13 + 1) x 25ns = 350ns      */
        /*  - Tseg2 =  (DTSEG2 + 1) x Tq = (4 + 1) x 25ns = 125ns       */
        /*  - bit time = Tsync + Tseg1 + Tseg2 = 500ns =0.5us (2Mbps)   */
        /* 2. CAN0 Normal Sampling Point: 75%                           */
        /*  - Sampling Point = (1 + Tseg1)/(1 + Tseg1 + Tseg2) x 100    */
        /*                   = (1 + 14) / (1 + 14 + 5) x 100 = 75%      */
        CAN0_DBTP0.B.DTSEG1 = 14u-1u;
        CAN0_DBTP0.B.DTSEG2 = 5u-1u;
        CAN0_DBTP0.B.DSJW = 4u;
        CAN0_DBTP0.B.DBRP = 2u-1u;

        /* Transmitter Delay Compensation */
        CAN0_DBTP0.B.TDC = 1u;   /* Transmitter Delay Compensation Enable */
        CAN0_TDCR0.B.TDCO = 30u; /* 1bit time: 500ns, SSP:75% (375ns), mtq: 12.5ns, 375/12.5 = 30 */

        /*Transmission Compeleted Interrupt Enable*/
        CAN0_TXBTIE0.U = 0xC000003Fu; /*BUF 0,1,2,3,4,5,30,31*/

        /* Enable interrupts in CAN */
        //IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_messageStoredToDedicatedRxBuffer);
        //IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_transmissionCompleted);
        //IfxCan_Node_enableInterrupt(nodeSfr, IfxCan_Interrupt_busOffStatus);

        /* disable configuration change CCCR.CCE = 0 */
        IfxCan_Node_disableConfigurationChange(nodeSfr);
    }

    /* Filter Configuration for CAN0 Node0 */
    {
        for(ucFltNum = 0; ucFltNum< NUM_CAN0_STD_FILTERS; ucFltNum++ )
        {
            IfxCan_Can_setStandardFilter(&gstCanBasic.drivers.canNode[0],&gstCan0StandardFilter[ucFltNum]);
        }
    }
    /* enable interrupts again */
    IfxCpu_restoreInterrupts(interruptState);

}

static uint32_t DrvCan_NewDataReceived(const IfxCan_Can_Node *node, uint8_t rxBufferId)
{
    uint32_t ulResult = 0u;
    uint32_t mask;

    if (rxBufferId < (uint8_t)IfxCan_RxBufferId_32)
    {
        mask    = (1UL << rxBufferId);
        ulResult = (node->node->NDAT1.U & mask);
    }
    else
    {
        mask    = (1UL << (rxBufferId - 32u));
        ulResult = (node->node->NDAT1.U & mask);
    }

    return ulResult;
}

void DrvCan_BusOffRecovery(void)
{
    /* In CAN BUS OFF */
    if (CAN0_CCCR0.B.INIT == 1u)
    {
        /* START: Change State from bus off fault to Normal */
        CAN0_CCCR0.B.CCE = 1u;
        while (CAN0_CCCR0.B.CCE != 1u)
        {
            /* Do Nothing */
        }

        CAN0_CCCR0.B.INIT = 0u;
        while (CAN0_CCCR0.B.INIT != 0u)
        {
            /* Do Nothing */
        }
        /* END: Change State from bus off fault to Normal */

        gucCan0TxStop = 0u;                               /* Enable Tx */
    }
}

void DrvCan_TxTest(void)
{
	uint8_t aTempData[64] = {0u,};
	uint8_t ucIndex = 0u;

	for(ucIndex = 0u; ucIndex < 64 ; ucIndex++)
	{
		aTempData[ucIndex] = ucIndex;
	}

	aTempData[0] = ucIndex;

	DrvCan0_Transmit(aTempData, CAN0_ID_OBC_01_100MS, CAN0_OBC_01_TX_MSG_BUF, IfxCan_DataLengthCode_64, STANDARD_ID);
}
