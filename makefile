TEST    	:= test
BIN     	:= bin
SRC     	:= src
INCLUDE 	:= include

CXX			:= g++
CXX_FLAGS	:= -std=c++17 -g -I$(INCLUDE)
LD_FLAGS	:= -g
LD_LIBS		:= -lwiringPi -lpthread -lpigpio -lrt
RM			:= rm -f

SRCS 		:= $(shell find $(SRC_DIRS) -name *.cpp)
OBJS 		:= $(SRCS:%=$(BIN)/%.o)

all: i2c_devices.o acc_sensor.o mpu_i2c.o

# gpio_test: gpio_test.o
# 	$(CXX) $(LD_FLAGS) -o $(BIN)/gpio_test $(BIN)/gpio_test.o $(LD_LIBS)

# gpio_test.o:
# 	$(CXX) $(CXX_FLAGS) -c $(TEST)/gpio_test.cpp -o $(BIN)/gpio_test.o

acc_i2c_test: acc_i2c_test.o i2c_devices.o acc_sensor.o mpu_i2c.o
	$(CXX) $(LD_FLAGS) -o $(BIN)/acc_i2c_test $(BIN)/*.o $(LD_LIBS)

acc_i2c_test.o:
	$(CXX) $(CXX_FLAGS) -c $(TEST)/acc_i2c_test.cpp -o $(BIN)/acc_i2c_test.o

i2c_devices.o:
	$(CXX) $(CXX_FLAGS) -c $(SRC)/serial_devices/I2cDevice.cpp -o $(BIN)/i2c_devices.o

acc_sensor.o:
	$(CXX) $(CXX_FLAGS) -c $(SRC)/inertial_sensors/AccSensor.cpp -o $(BIN)/acc_sensor.o

mpu_i2c.o:
	$(CXX) $(CXX_FLAGS) -c $(SRC)/drivers/Mpu9250I2c.cpp -o $(BIN)/mpu_i2c.o

clean:
	$(RM) $(BIN)/*