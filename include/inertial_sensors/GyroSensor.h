#ifndef GYRO_SENSOR_H
#define GYRO_SENSOR_H

#include "inertial_sensors/InertialSensor.h"

#include <cstdint>

class GyroData : public ThreeDimensionData
{
    public:
        using ThreeDimensionData::ThreeDimensionData;
        ~GyroData() = default;
};

class GyroSensor : public ThreeDimensionInertialSensor<GyroData>
{
    private:
        const float SCALE_M;

    public:
        // individual axis access
        GyroSensor(SerialDevice &device, uint8_t addr_x, uint8_t addr_y, uint8_t addr_z, int16_t min, int16_t max);
        // block axis access
        GyroSensor(SerialDevice &device, uint8_t addr_full_block, int16_t min, int16_t max);
        ~GyroSensor() = default;
        GyroData GetData() override;

        inline float ConvertData(uint16_t raw_data)
        {
            return SCALE_M * static_cast<int16_t>(raw_data);
        }
};

#endif // GYRO_SENSOR_H