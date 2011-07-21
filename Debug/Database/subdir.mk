################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Database/SQLiteDB.cpp 

OBJS += \
./Database/SQLiteDB.o 

CPP_DEPS += \
./Database/SQLiteDB.d 


# Each subdirectory must supply rules for building sources it contributes
Database/%.o: ../Database/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/net/actin/u1/home/grosner/Documents/Dropbox/DNALoopsC -I/net/actin/u1/home/grosner/lib/DNASim/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


