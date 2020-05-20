#ifndef ACC_SENSOR_H
#define ACC_SENSOR_H

#include "serial_devices/SerialDevice.h"
#include "inertial_sensors/InertialSensor.h"

#include <cstdint>

class AccData
{
    private:
        const int16_t acc_raw_x;
        const int16_t acc_raw_y;
        const int16_t acc_raw_z;
        const float acc_x;
        const float acc_y;
        const float acc_z;

    public:
        AccData(int16_t raw_x, int16_t raw_y, int16_t raw_z, float x, float y, float z);
        ~AccData();
        int16_t GetRawX();
        int16_t GetRawY();
        int16_t GetRawZ();

        float GetX();
        float GetY();
        float GetZ();
};

class AccSensor : public InertialSensor<AccData>
{
    private:
        const int16_t RANGE_MIN;
        const int16_t RANGE_MAX;
        const float SCALE_M;
        const int16_t SCALE_B;

        const int8_t ADDR_ACC_X_L;
        const int8_t ADDR_ACC_X_H;
        const int8_t ADDR_ACC_Y_L;
        const int8_t ADDR_ACC_Y_H;
        const int8_t ADDR_ACC_Z_L;
        const int8_t ADDR_ACC_Z_H;

    public:
        // Single byte register constructor
        AccSensor(SerialDevice &device, int8_t addr_x, int8_t addr_y, int8_t addr_z,
                int16_t min, int16_t max);
        // Double byte register constructor
        AccSensor(SerialDevice &device, int8_t addr_x0, int8_t addr_x1, int8_t addr_y0, int8_t addr_y1,
                int8_t addr_z0,  int8_t addr_z1, int16_t min, int16_t max);
        ~AccSensor();
        AccData GetData() override;

        inline float ConvertData(uint16_t raw_data)
        {
            return SCALE_M * static_cast<int16_t>(raw_data);// + SCALE_B;
        }
};

#endif // ACC_SENSOR_H