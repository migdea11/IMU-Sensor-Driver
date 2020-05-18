#include "drivers/Mpu9250I2c.h"
#include "serial_devices/I2cDevice.h"

Mpu9250I2c::Mpu9250I2c() : // TODO make bus and addr configurable
    I2cDevice(Mpu9250I2c::I2C_BUS_01, Mpu9250I2c::AD0_ADDR)
{
    acc_sensor = new AccSensor(*this, ACCEL_XOUT_L, ACCEL_XOUT_H, ACCEL_YOUT_L, ACCEL_YOUT_H,
            ACCEL_ZOUT_L, ACCEL_ZOUT_H, 0, 0); // TODO update min and max values
}

Mpu9250I2c::~Mpu9250I2c()
{
    delete acc_sensor;
}

AccData Mpu9250I2c::GetAccData()
{
    return acc_sensor->GetData();
}