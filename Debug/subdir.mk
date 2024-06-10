################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_Prog.c \
../GIE_Pro.c \
../ParkedCell_Pro.c \
../Stepper_pro.c \
../TIM1_Pro.c \
../USART_Pro.c \
../main.c 

OBJS += \
./DIO_Prog.o \
./GIE_Pro.o \
./ParkedCell_Pro.o \
./Stepper_pro.o \
./TIM1_Pro.o \
./USART_Pro.o \
./main.o 

C_DEPS += \
./DIO_Prog.d \
./GIE_Pro.d \
./ParkedCell_Pro.d \
./Stepper_pro.d \
./TIM1_Pro.d \
./USART_Pro.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


