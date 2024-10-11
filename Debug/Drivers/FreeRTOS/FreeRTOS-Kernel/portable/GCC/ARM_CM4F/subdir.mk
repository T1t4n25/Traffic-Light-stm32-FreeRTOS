################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.c 

OBJS += \
./Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.o 

C_DEPS += \
./Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/%.o Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/%.su Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/%.cyclo: ../Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/%.c Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/FreeRTOS-Kernel/portable/MemMang" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/FreeRTOS-Kernel/include" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/HAL/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel-2f-portable-2f-GCC-2f-ARM_CM4F

clean-Drivers-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel-2f-portable-2f-GCC-2f-ARM_CM4F:
	-$(RM) ./Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F/port.su

.PHONY: clean-Drivers-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel-2f-portable-2f-GCC-2f-ARM_CM4F

