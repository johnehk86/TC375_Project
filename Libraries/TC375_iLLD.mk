################################################################################
##                      iLLD Header
################################################################################
#*******************************************************************************
# iLLD Object File Path
#*******************************************************************************
ILLD_OBJS_DIR			= ../Libraries/Obj
ILLD_LIB_DIR			= ../Libraries/Lib

#*******************************************************************************
# Directorys of iLLD Source to build
#*******************************************************************************
LIB_CONFIG												=	../Libraries/Config
LIB_ILLD_ILLD_TC37A_TRICORE								=	../Libraries/iLLD/iLLD/TC37A/Tricore
LIB_ILLD_ILLD_TC37A_TRICORE_IMPL						=	../Libraries/iLLD/iLLD/TC37A/Tricore/_Impl
LIB_ILLD_ILLD_TC37A_TRICORE_LIB							=	../Libraries/iLLD/iLLD/TC37A/Tricore/_Lib
LIB_ILLD_ILLD_TC37A_TRICORE_LIB_DATAHANDLING			=	../Libraries/iLLD/iLLD/TC37A/Tricore/_Lib/DataHandling
LIB_ILLD_ILLD_TC37A_TRICORE_LIB_INTERNALMUX				=	../Libraries/iLLD/iLLD/TC37A/Tricore/_Lib/InternalMux
LIB_ILLD_ILLD_TC37A_TRICORE_PINMAP						=	../Libraries/iLLD/iLLD/TC37A/Tricore/_PinMap
LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_ASC 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Asclin/Asc
LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_LIN 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Asclin/Lin
LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_SPI 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Asclin/Spi
LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_STD 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Asclin/Std
LIB_ILLD_ILLD_TC37A_TRICORE_CAN_CAN						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Can/Can
LIB_ILLD_ILLD_TC37A_TRICORE_CAN_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Can/Std
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_ICU 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/Icu
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_PWMBC 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/PwmBc
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_PWMHL 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/PwmHl
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_STD 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/Std
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_TIMER 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/Timer
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_TIMERWITHTRIGGER 		= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/TimerWithTrigger
LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_TPWM 					= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Ccu6/TPwm
LIB_ILLD_ILLD_TC37A_TRICORE_CONVCTRL_STD 				= 	../Libraries/iLLD/iLLD/TC37A/Tricore/Convctrl/Std
LIB_ILLD_ILLD_TC37A_TRICORE_CPU_CSTART					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Cpu/CStart
LIB_ILLD_ILLD_TC37A_TRICORE_CPU_IRQ						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Cpu/Irq
LIB_ILLD_ILLD_TC37A_TRICORE_CPU_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Cpu/Std
LIB_ILLD_ILLD_TC37A_TRICORE_CPU_TRAP					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Cpu/Trap
LIB_ILLD_ILLD_TC37A_TRICORE_DMA_DMA						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Dma/Dma
LIB_ILLD_ILLD_TC37A_TRICORE_DMA_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Dma/Std
LIB_ILLD_ILLD_TC37A_TRICORE_DTS_DTS						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Dts/Dts
LIB_ILLD_ILLD_TC37A_TRICORE_DTS_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Dts/Std
LIB_ILLD_ILLD_TC37A_TRICORE_EDSADC_EDSADC				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Edsadc/Edsadc
LIB_ILLD_ILLD_TC37A_TRICORE_EDSADC_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Edsadc/Std
LIB_ILLD_ILLD_TC37A_TRICORE_ERAY_ERAY					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Eray/Eray
LIB_ILLD_ILLD_TC37A_TRICORE_ERAY_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Eray/Std
LIB_ILLD_ILLD_TC37A_TRICORE_EVADC_ADC					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Evadc/Adc
LIB_ILLD_ILLD_TC37A_TRICORE_EVADC_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Evadc/Std
LIB_ILLD_ILLD_TC37A_TRICORE_FCE_CRC						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Fce/Crc
LIB_ILLD_ILLD_TC37A_TRICORE_FCE_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Fce/Std
LIB_ILLD_ILLD_TC37A_TRICORE_FLASH_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Flash/Std
LIB_ILLD_ILLD_TC37A_TRICORE_GETH_ETH					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Geth/Eth
LIB_ILLD_ILLD_TC37A_TRICORE_GETH_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Geth/Std
LIB_ILLD_ILLD_TC37A_TRICORE_ETH_PHY_PEF7071				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Eth/Phy_Pef7071
LIB_ILLD_ILLD_TC37A_TRICORE_ETH_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Eth/Std
LIB_ILLD_ILLD_TC37A_TRICORE_GPT12_INCRENC				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gpt12/IncrEnc
LIB_ILLD_ILLD_TC37A_TRICORE_GPT12_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gpt12/Std
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_DTMPWMHL			=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Atom/Dtm_PwmHl
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_PWM				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Atom/Pwm
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_PWMHL				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Atom/PwmHl
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_TIMER				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Atom/Timer
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Std
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TIM_IN					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Tim/In
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TIM_TIMER				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Tim/Timer
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_DTMPWMHL			=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Tom/Dtm_PwmHl
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_PWM					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Tom/Pwm
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_PWMHL				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Tom/PwmHl
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_TIMER				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Tom/Timer
LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TRIG					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Gtm/Trig
LIB_ILLD_ILLD_TC37A_TRICORE_HSSL_HSSL					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Hssl/Hssl
LIB_ILLD_ILLD_TC37A_TRICORE_HSSL_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Hssl/Std
LIB_ILLD_ILLD_TC37A_TRICORE_I2C_I2C						=	../Libraries/iLLD/iLLD/TC37A/Tricore/I2c/I2c
LIB_ILLD_ILLD_TC37A_TRICORE_I2C_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/I2c/Std
LIB_ILLD_ILLD_TC37A_TRICORE_IOM_DRIVER					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Iom/Driver
LIB_ILLD_ILLD_TC37A_TRICORE_IOM_IOM						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Iom/Iom
LIB_ILLD_ILLD_TC37A_TRICORE_IOM_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Iom/Std
LIB_ILLD_ILLD_TC37A_TRICORE_MSC_MSC						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Msc/Msc
LIB_ILLD_ILLD_TC37A_TRICORE_MSC_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Msc/Std
LIB_ILLD_ILLD_TC37A_TRICORE_MTU_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Mtu/Std
LIB_ILLD_ILLD_TC37A_TRICORE_PMS_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Pms/Std
LIB_ILLD_ILLD_TC37A_TRICORE_PORT_IO						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Port/Io
LIB_ILLD_ILLD_TC37A_TRICORE_PORT_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Port/Std
LIB_ILLD_ILLD_TC37A_TRICORE_PSI5_PSI5					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Psi5/Psi5
LIB_ILLD_ILLD_TC37A_TRICORE_PSI5_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Psi5/Std
LIB_ILLD_ILLD_TC37A_TRICORE_PSI5S_PSI5S					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Psi5s/Psi5s
LIB_ILLD_ILLD_TC37A_TRICORE_PSI5S_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Psi5s/Std
LIB_ILLD_ILLD_TC37A_TRICORE_QSPI_SPIMASTER				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Qspi/SpiMaster
LIB_ILLD_ILLD_TC37A_TRICORE_QSPI_SPISLAVE				=	../Libraries/iLLD/iLLD/TC37A/Tricore/Qspi/SpiSlave
LIB_ILLD_ILLD_TC37A_TRICORE_QSPI_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Qspi/Std
LIB_ILLD_ILLD_TC37A_TRICORE_SCU_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Scu/Std
LIB_ILLD_ILLD_TC37A_TRICORE_SENT_SENT					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Sent/Sent
LIB_ILLD_ILLD_TC37A_TRICORE_SENT_STD					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Sent/Std
LIB_ILLD_ILLD_TC37A_TRICORE_SMU_SMU						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Smu/Smu
LIB_ILLD_ILLD_TC37A_TRICORE_SMU_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Smu/Std
LIB_ILLD_ILLD_TC37A_TRICORE_SRC_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Src/Std
LIB_ILLD_ILLD_TC37A_TRICORE_STM_STD						=	../Libraries/iLLD/iLLD/TC37A/Tricore/Stm/Std
LIB_ILLD_ILLD_TC37A_TRICORE_STM_TIMER					=	../Libraries/iLLD/iLLD/TC37A/Tricore/Stm/Timer
LIB_ILLD_INFRA_PLATFORM									=	../Libraries/iLLD/Infra/Platform
LIB_ILLD_INFRA_PLATFORM_TRICORE							=	../Libraries/iLLD/Infra/Platform/Tricore
LIB_ILLD_INFRA_PLATFORM_TRICORE_COMPILERS				=	../Libraries/iLLD/Infra/Platform/Tricore/Compilers
LIB_ILLD_INFRA_SFR_TC37A								=	../Libraries/iLLD/Infra/Sfr/TC37A
LIB_ILLD_INFRA_SFR_TC37A_REG							=	../Libraries/iLLD/Infra/Sfr/TC37A/_Reg
LIB_ILLD_INFRA_SSW_TC37A_TRICORE						=	../Libraries/iLLD/Infra/Ssw/TC37A/Tricore
LIB_ILLD_SERVICE_CPUGENERIC								=	../Libraries/iLLD/Service/CpuGeneric
LIB_ILLD_SERVICE_CPUGENERIC_UTILITIES					=	../Libraries/iLLD/Service/CpuGeneric/_Utilities
LIB_ILLD_SERVICE_CPUGENERIC_IF							=	../Libraries/iLLD/Service/CpuGeneric/If
LIB_ILLD_SERVICE_CPUGENERIC_IF_CCU6IF					=	../Libraries/iLLD/Service/CpuGeneric/If/Ccu6If
LIB_ILLD_SERVICE_CPUGENERIC_STDIF						=	../Libraries/iLLD/Service/CpuGeneric/StdIf
LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_BSP					=	../Libraries/iLLD/Service/CpuGeneric/SysSe/Bsp
LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_COMM					=	../Libraries/iLLD/Service/CpuGeneric/SysSe/Comm
LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_GENERAL				=	../Libraries/iLLD/Service/CpuGeneric/SysSe/General
LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_MATH					=	../Libraries/iLLD/Service/CpuGeneric/SysSe/Math
LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_TIME					=	../Libraries/iLLD/Service/CpuGeneric/SysSe/Time

