################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ReversePoem.cpp \
../ReversePoemTester.cpp \
../Stack.cpp \
../StackTester.cpp \
../tester.cpp 

OBJS += \
./ReversePoem.o \
./ReversePoemTester.o \
./Stack.o \
./StackTester.o \
./tester.o 

CPP_DEPS += \
./ReversePoem.d \
./ReversePoemTester.d \
./Stack.d \
./StackTester.d \
./tester.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


