################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/HAL/Src/KPD_program.c \
../Drivers/HAL/Src/LED_program.c \
../Drivers/HAL/Src/SSD_program.c 

OBJS += \
./Drivers/HAL/Src/KPD_program.o \
./Drivers/HAL/Src/LED_program.o \
./Drivers/HAL/Src/SSD_program.o 

C_DEPS += \
./Drivers/HAL/Src/KPD_program.d \
./Drivers/HAL/Src/LED_program.d \
./Drivers/HAL/Src/SSD_program.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/HAL/Src/%.o Drivers/HAL/Src/%.su Drivers/HAL/Src/%.cyclo: ../Drivers/HAL/Src/%.c Drivers/HAL/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/include" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/portable/GCC/ARM_CM4F" -I../Core/Inc -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/HAL/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-HAL-2f-Src

clean-Drivers-2f-HAL-2f-Src:
	-$(RM) ./Drivers/HAL/Src/KPD_program.cyclo ./Drivers/HAL/Src/KPD_program.d ./Drivers/HAL/Src/KPD_program.o ./Drivers/HAL/Src/KPD_program.su ./Drivers/HAL/Src/LED_program.cyclo ./Drivers/HAL/Src/LED_program.d ./Drivers/HAL/Src/LED_program.o ./Drivers/HAL/Src/LED_program.su ./Drivers/HAL/Src/SSD_program.cyclo ./Drivers/HAL/Src/SSD_program.d ./Drivers/HAL/Src/SSD_program.o ./Drivers/HAL/Src/SSD_program.su

.PHONY: clean-Drivers-2f-HAL-2f-Src