#*******************************************************************************
# Define include directorys to build
#*******************************************************************************
INCLUDE 			+= $(LIB_CONFIG)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_IMPL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_LIB)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_LIB_DATAHANDLING)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_LIB_INTERNALMUX)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PINMAP)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_ASC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_LIN)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_SPI)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ASCLIN_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CAN_CAN)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CAN_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_ICU)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_PWMBC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_PWMHL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_TIMER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_TIMERWITHTRIGGER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CCU6_TPWM)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CONVCTRL_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CPU_CSTART)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CPU_IRQ)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CPU_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_CPU_TRAP)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_DMA_DMA)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_DMA_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_DTS_DTS)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_DTS_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_EDSADC_EDSADC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_EDSADC_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ERAY_ERAY)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ERAY_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_EVADC_ADC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_EVADC_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_FCE_CRC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_FCE_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_FLASH_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GETH_ETH)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GETH_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ETH_PHY_PEF7071)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_ETH_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GPT12_INCRENC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GPT12_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_DTMPWMHL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_PWM)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_PWMHL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_ATOM_TIMER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TIM_IN)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TIM_TIMER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_DTMPWMHL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_PWM)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_PWMHL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TOM_TIMER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_GTM_TRIG)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_HSSL_HSSL)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_HSSL_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_I2C_I2C)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_I2C_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_IOM_DRIVER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_IOM_IOM)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_IOM_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_MSC_MSC)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_MSC_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_MTU_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PMS_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PORT_IO)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PORT_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PSI5_PSI5)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PSI5_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PSI5S_PSI5S)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_PSI5S_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_QSPI_SPIMASTER)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_QSPI_SPISLAVE)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_QSPI_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_SCU_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_SENT_SENT)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_SENT_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_SMU_SMU)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_SMU_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_SRC_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_STM_STD)
INCLUDE 			+= $(LIB_ILLD_ILLD_TC37A_TRICORE_STM_TIMER)

