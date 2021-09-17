##########################################################################################################################
# File automatically-generated by tool: [projectgenerator] version: [3.14.1] date: [Fri Sep 17 20:42:55 CST 2021] 
##########################################################################################################################

# ------------------------------------------------
# Generic Makefile (based on gcc)
#
# ChangeLog :
#	2017-02-10 - Several enhancements + project update mode
#   2015-07-22 - first version
# ------------------------------------------------

######################################
# target
######################################
TARGET = 401CCU-Demo


######################################
# building variables
######################################
# debug build?
DEBUG = 1
# optimization
OPT = -Og


#######################################
# paths
#######################################
# Build path
BUILD_DIR = build

######################################
# source
######################################
# C sources
C_SOURCES =  \
Core/Src/main.c \
Core/Src/mysetp.c \
Core/Src/stm32f4xx_it.c \
Core/Src/stm32f4xx_hal_msp.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_tim_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_rcc_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_flash_ramfunc.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_gpio.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_dma.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_pwr_ex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_cortex.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_exti.c \
Core/Src/system_stm32f4xx.c \
u8glib/u8g_ellipse.c \
u8glib/u8g_font.c \
u8glib/u8g_line.c \
u8glib/u8g_ll_api.c \
u8glib/u8g_page.c \
u8glib/u8g_pb.c \
u8glib/u8g_pb8h1.c \
u8glib/u8g_pb8h1f.c \
u8glib/u8g_pb8h2.c \
u8glib/u8g_pb8h8.c \
u8glib/u8g_pb8v1.c \
u8glib/u8g_pb8v2.c \
u8glib/u8g_pb14v1.c \
u8glib/u8g_pb16h1.c \
u8glib/u8g_pb16h2.c \
u8glib/u8g_pb16v1.c \
u8glib/u8g_pb16v2.c \
u8glib/u8g_pb32h1.c \
u8glib/u8g_pbxh16.c \
u8glib/u8g_pbxh24.c \
u8glib/u8g_polygon.c \
u8glib/u8g_rect.c \
u8glib/u8g_rot.c \
u8glib/u8g_scale.c \
u8glib/u8g_state.c \
u8glib/u8g_u8toa.c \
u8glib/u8g_u16toa.c \
u8glib/u8g_virtual_screen.c \
u8glib/u8g_cursor.c \
u8glib/u8g_com_api.c \
u8glib/u8g_com_api_16gr.c \
u8glib/u8g_clip.c \
u8glib/u8g_circle.c \
u8glib/u8g_bitmap.c \
u8glib/chessengine.c \
u8glib/u8g_com_stm32_hw_i2c_hal.c \
u8glib/u8g_com_null.c \
u8glib/u8g_dev_ssd1306_128x64.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c.c \
Drivers/STM32F4xx_HAL_Driver/Src/stm32f4xx_hal_i2c_ex.c

# ASM sources
# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources# ASM sources
ASM_SOURCES =  \
startup_stm32f401xc.s


#######################################
# binaries
#######################################
PREFIX = arm-none-eabi-
# The gcc compiler bin path can be either defined in make command via GCC_PATH variable (> make GCC_PATH=xxx)
# either it can be added to the PATH environment variable.
ifdef GCC_PATH
CC = $(GCC_PATH)/$(PREFIX)gcc
AS = $(GCC_PATH)/$(PREFIX)gcc -x assembler-with-cpp
CP = $(GCC_PATH)/$(PREFIX)objcopy
SZ = $(GCC_PATH)/$(PREFIX)size
else
CC = $(PREFIX)gcc
AS = $(PREFIX)gcc -x assembler-with-cpp
CP = $(PREFIX)objcopy
SZ = $(PREFIX)size
endif
HEX = $(CP) -O ihex
BIN = $(CP) -O binary -S
 
#######################################
# CFLAGS
#######################################
# cpu
CPU = -mcpu=cortex-m4

# fpu
FPU = -mfpu=fpv4-sp-d16

# float-abi
FLOAT-ABI = -mfloat-abi=hard

# mcu
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)

# macros for gcc
# AS defines
AS_DEFS = 

# C defines
C_DEFS =  \
-DUSE_HAL_DRIVER \
-DSTM32F401xC


# AS includes
AS_INCLUDES = 

# C includes
C_INCLUDES =  \
-Iu8glib \
-ICore/Inc \
-IDrivers/STM32F4xx_HAL_Driver/Inc \
-IDrivers/STM32F4xx_HAL_Driver/Inc/Legacy \
-IDrivers/CMSIS/Device/ST/STM32F4xx/Include \
-IDrivers/CMSIS/Include



# compile gcc flags
ASFLAGS = $(MCU) $(AS_DEFS) $(AS_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

CFLAGS = $(MCU) $(C_DEFS) $(C_INCLUDES) $(OPT) -Wall -fdata-sections -ffunction-sections

ifeq ($(DEBUG), 1)
CFLAGS += -g -gdwarf-2
endif


# Generate dependency information
CFLAGS += -MMD -MP -MF"$(@:%.o=%.d)"


#######################################
# LDFLAGS
#######################################
# link script
LDSCRIPT = STM32F401CCUx_FLASH.ld

# libraries
LIBS = -lc -lm -lnosys 
LIBDIR = 
LDFLAGS = $(MCU) -specs=nano.specs -T$(LDSCRIPT) $(LIBDIR) $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map,--cref -Wl,--gc-sections

# default action: build all
all: $(BUILD_DIR)/$(TARGET).elf $(BUILD_DIR)/$(TARGET).hex $(BUILD_DIR)/$(TARGET).bin


#######################################
# build the application
#######################################
# list of objects
OBJECTS = $(addprefix $(BUILD_DIR)/,$(notdir $(C_SOURCES:.c=.o)))
vpath %.c $(sort $(dir $(C_SOURCES)))
# list of ASM program objects
OBJECTS += $(addprefix $(BUILD_DIR)/,$(notdir $(ASM_SOURCES:.s=.o)))
vpath %.s $(sort $(dir $(ASM_SOURCES)))

$(BUILD_DIR)/%.o: %.c Makefile | $(BUILD_DIR) 
	$(CC) -c $(CFLAGS) -Wa,-a,-ad,-alms=$(BUILD_DIR)/$(notdir $(<:.c=.lst)) $< -o $@

$(BUILD_DIR)/%.o: %.s Makefile | $(BUILD_DIR)
	$(AS) -c $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJECTS) Makefile
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@
	$(SZ) $@

$(BUILD_DIR)/%.hex: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(HEX) $< $@
	
$(BUILD_DIR)/%.bin: $(BUILD_DIR)/%.elf | $(BUILD_DIR)
	$(BIN) $< $@	
	
$(BUILD_DIR):
	mkdir $@		

#######################################
# clean up
#######################################
clean:
	-rm -fR $(BUILD_DIR)
  
#######################################
# dependencies
#######################################
-include $(wildcard $(BUILD_DIR)/*.d)

# *** EOF ***
