################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (9-2020-q2-update)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../P1_graphics_module/src/dash_pages/ble_ui_pages.c \
../P1_graphics_module/src/dash_pages/charging_ui_pages.c \
../P1_graphics_module/src/dash_pages/ota_ui_pages.c \
../P1_graphics_module/src/dash_pages/primary_ui_pages.c \
../P1_graphics_module/src/dash_pages/wish_message_pages.c 

OBJS += \
./P1_graphics_module/src/dash_pages/ble_ui_pages.o \
./P1_graphics_module/src/dash_pages/charging_ui_pages.o \
./P1_graphics_module/src/dash_pages/ota_ui_pages.o \
./P1_graphics_module/src/dash_pages/primary_ui_pages.o \
./P1_graphics_module/src/dash_pages/wish_message_pages.o 

C_DEPS += \
./P1_graphics_module/src/dash_pages/ble_ui_pages.d \
./P1_graphics_module/src/dash_pages/charging_ui_pages.d \
./P1_graphics_module/src/dash_pages/ota_ui_pages.d \
./P1_graphics_module/src/dash_pages/primary_ui_pages.d \
./P1_graphics_module/src/dash_pages/wish_message_pages.d 


# Each subdirectory must supply rules for building sources it contributes
P1_graphics_module/src/dash_pages/%.o: ../P1_graphics_module/src/dash_pages/%.c P1_graphics_module/src/dash_pages/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -DSTM32_PLATFORM_COCMD_BURST -DSTM32_PLATFORM -c -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/saman/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/Core/Inc" -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -I/Users/samanratnabuddhacharya/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/inc/app_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/inc/eve_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/src/app_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/riverdi_modules/src/eve_layer" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/standard_graphics_module" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/standard_graphics_module/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/standard_graphics_module/src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/Core/Src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/src" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/inc/dash_pages" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/P1_graphics_module/src/dash_pages" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/data_control" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/data_control/inc" -I"/Users/samanratnabuddhacharya/project-one-display/display-stm32f1/data_control/src" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Users/Sanjeeb Malla/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include" -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/peter/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Device/ST/STM32F1xx/Include -IC:/Users/Dell/STM32Cube/Repository/STM32Cube_FW_F1_V1.8.4/Drivers/CMSIS/Include -I../Core/Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

