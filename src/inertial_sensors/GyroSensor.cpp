#include "inertial_sensors/GyroSensor.h"
#include "inertial_sensors/InertialSensor.h"

#include <cstdint>

GyroSensor::GyroSensor(SerialDevice &device, uint8_t addr_x, uint8_t addr_y, uint8_t addr_z, int16_t min, int16_t max) :
        ThreeDimensionInertialSensor(device, addr_x, addr_y, addr_z, min, max),
        SCALE_M(static_cast<float>(max - min) / UINT16_MAX)
{}

GyroSensor::GyroSensor(SerialDevice &device, uint8_t addr_block, int16_t min, int16_t max) :
        ThreeDimensionInertialSensor(device, addr_block, min, max),
        SCALE_M(static_cast<float>(max - min) / UINT16_MAX)
{}

 GyroData GyroSensor::GetData()
 {
    static const uint8_t dim_num = 3, reg_num = 2;
    uint8_t data[dim_num * reg_num] = {0};
    uint8_t success = this->GetDataCommon(data, dim_num, reg_num);
    uint16_t x = ((uint16_t)data[0] << 8 | data[1]);
    uint16_t y = ((uint16_t)data[2] << 8 | data[3]);
    uint16_t z = ((uint16_t)data[4] << 8 | data[5]);

    if (success) {
        return GyroData(x, y, z, ConvertData(x), ConvertData(y), ConvertData(z));
    }

    return GyroData(success);
 }