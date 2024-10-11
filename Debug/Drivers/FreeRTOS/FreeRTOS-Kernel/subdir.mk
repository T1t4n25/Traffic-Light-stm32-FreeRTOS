################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.c \
../Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.c \
../Drivers/FreeRTOS/FreeRTOS-Kernel/list.c \
../Drivers/FreeRTOS/FreeRTOS-Kernel/queue.c \
../Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.c \
../Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.c \
../Drivers/FreeRTOS/FreeRTOS-Kernel/timers.c 

OBJS += \
./Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.o \
./Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.o \
./Drivers/FreeRTOS/FreeRTOS-Kernel/list.o \
./Drivers/FreeRTOS/FreeRTOS-Kernel/queue.o \
./Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.o \
./Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.o \
./Drivers/FreeRTOS/FreeRTOS-Kernel/timers.o 

C_DEPS += \
./Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.d \
./Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.d \
./Drivers/FreeRTOS/FreeRTOS-Kernel/list.d \
./Drivers/FreeRTOS/FreeRTOS-Kernel/queue.d \
./Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.d \
./Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.d \
./Drivers/FreeRTOS/FreeRTOS-Kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/FreeRTOS/FreeRTOS-Kernel/%.o Drivers/FreeRTOS/FreeRTOS-Kernel/%.su Drivers/FreeRTOS/FreeRTOS-Kernel/%.cyclo: ../Drivers/FreeRTOS/FreeRTOS-Kernel/%.c Drivers/FreeRTOS/FreeRTOS-Kernel/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/FreeRTOS-Kernel/portable/MemMang" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/FreeRTOS-Kernel/portable/GCC/ARM_CM4F" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/FreeRTOS/FreeRTOS-Kernel/include" -I"D:/T1t4nProject/Embedded systems projects/workspace_1.16.1/Traffic Light/Drivers/HAL/Inc" -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel

clean-Drivers-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel:
	-$(RM) ./Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/croutine.su ./Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/event_groups.su ./Drivers/FreeRTOS/FreeRTOS-Kernel/list.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/list.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/list.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/list.su ./Drivers/FreeRTOS/FreeRTOS-Kernel/queue.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/queue.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/queue.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/queue.su ./Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/stream_buffer.su ./Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/tasks.su ./Drivers/FreeRTOS/FreeRTOS-Kernel/timers.cyclo ./Drivers/FreeRTOS/FreeRTOS-Kernel/timers.d ./Drivers/FreeRTOS/FreeRTOS-Kernel/timers.o ./Drivers/FreeRTOS/FreeRTOS-Kernel/timers.su

.PHONY: clean-Drivers-2f-FreeRTOS-2f-FreeRTOS-2d-Kernel