INCLUDE 			+= $(LIB_ILLD_INFRA_PLATFORM)
INCLUDE 			+= $(LIB_ILLD_INFRA_PLATFORM_TRICORE)
INCLUDE 			+= $(LIB_ILLD_INFRA_PLATFORM_TRICORE_COMPILERS)

INCLUDE 			+= $(LIB_ILLD_INFRA_SFR_TC37A)
INCLUDE 			+= $(LIB_ILLD_INFRA_SFR_TC37A_REG)
INCLUDE 			+= $(LIB_ILLD_INFRA_SSW_TC37A_TRICORE)

INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_UTILITIES)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_IF)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_IF_CCU6IF)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_STDIF)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_BSP)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_COMM)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_GENERAL)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_MATH)
INCLUDE 			+= $(LIB_ILLD_SERVICE_CPUGENERIC_SYSSE_TIME)

#*******************************************************************************
# iLLD Source files to build
#*******************************************************************************
ILLD_SOURCE				= 	Ifx_Cfg_Ssw.c
ILLD_SOURCE				+= 	Ifx_Cfg_SswBmhd.c

ILLD_SOURCE				+= 	IfxAsclin_cfg.c
ILLD_SOURCE				+= 	IfxCan_cfg.c
ILLD_SOURCE				+= 	IfxCcu6_cfg.c
ILLD_SOURCE				+= 	IfxCpu_cfg.c
ILLD_SOURCE				+= 	IfxDma_cfg.c
ILLD_SOURCE				+= 	IfxEray_cfg.c
ILLD_SOURCE				+= 	IfxEvadc_cfg.c
ILLD_SOURCE				+= 	IfxFlash_cfg.c
ILLD_SOURCE				+= 	IfxGeth_cfg.c
ILLD_SOURCE				+= 	IfxGtm_cfg.c
ILLD_SOURCE				+= 	IfxHssl_cfg.c
ILLD_SOURCE				+= 	IfxI2c_cfg.c
ILLD_SOURCE				+= 	IfxMsc_cfg.c
ILLD_SOURCE				+= 	IfxMtu_cfg.c
ILLD_SOURCE				+= 	IfxPort_cfg.c
ILLD_SOURCE				+= 	IfxPsi5_cfg.c
ILLD_SOURCE				+= 	IfxQspi_cfg.c
ILLD_SOURCE				+= 	IfxScu_cfg.c
ILLD_SOURCE				+= 	IfxSent_cfg.c
ILLD_SOURCE				+= 	IfxSmu_cfg.c
ILLD_SOURCE				+= 	IfxSrc_cfg.c
ILLD_SOURCE				+= 	IfxStm_cfg.c

