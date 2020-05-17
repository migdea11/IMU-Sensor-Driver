TEST    	:= test
BIN     	:= bin
SRC     	:= src/*
INCLUDE 	:= include/*

CXX			:= g++
CXX_FLAGS	:= -std=c++17 -g
LD_FLAGS	:= -g
LD_LIBS		:= -lwiringPi -lpthread -lpigpio -lrt
RM			:= rm -f

SRCS		:= 

gpio_test: gpio_test.o
	$(CXX) $(LD_FLAGS) -o $(BIN)/gpio_test $(BIN)/gpio_test.o $(LD_LIBS)

gpio_test.o:
	$(CXX) $(CXX_FLAGS) -c $(TEST)/gpio_test.cpp -o $(BIN)/gpio_test.o



clean:
    $(RM) $(BIN)/*