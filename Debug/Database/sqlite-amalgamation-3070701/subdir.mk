################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Database/sqlite-amalgamation-3070701/shell.c \
../Database/sqlite-amalgamation-3070701/sqlite3.c 

OBJS += \
./Database/sqlite-amalgamation-3070701/shell.o \
./Database/sqlite-amalgamation-3070701/sqlite3.o 

C_DEPS += \
./Database/sqlite-amalgamation-3070701/shell.d \
./Database/sqlite-amalgamation-3070701/sqlite3.d 


# Each subdirectory must supply rules for building sources it contributes
Database/sqlite-amalgamation-3070701/%.o: ../Database/sqlite-amalgamation-3070701/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