#ILLD_SOURCE				+= 	Ifx_CircularBuffer.asm
ILLD_SOURCE				+= 	Ifx_CircularBuffer.c
ILLD_SOURCE				+= 	Ifx_Fifo.c
ILLD_SOURCE				+= 	Ifx_InternalMux.c

ILLD_SOURCE				+= 	IfxAsclin_PinMap.c
ILLD_SOURCE				+= 	IfxCan_PinMap.c
ILLD_SOURCE				+= 	IfxCcu6_PinMap.c
ILLD_SOURCE				+= 	IfxDmu_PinMap.c
ILLD_SOURCE				+= 	IfxEdsadc_PinMap.c
ILLD_SOURCE				+= 	IfxEray_PinMap.c
ILLD_SOURCE				+= 	IfxEvadc_PinMap.c
ILLD_SOURCE				+= 	IfxGeth_PinMap.c
ILLD_SOURCE				+= 	IfxGpt12_PinMap.c
ILLD_SOURCE				+= 	IfxGtm_PinMap.c
ILLD_SOURCE				+= 	IfxI2c_PinMap.c
ILLD_SOURCE				+= 	IfxMsc_PinMap.c
ILLD_SOURCE				+= 	IfxPms_PinMap.c
ILLD_SOURCE				+= 	IfxPort_PinMap.c
ILLD_SOURCE				+= 	IfxPsi5_PinMap.c
ILLD_SOURCE				+= 	IfxPsi5s_PinMap.c
ILLD_SOURCE				+= 	IfxQspi_PinMap.c
ILLD_SOURCE				+= 	IfxScu_PinMap.c
ILLD_SOURCE				+= 	IfxSent_PinMap.c
ILLD_SOURCE				+= 	IfxSmu_PinMap.c

ILLD_SOURCE				+= 	IfxAsclin_Asc.c
ILLD_SOURCE				+= 	IfxAsclin_Lin.c
ILLD_SOURCE				+= 	IfxAsclin_Spi.c
ILLD_SOURCE				+= 	IfxAsclin.c

