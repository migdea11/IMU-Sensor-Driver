#ifndef I2C_DEVICE_H
#define I2C_DEVICE_H

#include "serial_devices/SerialDevice.h"

#include <cstdint>

class I2cDevice : public SerialDevice
{
    private:
        static const uint8_t I2C_FLAGS = 0;

        const uint8_t i2c_bus;
        const uint8_t i2c_addr;
        int32_t handle;

    public:
        I2cDevice(uint8_t bus, uint8_t addr);
        ~I2cDevice();
        void Initialize() override;
        void Terminate() override;

        uint8_t ReadSerialByte(uint8_t addr) override;
        void WriteSerialByte(uint8_t addr, uint8_t data) override;

        uint16_t ReadSerialWord(uint8_t addr) override;
        void WriteSerialWord(uint8_t addr, uint16_t data) override;
};

#endif // I2C_DEVICE_H