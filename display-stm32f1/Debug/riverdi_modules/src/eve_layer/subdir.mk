################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../riverdi_modules/src/eve_layer/CoPro_Cmds.c \
../riverdi_modules/src/eve_layer/Gpu_Hal.c \
../riverdi_modules/src/eve_layer/Hal_Utils.c 

O_SRCS += \
../riverdi_modules/src/eve_layer/CoPro_Cmds.o \
../riverdi_modules/src/eve_layer/Gpu_Hal.o \
../riverdi_modules/src/eve_layer/Hal_Utils.o 

OBJS += \
./riverdi_modules/src/eve_layer/CoPro_Cmds.o \
./riverdi_modules/src/eve_layer/Gpu_Hal.o \
./riverdi_modules/src/eve_layer/Hal_Utils.o 

C_DEPS += \
./riverdi_modules/src/eve_layer/CoPro_Cmds.d \
./riverdi_modules/src/eve_layer/Gpu_Hal.d \
./riverdi_modules/src/eve_layer/Hal_Utils.d 


# Each subdirectory must supply rules for building sources it contributes
riverdi_modules/src/eve_layer/%.o: ../riverdi_modules/src/eve_layer/%.c riverdi_modules/src/eve_layer/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DSTM32_PLATFORM_COCMD_BURST -DSTM32_PLATFORM -c -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/Core/Inc" -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/inc/app_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/inc/eve_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/src/app_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/src/eve_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/standard_graphics_module" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/standard_graphics_module/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/standard_graphics_module/src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/Core/Src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/inc/dash_pages" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/src/dash_pages" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/data_control" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/data_control/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/data_control/src" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include" -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