ILLD_SOURCE				+= 	IfxCan_Can.c
ILLD_SOURCE				+= 	IfxCan.c
ILLD_SOURCE				+= 	IfxCcu6_Icu.c
ILLD_SOURCE				+= 	IfxCcu6_PwmBc.c
ILLD_SOURCE				+= 	IfxCcu6_PwmHl.c
ILLD_SOURCE				+= 	IfxCcu6.c
ILLD_SOURCE				+= 	IfxCcu6_Timer.c
ILLD_SOURCE				+= 	IfxCcu6_TimerWithTrigger.c
ILLD_SOURCE				+= 	IfxCcu6_TPwm.c

ILLD_SOURCE				+= 	IfxConvctrl.c

ILLD_SOURCE				+= 	IfxCpu_Irq.c
ILLD_SOURCE				+= 	IfxCpu.c
ILLD_SOURCE				+= 	IfxCpu_Trap.c

ILLD_SOURCE				+= 	IfxDma_Dma.c
ILLD_SOURCE				+= 	IfxDma.c

ILLD_SOURCE				+= 	IfxDts_Dts.c
ILLD_SOURCE				+= 	IfxDts.c

ILLD_SOURCE				+= 	IfxEdsadc_Edsadc.c
ILLD_SOURCE				+= 	IfxEdsadc.c

ILLD_SOURCE				+= 	IfxEray_Eray.c
ILLD_SOURCE				+= 	IfxEray.c

ILLD_SOURCE				+= 	IfxEvadc_Adc.c
ILLD_SOURCE				+= 	IfxEvadc.c

ILLD_SOURCE				+= 	IfxFce_Crc.c
ILLD_SOURCE				+= 	IfxFce.c

ILLD_SOURCE				+= 	IfxFlash.c

ILLD_SOURCE				+= 	IfxGeth_Eth.c
ILLD_SOURCE				+= 	IfxGeth.c

ILLD_SOURCE				+= 	IfxGpt12_IncrEnc.c
ILLD_SOURCE				+= 	IfxGpt12.c

ILLD_SOURCE				+= 	IfxGtm_Atom_Dtm_PwmHl.c
ILLD_SOURCE				+= 	IfxGtm_Atom_Pwm.c
ILLD_SOURCE				+= 	IfxGtm_Atom_PwmHl.c
ILLD_SOURCE				+= 	IfxGtm_Atom_Timer.c
ILLD_SOURCE				+= 	IfxGtm.c
ILLD_SOURCE				+= 	IfxGtm_Atom.c
ILLD_SOURCE				+= 	IfxGtm_Cmu.c
ILLD_SOURCE				+= 	IfxGtm_Dpll.c
ILLD_SOURCE				+= 	IfxGtm_Dtm.c
ILLD_SOURCE				+= 	IfxGtm_Psm.c
ILLD_SOURCE				+= 	IfxGtm_Spe.c
ILLD_SOURCE				+= 	IfxGtm_Tbu.c
ILLD_SOURCE				+= 	IfxGtm_Tim.c
ILLD_SOURCE				+= 	IfxGtm_Tom.c
ILLD_SOURCE				+= 	IfxGtm_Tim_In.c
ILLD_SOURCE				+= 	IfxGtm_Tim_Timer.c
ILLD_SOURCE				+= 	IfxGtm_Tom_Dtm_PwmHl.c
ILLD_SOURCE				+= 	IfxGtm_Tom_Pwm.c
ILLD_SOURCE				+= 	IfxGtm_Tom_PwmHl.c
ILLD_SOURCE				+= 	IfxGtm_Tom_Timer.c
ILLD_SOURCE				+= 	IfxGtm_Trig.c

ILLD_SOURCE				+= 	IfxHssl_Hssl.c
ILLD_SOURCE				+= 	IfxHssl.c

ILLD_SOURCE				+= 	IfxI2c_I2c.c
ILLD_SOURCE				+= 	IfxI2c.c

ILLD_SOURCE				+= 	IfxIom_Driver.c
ILLD_SOURCE				+= 	IfxIom_Iom.c
ILLD_SOURCE				+= 	IfxIom.c

ILLD_SOURCE				+= 	IfxMsc_Msc.c
ILLD_SOURCE				+= 	IfxMsc.c

ILLD_SOURCE				+= 	IfxMtu.c

ILLD_SOURCE				+= 	IfxPmsEvr.c
ILLD_SOURCE				+= 	IfxPmsPm.c

