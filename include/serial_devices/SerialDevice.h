#ifndef SERIAL_DEVICE_H
#define SERIAL_DEVICE_H

#include <cstdint>
#include <mutex>
#include <thread>

class SerialDevice
{
    public:
        virtual void Start(uint8_t interval) = 0;
        virtual void Stop() = 0;
        virtual uint8_t GetSerialData(uint8_t addr) = 0;
};

#endif // SERIAL_DEVICE_H