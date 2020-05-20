#ifndef SERIAL_DEVICE_H
#define SERIAL_DEVICE_H

#include <cstdint>
#include <mutex>
#include <thread>

class SerialDevice
{
    public:
        virtual void Initialize() = 0;
        virtual void Terminate() = 0;

        virtual uint8_t ReadSerialByte(uint8_t addr) = 0;
        virtual void WriteSerialByte(uint8_t addr, uint8_t data) = 0;

        virtual uint16_t ReadSerialWord(uint8_t addr) = 0;
        virtual void WriteSerialWord(uint8_t addr, uint16_t data) = 0;
};

#endif // SERIAL_DEVICE_H