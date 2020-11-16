#include "drivers/Mpu9250I2c.h"
#include "serial_devices/I2cDevice.h"

#include <cstdint>

Mpu9250I2c::Mpu9250I2c(uint8_t bus, Mpu9250Config::I2cAddr addr, Mpu9250Config::AccConfig::AccRangeSelect range, Mpu9250Config::AccConfig::AccFilterBW filter) : // TODO make bus and addr configurable
    I2cDevice(bus, addr), acc_range(range), acc_filter(filter)
{
    acc_sensor = new AccSensor(*this,
            Mpu9250Registers::ACCEL_XOUT_H,
            Mpu9250Config::AccConfig::getAccRange(acc_range, true),
            Mpu9250Config::AccConfig::getAccRange(acc_range, false));
}

Mpu9250I2c::~Mpu9250I2c()
{
    delete acc_sensor;
}

void Mpu9250I2c::Initialize()
{
    I2cDevice::Initialize();

    // Enable Accelerometer
    uint8_t pwr_reg = I2cDevice::ReadSerialByte(Mpu9250Registers::PWR_MGMT_2);
    I2cDevice::WriteSerialByte(Mpu9250Registers::PWR_MGMT_2, Mpu9250Config::AccConfig::ACC_ENABLE_ALL & pwr_reg);

    I2cDevice::WriteSerialByte(Mpu9250Registers::ACCEL_CONFIG_1, acc_range << Mpu9250Config::AccConfig::ACC_RANGE_OFFSET);
    I2cDevice::WriteSerialByte(Mpu9250Registers::ACCEL_CONFIG_2, acc_filter | Mpu9250Config::AccConfig::ACC_FILTER_ENABLE);

        // Enable Gyro
    uint8_t pwr_reg = I2cDevice::ReadSerialByte(Mpu9250Registers::PWR_MGMT_2);
    I2cDevice::WriteSerialByte(Mpu9250Registers::PWR_MGMT_2, Mpu9250Config::AccConfig::ACC_ENABLE_ALL & pwr_reg);

    I2cDevice::WriteSerialByte(Mpu9250Registers::ACCEL_CONFIG_1, acc_range << Mpu9250Config::AccConfig::ACC_RANGE_OFFSET);
    I2cDevice::WriteSerialByte(Mpu9250Registers::ACCEL_CONFIG_2, acc_filter | Mpu9250Config::AccConfig::ACC_FILTER_ENABLE);
}

AccData Mpu9250I2c::GetAccData()
{
    return acc_sensor->GetData();
}