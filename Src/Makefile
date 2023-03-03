################################################################################
##                      SRC Makefile
################################################################################
#*******************************************************************************
# Incluse iLLD information
#*******************************************************************************
include ../Libraries/TC375_iLLD.mk

#*******************************************************************************
# Define targets
#*******************************************************************************
TARGET                          = TC375_APP
TARGET_ELF_FILE                 = ../Product/Exe/$(TARGET).elf
TARGET_HEX_FILE                 = ../Product/Exe/$(TARGET).hex
TARGET_MAP_FILE                 = ../Product/Exe/$(TARGET).map

#*******************************************************************************
# Define Compiler, Assembler, Linker Command
#*******************************************************************************
CC                              = cctc
AS                              = cctc
LD                              = cctc

#*******************************************************************************
# Directorys of source to build
#*******************************************************************************
SOURCE_APP                      = ./App
SOURCE_APP_SENSORHANDLER        = ./App/SensorHandler
SOURCE_APP_DIAGNOSIS        	= ./App/Diagnosis
SOURCE_RTE                      = ./Rte
SOURCE_BASIC                    = ./Basic
SOURCE_BASIC_IODRIVER           = ./Basic/IoDriver

PRODUCT_DIR                     = ../Product
EXE_DIR                         = $(PRODUCT_DIR)/Exe
OBJS_DIR                        = $(PRODUCT_DIR)/Obj

#*******************************************************************************
# Define include directorys to build
#*******************************************************************************
INCLUDE                     += $(SOURCE_APP)
INCLUDE                     += $(SOURCE_APP_SENSORHANDLER)
INCLUDE                     += $(SOURCE_APP_DIAGNOSIS)
INCLUDE                     += $(SOURCE_RTE)
INCLUDE                     += $(SOURCE_BASIC)
INCLUDE                     += $(SOURCE_BASIC_IODRIVER)

#*******************************************************************************
# Set search path
#*******************************************************************************
vpath % $(INCLUDE)

#*******************************************************************************
# Source files to build
#*******************************************************************************
SOURCE                  = Cpu0_Main.c
SOURCE                  += Cpu1_Main.c
SOURCE                  += Cpu2_Main.c
SOURCE                  += SensorHandler.c

SOURCE                  += RteScheduler.c

SOURCE                  += Driver_Port.c
SOURCE                  += Driver_Stm.c
SOURCE                  += Driver_Watchdog.c
SOURCE                  += Driver_Asc.c
SOURCE                  += Driver_Adc.c
SOURCE                  += Driver_Can.c

SOURCE                  += DiagManager.c
SOURCE                  += DiagHandler.c
SOURCE                  += DiagItem_CellVoltage.c

SOURCE_NAMES            = $(notdir $(SOURCE))
BASE_NAMES              = $(basename $(SOURCE_NAMES))
OBJECTS_NAMES           = $(addsuffix .o, $(BASE_NAMES))
OBJECTS                 = $(addprefix $(OBJS_DIR)/, $(OBJECTS_NAMES))

#*******************************************************************************
# Tasking Compiler options
#*******************************************************************************
CFLAGS  				= --misrac-version=2004
CFLAGS  				+= -D__CPU__=tc37x
CFLAGS  				+= --iso=99
CFLAGS  				+= --c++14
CFLAGS  				+= --language=+volatile
CFLAGS  				+= --exceptions
CFLAGS  				+= --anachronisms
CFLAGS  				+= --fp-model=3
CFLAGS  				+= -O0
CFLAGS  				+= --tradeoff=4
CFLAGS  				+= --compact-max-size=200
CFLAGS  				+= -g
CFLAGS  				+= -Wc-w544
CFLAGS  				+= -Wc-w557
CFLAGS  				+= -Ctc37x
CFLAGS  				+= -Y0
CFLAGS  				+= -N0
CFLAGS  				+= -Z0
CFLAGS  				+= $(patsubst %,-I%,$(INCLUDE))

#*******************************************************************************
# Tasking Assmbler options
#*******************************************************************************
ASFLAGS					= -Og
ASFLAGS 				+= -Os
ASFLAGS 				+= --no-warnings= --error-limit=42
ASFLAGS 				+= $(patsubst %,-I%,$(INCLUDE))
  
#*******************************************************************************
# Tasking Linker options
#*******************************************************************************
LDFLAGS                     = -Wl
LDFLAGS                     += -Oc
LDFLAGS                     += -Wl
LDFLAGS                     += -OL
LDFLAGS                     += -Wl
LDFLAGS                     += -Ot
LDFLAGS                     += -Wl-Ox
LDFLAGS                     += -Wl-Oy
LDFLAGS                     += -Wl-mc
LDFLAGS                     += -Wl-mf
LDFLAGS                     += -Wl-mi
LDFLAGS                     += -Wl-mk
LDFLAGS                     += -Wl-ml
LDFLAGS                     += -Wl-mm
LDFLAGS                     += -Wl-md
LDFLAGS                     += -Wl-mr
LDFLAGS                     += -Wl-mu
LDFLAGS                     += --no-warnings= -Wl--error-limit=42
LDFLAGS                     += --exceptions
LDFLAGS                     += --strict --anachronisms
LDFLAGS                     += --force-c++
LDFLAGS                     += -Ctc37x
LDFLAGS                     += --lsl-core=vtc
LDFLAGS                     += -lcs_fpu
LDFLAGS                     += -lfp_fpu
LDFLAGS                     += -lrt
LDFLAGS					    += --lsl-file=./Lcf_Tasking_Tricore_Tc.lsl
   
#*******************************************************************************
# Define Rules (make objects)
#*******************************************************************************
$(OBJS_DIR)/%.o: %.asm
	$(AS) -c -o $@ $(ASFLAGS) $<

$(OBJS_DIR)/%.o: %.c
	$(CC) -c -o $@ $(CFLAGS) $<

#*******************************************************************************
# Build targets
#*******************************************************************************
.PHONY: all dir clean

all: dir build

dir:
	@echo make dir...
	@if test ! -d $(PRODUCT_DIR); then mkdir -p $(PRODUCT_DIR); fi	
	@if test ! -d $(EXE_DIR); then mkdir -p $(EXE_DIR); fi
	@if test ! -d $(OBJS_DIR); then mkdir -p $(OBJS_DIR); fi
	@echo =============================================================
	@echo '                    App Sw Compile Start!                  '
	@echo =============================================================
	
build: $(OBJECTS)
	@echo =============================================================
	@echo '                    App Sw Linking Start!                  '
	@echo =============================================================
	@$(LD) -o $(TARGET_ELF_FILE) $^ $(ILLD_OBJECTS) $(LDFLAGS)
	@echo App SW Build Finish!
	
clean:
	@echo clean...
	@rm -rf $(OBJS_DIR)/*.o $(TARGET_ELF_FILE) $(TARGET_MAP_FILE)
	@if test -d $(OBJS_DIR) ; then rm -r $(OBJS_DIR); fi
	@if test -d $(EXE_DIR) ; then rm -r $(EXE_DIR); fi
	@if test -d $(PRODUCT_DIR) ; then rm -r $(PRODUCT_DIR); fi 