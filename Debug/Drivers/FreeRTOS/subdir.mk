################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/FreeRTOS/croutine.c \
../Drivers/FreeRTOS/event_groups.c \
../Drivers/FreeRTOS/list.c \
../Drivers/FreeRTOS/queue.c \
../Drivers/FreeRTOS/tasks.c \
../Drivers/FreeRTOS/timers.c 

OBJS += \
./Drivers/FreeRTOS/croutine.o \
./Drivers/FreeRTOS/event_groups.o \
./Drivers/FreeRTOS/list.o \
./Drivers/FreeRTOS/queue.o \
./Drivers/FreeRTOS/tasks.o \
./Drivers/FreeRTOS/timers.o 

C_DEPS += \
./Drivers/FreeRTOS/croutine.d \
./Drivers/FreeRTOS/event_groups.d \
./Drivers/FreeRTOS/list.d \
./Drivers/FreeRTOS/queue.d \
./Drivers/FreeRTOS/tasks.d \
./Drivers/FreeRTOS/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/FreeRTOS/%.o Drivers/FreeRTOS/%.su Drivers/FreeRTOS/%.cyclo: ../Drivers/FreeRTOS/%.c Drivers/FreeRTOS/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/HAL/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/include" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/portable/GCC/ARM_CM4F" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-FreeRTOS

clean-Drivers-2f-FreeRTOS:
	-$(RM) ./Drivers/FreeRTOS/croutine.cyclo ./Drivers/FreeRTOS/croutine.d ./Drivers/FreeRTOS/croutine.o ./Drivers/FreeRTOS/croutine.su ./Drivers/FreeRTOS/event_groups.cyclo ./Drivers/FreeRTOS/event_groups.d ./Drivers/FreeRTOS/event_groups.o ./Drivers/FreeRTOS/event_groups.su ./Drivers/FreeRTOS/list.cyclo ./Drivers/FreeRTOS/list.d ./Drivers/FreeRTOS/list.o ./Drivers/FreeRTOS/list.su ./Drivers/FreeRTOS/queue.cyclo ./Drivers/FreeRTOS/queue.d ./Drivers/FreeRTOS/queue.o ./Drivers/FreeRTOS/queue.su ./Drivers/FreeRTOS/tasks.cyclo ./Drivers/FreeRTOS/tasks.d ./Drivers/FreeRTOS/tasks.o ./Drivers/FreeRTOS/tasks.su ./Drivers/FreeRTOS/timers.cyclo ./Drivers/FreeRTOS/timers.d ./Drivers/FreeRTOS/timers.o ./Drivers/FreeRTOS/timers.su

.PHONY: clean-Drivers-2f-FreeRTOS

