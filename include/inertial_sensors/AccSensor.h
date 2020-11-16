#ifndef ACC_SENSOR_H
#define ACC_SENSOR_H

#include "inertial_sensors/InertialSensor.h"

#include <cstdint>

class AccData : public ThreeDimensionData
{
    public:
        using ThreeDimensionData::ThreeDimensionData;
        ~AccData() = default;
};

class AccSensor : public ThreeDimensionInertialSensor<AccData>
{
    private:
        const float SCALE_M;

    public:
        constexpr static const float GRAVITY_ACC = 9.81; // might add constructor flag to auto apply this

        // individual axis access
        AccSensor(SerialDevice &device, uint8_t addr_x, uint8_t addr_y, uint8_t addr_z, int16_t min, int16_t max);
        // block axis access
        AccSensor(SerialDevice &device, uint8_t addr_full_block, int16_t min, int16_t max);
        ~AccSensor() = default;
        AccData GetData() override;

        inline float ConvertData(uint16_t raw_data)
        {
            return SCALE_M * static_cast<int16_t>(raw_data);
        }
};

#endif // ACC_SENSOR_H