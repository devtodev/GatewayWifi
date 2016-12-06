################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Generated_Code/ASerialLdd1.c \
../Generated_Code/ASerialLdd2.c \
../Generated_Code/BT.c \
../Generated_Code/BitIoLdd1.c \
../Generated_Code/BitIoLdd2.c \
../Generated_Code/BitIoLdd5.c \
../Generated_Code/BitIoLdd6.c \
../Generated_Code/BitIoLdd7.c \
../Generated_Code/BitIoLdd8.c \
../Generated_Code/CS1.c \
../Generated_Code/Cpu.c \
../Generated_Code/ESP8266.c \
../Generated_Code/FRTOS1.c \
../Generated_Code/Flash.c \
../Generated_Code/IntFlashLdd1.c \
../Generated_Code/KSDK1.c \
../Generated_Code/PE_LDD.c \
../Generated_Code/SW1.c \
../Generated_Code/SW2.c \
../Generated_Code/SW3.c \
../Generated_Code/SW4.c \
../Generated_Code/SW5.c \
../Generated_Code/SW6.c \
../Generated_Code/SegLCD1.c \
../Generated_Code/TI1.c \
../Generated_Code/TSK1.c \
../Generated_Code/TU1.c \
../Generated_Code/TimeDate.c \
../Generated_Code/UTIL1.c \
../Generated_Code/Vectors.c \
../Generated_Code/croutine.c \
../Generated_Code/event_groups.c \
../Generated_Code/heap_1.c \
../Generated_Code/heap_2.c \
../Generated_Code/heap_3.c \
../Generated_Code/heap_4.c \
../Generated_Code/heap_5.c \
../Generated_Code/list.c \
../Generated_Code/port.c \
../Generated_Code/queue.c \
../Generated_Code/tasks.c \
../Generated_Code/timers.c 

OBJS += \
./Generated_Code/ASerialLdd1.o \
./Generated_Code/ASerialLdd2.o \
./Generated_Code/BT.o \
./Generated_Code/BitIoLdd1.o \
./Generated_Code/BitIoLdd2.o \
./Generated_Code/BitIoLdd5.o \
./Generated_Code/BitIoLdd6.o \
./Generated_Code/BitIoLdd7.o \
./Generated_Code/BitIoLdd8.o \
./Generated_Code/CS1.o \
./Generated_Code/Cpu.o \
./Generated_Code/ESP8266.o \
./Generated_Code/FRTOS1.o \
./Generated_Code/Flash.o \
./Generated_Code/IntFlashLdd1.o \
./Generated_Code/KSDK1.o \
./Generated_Code/PE_LDD.o \
./Generated_Code/SW1.o \
./Generated_Code/SW2.o \
./Generated_Code/SW3.o \
./Generated_Code/SW4.o \
./Generated_Code/SW5.o \
./Generated_Code/SW6.o \
./Generated_Code/SegLCD1.o \
./Generated_Code/TI1.o \
./Generated_Code/TSK1.o \
./Generated_Code/TU1.o \
./Generated_Code/TimeDate.o \
./Generated_Code/UTIL1.o \
./Generated_Code/Vectors.o \
./Generated_Code/croutine.o \
./Generated_Code/event_groups.o \
./Generated_Code/heap_1.o \
./Generated_Code/heap_2.o \
./Generated_Code/heap_3.o \
./Generated_Code/heap_4.o \
./Generated_Code/heap_5.o \
./Generated_Code/list.o \
./Generated_Code/port.o \
./Generated_Code/queue.o \
./Generated_Code/tasks.o \
./Generated_Code/timers.o 

C_DEPS += \
./Generated_Code/ASerialLdd1.d \
./Generated_Code/ASerialLdd2.d \
./Generated_Code/BT.d \
./Generated_Code/BitIoLdd1.d \
./Generated_Code/BitIoLdd2.d \
./Generated_Code/BitIoLdd5.d \
./Generated_Code/BitIoLdd6.d \
./Generated_Code/BitIoLdd7.d \
./Generated_Code/BitIoLdd8.d \
./Generated_Code/CS1.d \
./Generated_Code/Cpu.d \
./Generated_Code/ESP8266.d \
./Generated_Code/FRTOS1.d \
./Generated_Code/Flash.d \
./Generated_Code/IntFlashLdd1.d \
./Generated_Code/KSDK1.d \
./Generated_Code/PE_LDD.d \
./Generated_Code/SW1.d \
./Generated_Code/SW2.d \
./Generated_Code/SW3.d \
./Generated_Code/SW4.d \
./Generated_Code/SW5.d \
./Generated_Code/SW6.d \
./Generated_Code/SegLCD1.d \
./Generated_Code/TI1.d \
./Generated_Code/TSK1.d \
./Generated_Code/TU1.d \
./Generated_Code/TimeDate.d \
./Generated_Code/UTIL1.d \
./Generated_Code/Vectors.d \
./Generated_Code/croutine.d \
./Generated_Code/event_groups.d \
./Generated_Code/heap_1.d \
./Generated_Code/heap_2.d \
./Generated_Code/heap_3.d \
./Generated_Code/heap_4.d \
./Generated_Code/heap_5.d \
./Generated_Code/list.d \
./Generated_Code/port.d \
./Generated_Code/queue.d \
./Generated_Code/tasks.d \
./Generated_Code/timers.d 


# Each subdirectory must supply rules for building sources it contributes
Generated_Code/%.o: ../Generated_Code/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Static_Code/PDD" -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Static_Code/IO_Map" -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Sources" -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


