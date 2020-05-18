#ifndef MPU_9250_I2C_H
#define MPU_9250_I2C_H

#include "serial_devices/I2cDevice.h"
#include "inertial_sensors/AccSensor.h"

#include <cstdint>

// class InertialData
// {
//     private:
//         AccData acc_data; // TODO change to smart pointer
//     public:
//         InertialData(AccData acc)
//         ~InertialData();
// }

class Mpu9250I2c : public I2cDevice
{
    private:
        AccSensor *acc_sensor; // TODO change to smart pointer
    public:
        Mpu9250I2c();
        ~Mpu9250I2c();

        AccData GetAccData();


    private:
        static const uint8_t AD0_ADDR = 0x68; // TODO change to configurable
        // static const uint8_t SD0_ADDR = 0x69;

        static const uint8_t I2C_BUS_00 = 0x0;
        static const uint8_t I2C_BUS_01 = 0x1;

        static const uint8_t ACCEL_CONFIG_DATA_1 = 0x0; // TODO change to configurable
        static const uint8_t ACCEL_CONFIG_DATA_2 = 0x0; // TODO change to configurable

        /*
         * Register Definitions
         */
        static const uint16_t ACCEL_CONFIG_1 = 0x1C;
        static const uint16_t ACCEL_CONFIG_2 = 0x1D;
        static const uint16_t ACCEL_XOUT_L = 0x3C;
        static const uint16_t ACCEL_XOUT_H = 0x3B;
        static const uint16_t ACCEL_YOUT_L = 0x3E;
        static const uint16_t ACCEL_YOUT_H = 0x3D;
        static const uint16_t ACCEL_ZOUT_L = 0x40;
        static const uint16_t ACCEL_ZOUT_H = 0x3F;
};

#endif // MPU_9250_I2C_H