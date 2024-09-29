#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=MCAL_layer/device_config.c ECU_layer/chr_lcd/ecu_chr_lcd.c ECU_layer/keypad/ecu_keypad.c ECU_layer/mpu6050/mpu6050.c MCAL_layer/adc/hal_adc.c MCAL_layer/ccp/hal_ccp.c MCAL_layer/comparator/comparator.c MCAL_layer/gpio/gpio.c MCAL_layer/i2c/hal_i2c.c MCAL_layer/Interrupt/mcal_external_interrupt.c MCAL_layer/Interrupt/mcal_internal_interrupt.c MCAL_layer/Interrupt/mcal_interrupt_manager.c MCAL_layer/spi/hal_spi.c MCAL_layer/timer0/hal_timr0.c MCAL_layer/timer1/hal_timr1.c MCAL_layer/timer2/hal_timr2.c MCAL_layer/usart/hal_usart.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1 ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1 ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1 ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1 ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1 ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1 ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1 ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1 ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1 ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1 ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/MCAL_layer/device_config.p1.d ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/MCAL_layer/device_config.p1 ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1 ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1 ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1 ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1 ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1 ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1 ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1 ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1 ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1 ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1 ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1 ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1 ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1 ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=MCAL_layer/device_config.c ECU_layer/chr_lcd/ecu_chr_lcd.c ECU_layer/keypad/ecu_keypad.c ECU_layer/mpu6050/mpu6050.c MCAL_layer/adc/hal_adc.c MCAL_layer/ccp/hal_ccp.c MCAL_layer/comparator/comparator.c MCAL_layer/gpio/gpio.c MCAL_layer/i2c/hal_i2c.c MCAL_layer/Interrupt/mcal_external_interrupt.c MCAL_layer/Interrupt/mcal_internal_interrupt.c MCAL_layer/Interrupt/mcal_interrupt_manager.c MCAL_layer/spi/hal_spi.c MCAL_layer/timer0/hal_timr0.c MCAL_layer/timer1/hal_timr1.c MCAL_layer/timer2/hal_timr2.c MCAL_layer/usart/hal_usart.c main.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=16F877A
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1: ECU_layer/chr_lcd/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/chr_lcd" 
	@${RM} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1 ECU_layer/chr_lcd/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.d ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1: ECU_layer/keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1 ECU_layer/keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.d ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1: ECU_layer/mpu6050/mpu6050.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/mpu6050" 
	@${RM} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1 ECU_layer/mpu6050/mpu6050.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.d ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1: MCAL_layer/adc/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/adc" 
	@${RM} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1 MCAL_layer/adc/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.d ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1: MCAL_layer/ccp/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ccp" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1 MCAL_layer/ccp/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.d ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/comparator/comparator.p1: MCAL_layer/comparator/comparator.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/comparator" 
	@${RM} ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1 MCAL_layer/comparator/comparator.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/comparator/comparator.d ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/gpio/gpio.p1: MCAL_layer/gpio/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/gpio" 
	@${RM} ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1 MCAL_layer/gpio/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/gpio/gpio.d ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1: MCAL_layer/i2c/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/i2c" 
	@${RM} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1 MCAL_layer/i2c/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.d ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1: MCAL_layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1 MCAL_layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1: MCAL_layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1 MCAL_layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1: MCAL_layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1 MCAL_layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1: MCAL_layer/spi/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/spi" 
	@${RM} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1 MCAL_layer/spi/hal_spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.d ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1: MCAL_layer/timer0/hal_timr0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/timer0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1 MCAL_layer/timer0/hal_timr0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.d ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1: MCAL_layer/timer1/hal_timr1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/timer1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1 MCAL_layer/timer1/hal_timr1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.d ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1: MCAL_layer/timer2/hal_timr2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/timer2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1 MCAL_layer/timer2/hal_timr2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.d ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1: MCAL_layer/usart/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/usart" 
	@${RM} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1 MCAL_layer/usart/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.d ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c  -D__DEBUG=1  -mdebugger=none   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/MCAL_layer/device_config.p1: MCAL_layer/device_config.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer" 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/device_config.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/device_config.p1 MCAL_layer/device_config.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/device_config.d ${OBJECTDIR}/MCAL_layer/device_config.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/device_config.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1: ECU_layer/chr_lcd/ecu_chr_lcd.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/chr_lcd" 
	@${RM} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1 ECU_layer/chr_lcd/ecu_chr_lcd.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.d ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/chr_lcd/ecu_chr_lcd.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1: ECU_layer/keypad/ecu_keypad.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/keypad" 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1 ECU_layer/keypad/ecu_keypad.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.d ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/keypad/ecu_keypad.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1: ECU_layer/mpu6050/mpu6050.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/ECU_layer/mpu6050" 
	@${RM} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d 
	@${RM} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1 ECU_layer/mpu6050/mpu6050.c 
	@-${MV} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.d ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/ECU_layer/mpu6050/mpu6050.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1: MCAL_layer/adc/hal_adc.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/adc" 
	@${RM} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1 MCAL_layer/adc/hal_adc.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.d ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/adc/hal_adc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1: MCAL_layer/ccp/hal_ccp.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/ccp" 
	@${RM} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1 MCAL_layer/ccp/hal_ccp.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.d ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/ccp/hal_ccp.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/comparator/comparator.p1: MCAL_layer/comparator/comparator.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/comparator" 
	@${RM} ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1 MCAL_layer/comparator/comparator.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/comparator/comparator.d ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/comparator/comparator.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/gpio/gpio.p1: MCAL_layer/gpio/gpio.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/gpio" 
	@${RM} ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1 MCAL_layer/gpio/gpio.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/gpio/gpio.d ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/gpio/gpio.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1: MCAL_layer/i2c/hal_i2c.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/i2c" 
	@${RM} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1 MCAL_layer/i2c/hal_i2c.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.d ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/i2c/hal_i2c.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1: MCAL_layer/Interrupt/mcal_external_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1 MCAL_layer/Interrupt/mcal_external_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_external_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1: MCAL_layer/Interrupt/mcal_internal_interrupt.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1 MCAL_layer/Interrupt/mcal_internal_interrupt.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_internal_interrupt.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1: MCAL_layer/Interrupt/mcal_interrupt_manager.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/Interrupt" 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1 MCAL_layer/Interrupt/mcal_interrupt_manager.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.d ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/Interrupt/mcal_interrupt_manager.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1: MCAL_layer/spi/hal_spi.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/spi" 
	@${RM} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1 MCAL_layer/spi/hal_spi.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.d ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/spi/hal_spi.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1: MCAL_layer/timer0/hal_timr0.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/timer0" 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1 MCAL_layer/timer0/hal_timr0.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.d ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/timer0/hal_timr0.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1: MCAL_layer/timer1/hal_timr1.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/timer1" 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1 MCAL_layer/timer1/hal_timr1.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.d ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/timer1/hal_timr1.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1: MCAL_layer/timer2/hal_timr2.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/timer2" 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1 MCAL_layer/timer2/hal_timr2.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.d ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/timer2/hal_timr2.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1: MCAL_layer/usart/hal_usart.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}/MCAL_layer/usart" 
	@${RM} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d 
	@${RM} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1 MCAL_layer/usart/hal_usart.c 
	@-${MV} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.d ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/MCAL_layer/usart/hal_usart.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk 
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} $(MP_EXTRA_CC_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -c   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -DXPRJ_default=$(CND_CONF)  -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits $(COMPARISON_BUILD)  -std=c99 -gcoff -mstack=compiled:auto:auto     -o ${OBJECTDIR}/main.p1 main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.map  -D__DEBUG=1  -mdebugger=none  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto        $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} ${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.hex 
	
else
${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -mcpu=$(MP_PROCESSOR_OPTION) -Wl,-Map=${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.map  -DXPRJ_default=$(CND_CONF)  -Wl,--defsym=__MPLAB_BUILD=1   -mdfp="${DFP_DIR}/xc8"  -fno-short-double -fno-short-float -O0 -fasmfile -maddrqual=ignore -xassembler-with-cpp -mwarn=-3 -Wa,-a -msummary=-psect,-class,+mem,-hex,-file  -ginhx32 -Wl,--data-init -mno-keep-startup -mno-osccal -mno-resetbits -mno-save-resetbits -mno-download -mno-stackcall -mdefault-config-bits -std=c99 -gcoff -mstack=compiled:auto:auto     $(COMPARISON_BUILD) -Wl,--memorysummary,${DISTDIR}/memoryfile.xml -o ${DISTDIR}/PIC16F877A_Device_Drivers.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