ILLD_SOURCE				+= 	IfxPort_Io.c
ILLD_SOURCE				+= 	IfxPort.c

ILLD_SOURCE				+= 	IfxPsi5_Psi5.c
ILLD_SOURCE				+= 	IfxPsi5.c

ILLD_SOURCE				+= 	IfxPsi5s_Psi5s.c
ILLD_SOURCE				+= 	IfxPsi5s.c

ILLD_SOURCE				+= 	IfxQspi_SpiMaster.c
ILLD_SOURCE				+= 	IfxQspi_SpiSlave.c
ILLD_SOURCE				+= 	IfxQspi.c

ILLD_SOURCE				+= 	IfxScuCcu.c
ILLD_SOURCE				+= 	IfxScuEru.c
ILLD_SOURCE				+= 	IfxScuLbist.c
ILLD_SOURCE				+= 	IfxScuRcu.c
ILLD_SOURCE				+= 	IfxScuWdt.c

ILLD_SOURCE				+= 	IfxSent_Sent.c
ILLD_SOURCE				+= 	IfxSent.c

ILLD_SOURCE				+= 	IfxSmu_Smu.c
ILLD_SOURCE				+= 	IfxSmu.c
ILLD_SOURCE				+= 	IfxSmuStdby.c

ILLD_SOURCE				+= 	IfxSrc.c

ILLD_SOURCE				+= 	IfxStm.c
ILLD_SOURCE				+= 	IfxStm_Timer.c

ILLD_SOURCE				+= 	CompilerTasking.c

ILLD_SOURCE				+= 	Ifx_Ssw_Infra.c
ILLD_SOURCE				+= 	Ifx_Ssw_Tc0.c
ILLD_SOURCE				+= 	Ifx_Ssw_Tc1.c
ILLD_SOURCE				+= 	Ifx_Ssw_Tc2.c

ILLD_SOURCE				+= 	SpiIf.c
ILLD_SOURCE				+= 	IfxStdIf_DPipe.c
ILLD_SOURCE				+= 	IfxStdIf_Pos.c
ILLD_SOURCE				+= 	IfxStdIf_PwmHl.c
ILLD_SOURCE				+= 	IfxStdIf_Timer.c
ILLD_SOURCE				+= 	Assert.c
ILLD_SOURCE				+= 	Bsp.c
ILLD_SOURCE				+= 	Ifx_Console.c
ILLD_SOURCE				+= 	Ifx_Shell.c
ILLD_SOURCE				+= 	Ifx_GlobalResources.c
ILLD_SOURCE				+= 	Ifx_AngleTrkF32.c
ILLD_SOURCE				+= 	Ifx_Cf32.c
ILLD_SOURCE				+= 	Ifx_Crc.c
ILLD_SOURCE				+= 	Ifx_FftF32.c
ILLD_SOURCE				+= 	Ifx_FftF32_BitReverseTable.c
ILLD_SOURCE				+= 	Ifx_FftF32_TwiddleTable.c
ILLD_SOURCE				+= 	Ifx_IntegralF32.c
ILLD_SOURCE				+= 	Ifx_LowPassPt1F32.c
ILLD_SOURCE				+= 	Ifx_LutAtan2F32.c
ILLD_SOURCE				+= 	Ifx_LutAtan2F32_Table.c
ILLD_SOURCE				+= 	Ifx_LutLinearF32.c
ILLD_SOURCE				+= 	Ifx_LutLSincosF32.c
ILLD_SOURCE				+= 	Ifx_LutSincosF32.c
ILLD_SOURCE				+= 	Ifx_LutSincosF32_Table.c
ILLD_SOURCE				+= 	Ifx_RampF32.c
ILLD_SOURCE				+= 	Ifx_WndF32_BlackmanHarrisTable.c
ILLD_SOURCE				+= 	Ifx_WndF32_HannTable.c
ILLD_SOURCE				+= 	Ifx_DateTime.c

ILLD_SOURCE_NAMES = $(notdir $(ILLD_SOURCE))
ILLD_BASE_NAMES	 = $(basename $(ILLD_SOURCE_NAMES))
ILLD_OBJECTS_NAMES = $(addsuffix .o, $(ILLD_BASE_NAMES))
ILLD_OBJECTS = $(addprefix $(ILLD_OBJS_DIR)/, $(ILLD_OBJECTS_NAMES))