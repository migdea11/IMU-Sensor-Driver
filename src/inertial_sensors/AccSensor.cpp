#include "inertial_sensors/AccSensor.h"
#include "inertial_sensors/InertialSensor.h"

#include <cstdint>
#include <iostream>

AccData::AccData(int16_t raw_x, int16_t raw_y, int16_t raw_z, float x, float y, float z) :
        acc_raw_x(raw_x), acc_raw_y(raw_y), acc_raw_z(raw_z), acc_x(x), acc_y(y), acc_z(z) {}
AccData::~AccData() {}

int16_t AccData::GetRawX() { return acc_raw_x; }
int16_t AccData::GetRawY() { return acc_raw_y; }
int16_t AccData::GetRawZ() { return acc_raw_z; }

float AccData::GetX() { return acc_x; }
float AccData::GetY() { return acc_y; }
float AccData::GetZ() { return acc_z; }

AccSensor::AccSensor(SerialDevice &device, int8_t addr_x, int8_t addr_y, int8_t addr_z,
    int16_t min, int16_t max) : AccSensor(device, addr_x, 0x0, addr_y, 0x0, addr_z, 0x0, min, max) {}

AccSensor::AccSensor(SerialDevice &device, int8_t addr_x0, int8_t addr_x1, int8_t addr_y0, int8_t addr_y1,
        int8_t addr_z0,  int8_t addr_z1, int16_t min, int16_t max) :
        InertialSensor<AccData>(device),
        ADDR_ACC_X_L(addr_x0), ADDR_ACC_X_H(addr_x1),
        ADDR_ACC_Y_L(addr_y0), ADDR_ACC_Y_H(addr_y1),
        ADDR_ACC_Z_L(addr_z0), ADDR_ACC_Z_H(addr_z1),
        RANGE_MIN(min), RANGE_MAX(max),
        SCALE_B(min), SCALE_M(static_cast<float>(max - min) / UINT16_MAX)
{
    std::cout<<RANGE_MIN<<", "<<RANGE_MAX<<std::endl;
    std::cout<<SCALE_B<<", "<<SCALE_M<<", "<<UINT16_MAX<<std::endl;
}

AccSensor::~AccSensor() {}

 AccData AccSensor::GetData()
 {
    // TODO might need to replace with i2c_read_word_data()
    // uint16_t x = ADDR_ACC_X_H > 0 ? serial_device.ReadSerialByte(ADDR_ACC_X_H) << 8 : 0x00;
    // x |= serial_device.ReadSerialByte(ADDR_ACC_X_L);
    // uint16_t y = ADDR_ACC_Y_H > 0 ? serial_device.ReadSerialByte(ADDR_ACC_Y_H) << 8 : 0x00;
    // y |= serial_device.ReadSerialByte(ADDR_ACC_Y_L);
    // uint16_t z = ADDR_ACC_Z_H > 0 ? serial_device.ReadSerialByte(ADDR_ACC_Z_H) << 8 : 0x00;
    // z |= serial_device.ReadSerialByte(ADDR_ACC_Z_L);

    uint16_t x = ADDR_ACC_X_H == 0 ? serial_device.ReadSerialByte(ADDR_ACC_X_L) : serial_device.ReadSerialWord(ADDR_ACC_X_H);
    uint16_t y = ADDR_ACC_Y_H == 0 ? serial_device.ReadSerialByte(ADDR_ACC_Y_L) : serial_device.ReadSerialWord(ADDR_ACC_Y_H);
    uint16_t z = ADDR_ACC_Z_H == 0 ? serial_device.ReadSerialByte(ADDR_ACC_Z_L) : serial_device.ReadSerialWord(ADDR_ACC_Z_H);


    return AccData(x, y, z, ConvertData(x), ConvertData(y), ConvertData(z));
 }