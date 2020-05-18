#ifndef ACC_SENSOR_H
#define ACC_SENSOR_H

#include "serial_devices/SerialDevice.h"
#include "inertial_sensors/InertialSensor.h"

#include <cstdint>

class AccData
{
    private:
        const int16_t acc_x;
        const int16_t acc_y;
        const int16_t acc_z;

    public:
        AccData(int16_t x, int16_t y, int16_t z);
        ~AccData();
        int16_t get_x();
        int16_t get_y();
        int16_t get_z();
};

class AccSensor : public InertialSensor<AccData>
{
    private:
        const int16_t RANGE_MIN;
        const int16_t RANGE_MAX;

        const int8_t ADDR_ACC_X_L;
        const int8_t ADDR_ACC_X_H;
        const int8_t ADDR_ACC_Y_L;
        const int8_t ADDR_ACC_Y_H;
        const int8_t ADDR_ACC_Z_L;
        const int8_t ADDR_ACC_Z_H;

    public:
        // Single byte register constructor
        AccSensor(SerialDevice<AccData> &device, int8_t addr_x, int8_t addr_y, int8_t addr_z,
                int16_t min, int16_t max);
        // Double byte register constructor
        AccSensor(SerialDevice<AccData> &device, int8_t addr_x0, int8_t addr_x1, int8_t addr_y0, int8_t addr_y1,
                int8_t addr_z0,  int8_t addr_z1, int16_t min, int16_t max);
        ~AccSensor();
        AccData GetData() override;
};

#endif // ACC_SENSOR_H