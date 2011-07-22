################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Parsers/IdealStructureBuilder.cpp \
../Parsers/PDBLoopParser.cpp \
../Parsers/X3DNAParser.cpp 

OBJS += \
./Parsers/IdealStructureBuilder.o \
./Parsers/PDBLoopParser.o \
./Parsers/X3DNAParser.o 

CPP_DEPS += \
./Parsers/IdealStructureBuilder.d \
./Parsers/PDBLoopParser.d \
./Parsers/X3DNAParser.d 


# Each subdirectory must supply rules for building sources it contributes
Parsers/%.o: ../Parsers/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/net/actin/u1/home/grosner/Documents/Dropbox/DNALoopsC -I/net/actin/u1/home/grosner/lib/DNASim/include -O0 -g -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


