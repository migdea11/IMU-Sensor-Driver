#include "inertial_sensors/AccSensor.h"

AccSensor::AccSensor(SerialDevice<AccData> &device, int8_t addr_x, int8_t addr_y, int8_t addr_z,
    int16_t min, int16_t max) : AccSensor(device, addr_x, 0x0, addr_y, 0x0, addr_z, 0x0, min, max) {}

AccSensor::AccSensor(SerialDevice<AccData> &device, int8_t addr_x0, int8_t addr_x1, int8_t addr_y0, int8_t addr_y1,
        int8_t addr_z0,  int8_t addr_z1, int16_t min, int16_t max) :
        InertialSensor(device), ADDR_ACC_X_L(addr_x0), ADDR_ACC_Y_L(addr_y0), ADDR_ACC_Z_L(addr_z0), ADDR_ACC_X_H(addr_x1),
        ADDR_ACC_Y_H(addr_y1), ADDR_ACC_Z_H(addr_z1), RANGE_MIN(min), RANGE_MAX(max) {}

AccSensor::~AccSensor() {}

 AccData AccSensor::GetData()
 {
    uint16_t x = serial_device.GetSerialData(ADDR_ACC_X_L);
    uint16_t y = serial_device.GetSerialData(ADDR_ACC_Y_L);
    uint16_t z = serial_device.GetSerialData(ADDR_ACC_Z_L);

    if (ADDR_ACC_X_H > 0) // Assume that all or none are 2 byte registers
    {
        x |= serial_device.GetSerialData(ADDR_ACC_X_H) << 8;
        y |= serial_device.GetSerialData(ADDR_ACC_Y_H) << 8;
        z |= serial_device.GetSerialData(ADDR_ACC_Z_H) << 8;
    }

    return AccData(x, y,z);
 }