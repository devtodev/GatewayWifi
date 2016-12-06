################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Sources/BT_actions.c \
../Sources/Events.c \
../Sources/StorePassword.c \
../Sources/WIFI_actions.c \
../Sources/frtos_tasks.c \
../Sources/main.c \
../Sources/utils.c 

OBJS += \
./Sources/BT_actions.o \
./Sources/Events.o \
./Sources/StorePassword.o \
./Sources/WIFI_actions.o \
./Sources/frtos_tasks.o \
./Sources/main.o \
./Sources/utils.o 

C_DEPS += \
./Sources/BT_actions.d \
./Sources/Events.d \
./Sources/StorePassword.d \
./Sources/WIFI_actions.d \
./Sources/frtos_tasks.d \
./Sources/main.d \
./Sources/utils.d 


# Each subdirectory must supply rules for building sources it contributes
Sources/%.o: ../Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross ARM C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-m0plus -mthumb -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Static_Code/PDD" -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Static_Code/IO_Map" -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Sources" -I"/home/karl/workspace.kds/Kinetis-ARM/Gateway Wifi/Generated_Code" -std=c99 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


