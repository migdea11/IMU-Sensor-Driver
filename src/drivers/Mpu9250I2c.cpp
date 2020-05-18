#include "drivers/Mpu9250I2c.h"
#include "serial_devices/I2cDevice.h"

Mpu9250I2c::Mpu9250I2c() : // TODO make bus and addr configurable
    I2cDevice<InertialData>(Mpu9250I2c::I2C_BUS_01, Mpu9250I2c::AD0_ADDR)
{
    acc_sensor = AccSensor(this, ACCEL_XOUT_L, ACCEL_XOUT_H, ACCEL_YOUT_L, ACCEL_YOUT_H,
            ACCEL_ZOUT_L, ACCEL_ZOUT_H, )
}

Mpu9250I2c::~Mpu9250I2c() {}
