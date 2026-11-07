################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../device\ drivers/Src/AFIO_drivers.c \
../device\ drivers/Src/EXTI_Driver.c \
../device\ drivers/Src/GPIO_driver.c \
../device\ drivers/Src/NVIC_Driver.c \
../device\ drivers/Src/RCC_driver.c \
../device\ drivers/Src/USART_Driver.c 

OBJS += \
./device\ drivers/Src/AFIO_drivers.o \
./device\ drivers/Src/EXTI_Driver.o \
./device\ drivers/Src/GPIO_driver.o \
./device\ drivers/Src/NVIC_Driver.o \
./device\ drivers/Src/RCC_driver.o \
./device\ drivers/Src/USART_Driver.o 

C_DEPS += \
./device\ drivers/Src/AFIO_drivers.d \
./device\ drivers/Src/EXTI_Driver.d \
./device\ drivers/Src/GPIO_driver.d \
./device\ drivers/Src/NVIC_Driver.d \
./device\ drivers/Src/RCC_driver.d \
./device\ drivers/Src/USART_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
device\ drivers/Src/AFIO_drivers.o: ../device\ drivers/Src/AFIO_drivers.c device\ drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Thirisha/STM32CubeIDE/workspace_1.18.1/stm32 gpio drivers/device drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"device drivers/Src/AFIO_drivers.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
device\ drivers/Src/EXTI_Driver.o: ../device\ drivers/Src/EXTI_Driver.c device\ drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Thirisha/STM32CubeIDE/workspace_1.18.1/stm32 gpio drivers/device drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"device drivers/Src/EXTI_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
device\ drivers/Src/GPIO_driver.o: ../device\ drivers/Src/GPIO_driver.c device\ drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Thirisha/STM32CubeIDE/workspace_1.18.1/stm32 gpio drivers/device drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"device drivers/Src/GPIO_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
device\ drivers/Src/NVIC_Driver.o: ../device\ drivers/Src/NVIC_Driver.c device\ drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Thirisha/STM32CubeIDE/workspace_1.18.1/stm32 gpio drivers/device drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"device drivers/Src/NVIC_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
device\ drivers/Src/RCC_driver.o: ../device\ drivers/Src/RCC_driver.c device\ drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Thirisha/STM32CubeIDE/workspace_1.18.1/stm32 gpio drivers/device drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"device drivers/Src/RCC_driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
device\ drivers/Src/USART_Driver.o: ../device\ drivers/Src/USART_Driver.c device\ drivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F1 -DSTM32F103C8Tx -c -I../Inc -I"C:/Users/Thirisha/STM32CubeIDE/workspace_1.18.1/stm32 gpio drivers/device drivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"device drivers/Src/USART_Driver.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-device-20-drivers-2f-Src

clean-device-20-drivers-2f-Src:
	-$(RM) ./device\ drivers/Src/AFIO_drivers.cyclo ./device\ drivers/Src/AFIO_drivers.d ./device\ drivers/Src/AFIO_drivers.o ./device\ drivers/Src/AFIO_drivers.su ./device\ drivers/Src/EXTI_Driver.cyclo ./device\ drivers/Src/EXTI_Driver.d ./device\ drivers/Src/EXTI_Driver.o ./device\ drivers/Src/EXTI_Driver.su ./device\ drivers/Src/GPIO_driver.cyclo ./device\ drivers/Src/GPIO_driver.d ./device\ drivers/Src/GPIO_driver.o ./device\ drivers/Src/GPIO_driver.su ./device\ drivers/Src/NVIC_Driver.cyclo ./device\ drivers/Src/NVIC_Driver.d ./device\ drivers/Src/NVIC_Driver.o ./device\ drivers/Src/NVIC_Driver.su ./device\ drivers/Src/RCC_driver.cyclo ./device\ drivers/Src/RCC_driver.d ./device\ drivers/Src/RCC_driver.o ./device\ drivers/Src/RCC_driver.su ./device\ drivers/Src/USART_Driver.cyclo ./device\ drivers/Src/USART_Driver.d ./device\ drivers/Src/USART_Driver.o ./device\ drivers/Src/USART_Driver.su

.PHONY: clean-device-20-drivers-2f-Src

