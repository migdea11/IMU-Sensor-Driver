#ifndef MPU_9250_I2C_H
#define MPU_9250_I2C_H

#include "drivers/Mpu9250Registers.h"
#include "drivers/Mpu9250Config.h"
#include "serial_devices/I2cDevice.h"
#include "inertial_sensors/AccSensor.h"

#include <cstdint>

class Mpu9250I2c : public I2cDevice
{
    private:
        AccSensor *acc_sensor; // TODO change to smart pointer

        const Mpu9250Config::AccConfig::AccRangeSelect acc_range;
        const Mpu9250Config::AccConfig::AccFilterBW acc_filter;
    public:
        Mpu9250I2c(uint8_t bus, Mpu9250Config::I2cAddr addr, Mpu9250Config::AccConfig::AccRangeSelect range, Mpu9250Config::AccConfig::AccFilterBW filter);
        ~Mpu9250I2c();

        AccData GetAccData();

        void Initialize() override;
};

#endif // MPU_9250_I2C_H