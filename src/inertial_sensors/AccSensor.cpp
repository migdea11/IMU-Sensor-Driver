#include "inertial_sensors/AccSensor.h"

AccData::AccData(int16_t x, int16_t y, int16_t z) : acc_x(x), acc_y(y), acc_z(z) {}
AccData::~AccData() {}
int16_t AccData::GetX() { return acc_x; }
int16_t AccData::GetY() { return acc_y; }
int16_t AccData::GetZ() { return acc_z; }

AccSensor::AccSensor(SerialDevice &device, int8_t addr_x, int8_t addr_y, int8_t addr_z,
    int16_t min, int16_t max) : AccSensor(device, addr_x, 0x0, addr_y, 0x0, addr_z, 0x0, min, max) {}

AccSensor::AccSensor(SerialDevice &device, int8_t addr_x0, int8_t addr_x1, int8_t addr_y0, int8_t addr_y1,
        int8_t addr_z0,  int8_t addr_z1, int16_t min, int16_t max) :
        InertialSensor<(device), ADDR_ACC_X_L(addr_x0), ADDR_ACC_Y_L(addr_y0), ADDR_ACC_Z_L(addr_z0), ADDR_ACC_X_H(addr_x1),
        ADDR_ACC_Y_H(addr_y1), ADDR_ACC_Z_H(addr_z1), RANGE_MIN(min), RANGE_MAX(max) {}

AccSensor::~AccSensor() {}

 AccData AccSensor::GetData()
 {
    // TODO might need to replace with i2c_read_word_data()
    uint16_t x = ADDR_ACC_X_H > 0 ? serial_device.GetSerialData(ADDR_ACC_X_H) << 8 : 0x00;
    x |= serial_device.GetSerialData(ADDR_ACC_X_L);
    uint16_t y = ADDR_ACC_Y_H > 0 ? serial_device.GetSerialData(ADDR_ACC_Y_H) << 8 : 0x00;
    y |= serial_device.GetSerialData(ADDR_ACC_Y_L);
    uint16_t z = ADDR_ACC_Z_H > 0 ? serial_device.GetSerialData(ADDR_ACC_Z_H) << 8 : 0x00;
    z |= serial_device.GetSerialData(ADDR_ACC_Z_L);

    return AccData(x, y, z);
 }