################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CTRL_MC.c \
../External_EEPROM.c \
../i2c.c \
../main.c \
../string.c \
../timer.c \
../uart.c 

OBJS += \
./CTRL_MC.o \
./External_EEPROM.o \
./i2c.o \
./main.o \
./string.o \
./timer.o \
./uart.o 

C_DEPS += \
./CTRL_MC.d \
./External_EEPROM.d \
./i2c.d \
./main.d \
./string.d \
./timer.d \
./uart.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


