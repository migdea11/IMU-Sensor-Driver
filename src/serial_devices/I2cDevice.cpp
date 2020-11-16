# include "serial_devices/I2cDevice.h"
# include "serial_devices/SerialDevice.h"

#include <pigpio.h>

#define LOGGING false
#if LOGGING == true
    #include <iostream>
    #define LOG OutputTransaction

    inline void OutputTransaction(std::string name, uint8_t addr, uint16_t data)
    {
        std::cout<<name<<": "<<std::nouppercase << std::showbase  << std::hex<<static_cast<int>(addr)<<" -> "<<data<<" ("<<std::dec<<static_cast<int16_t>(data)<<")\n";
    }
#else
    #define LOG
#endif

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

uint8_t I2cDevice::ReadSerialByte(uint8_t addr)
{
    uint8_t retval = i2cReadByteData(handle, addr);
    LOG("ReadSerialByte", addr, retval);
    return retval;
}

void I2cDevice::WriteSerialByte(uint8_t addr, uint8_t data)
{
    LOG("WriteSerialByte", addr, data);
    i2cWriteByteData(handle, addr, data);
}

uint16_t I2cDevice::ReadSerialWord(uint8_t addr)
{
    uint16_t retval = i2cReadWordData(handle, addr);
    LOG("ReadSerialWord", addr, retval);
    return retval;
}

void I2cDevice::WriteSerialWord(uint8_t addr, uint16_t data)
{
    LOG("WriteSerialWord", addr, data);
    i2cWriteWordData(handle, addr, data);
}

int8_t I2cDevice::ReadSerialBlock(uint8_t addr, uint8_t* data, uint8_t count)
{
    LOG("ReadSerialBlock", addr, 0);
    return i2cReadI2CBlockData(handle, addr, (char*)data, count);
}