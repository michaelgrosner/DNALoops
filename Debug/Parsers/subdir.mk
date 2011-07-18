################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Parsers/PDBLoopParser.cpp \
../Parsers/PDBParser.cpp \
../Parsers/X3DNAParser.cpp 

OBJS += \
./Parsers/PDBLoopParser.o \
./Parsers/PDBParser.o \
./Parsers/X3DNAParser.o 

CPP_DEPS += \
./Parsers/PDBLoopParser.d \
./Parsers/PDBParser.d \
./Parsers/X3DNAParser.d 


# Each subdirectory must supply rules for building sources it contributes
Parsers/%.o: ../Parsers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/net/actin/u1/home/grosner/Dropbox/DNALoopsC -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


