# include "serial_devices/I2cDevice.h"
# include "serial_devices/SerialDevice.h"

#include <pigpio.h>

I2cDevice::I2cDevice(uint8_t bus, uint8_t addr) :
    i2c_bus(bus), i2c_addr(addr) {}

I2cDevice::~I2cDevice() {}

void I2cDevice::Initialize()
{
    gpioInitialise();
    handle = i2cOpen(i2c_bus, i2c_addr, I2C_FLAGS);
}

void I2cDevice::Terminate()
{
    gpioTerminate();
}

uint8_t I2cDevice::GetSerialData(uint8_t addr)
{
    return i2cReadByteData(handle, addr);
}