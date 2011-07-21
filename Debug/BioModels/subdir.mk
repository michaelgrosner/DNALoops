################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../BioModels/Atom.cpp \
../BioModels/BasePair.cpp \
../BioModels/Chain.cpp \
../BioModels/Entity.cpp \
../BioModels/Loop.cpp \
../BioModels/Residue.cpp \
../BioModels/StepParameter.cpp \
../BioModels/Structure.cpp 

OBJS += \
./BioModels/Atom.o \
./BioModels/BasePair.o \
./BioModels/Chain.o \
./BioModels/Entity.o \
./BioModels/Loop.o \
./BioModels/Residue.o \
./BioModels/StepParameter.o \
./BioModels/Structure.o 

CPP_DEPS += \
./BioModels/Atom.d \
./BioModels/BasePair.d \
./BioModels/Chain.d \
./BioModels/Entity.d \
./BioModels/Loop.d \
./BioModels/Residue.d \
./BioModels/StepParameter.d \
./BioModels/Structure.d 


# Each subdirectory must supply rules for building sources it contributes
BioModels/%.o: ../BioModels/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I/net/actin/u1/home/grosner/Documents/Dropbox/DNALoopsC -I/net/actin/u1/home/grosner/lib/DNASim/include -O0 -g3 -Wall -c -fmessage-length=0 -fpermissive -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


