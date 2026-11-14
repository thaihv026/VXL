################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (14.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../App/Src/app_common.c \
../App/Src/led.c \
../App/Src/lux.c \
../App/Src/mcu.c \
../App/Src/nguon.c \
../App/Src/oled.c \
../App/Src/uart.c 

OBJS += \
./App/Src/app_common.o \
./App/Src/led.o \
./App/Src/lux.o \
./App/Src/mcu.o \
./App/Src/nguon.o \
./App/Src/oled.o \
./App/Src/uart.o 

C_DEPS += \
./App/Src/app_common.d \
./App/Src/led.d \
./App/Src/lux.d \
./App/Src/mcu.d \
./App/Src/nguon.d \
./App/Src/oled.d \
./App/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
App/Src/%.o App/Src/%.su App/Src/%.cyclo: ../App/Src/%.c App/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F103xB -c -I../Core/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc -I../Drivers/STM32F1xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F1xx/Include -I../Drivers/CMSIS/Include -I"E:/File/HUST/projects/VXL/App/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-App-2f-Src

clean-App-2f-Src:
	-$(RM) ./App/Src/app_common.cyclo ./App/Src/app_common.d ./App/Src/app_common.o ./App/Src/app_common.su ./App/Src/led.cyclo ./App/Src/led.d ./App/Src/led.o ./App/Src/led.su ./App/Src/lux.cyclo ./App/Src/lux.d ./App/Src/lux.o ./App/Src/lux.su ./App/Src/mcu.cyclo ./App/Src/mcu.d ./App/Src/mcu.o ./App/Src/mcu.su ./App/Src/nguon.cyclo ./App/Src/nguon.d ./App/Src/nguon.o ./App/Src/nguon.su ./App/Src/oled.cyclo ./App/Src/oled.d ./App/Src/oled.o ./App/Src/oled.su ./App/Src/uart.cyclo ./App/Src/uart.d ./App/Src/uart.o ./App/Src/uart.su

.PHONY: clean-App-2f-Src

