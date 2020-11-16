#ifndef INERTIAL_SENSOR_H
#define INERTIAL_SENSOR_H

#include "serial_devices/SerialDevice.h"

#include <cstdint>

class ThreeDimensionData
{
    private:
        const int16_t raw_x;
        const int16_t raw_y;
        const int16_t raw_z;
        const float x;
        const float y;
        const float z;

        const int8_t error_code;

    public:
        ThreeDimensionData(int16_t raw_x, int16_t raw_y, int16_t raw_z, float x, float y, float z);
        ThreeDimensionData(int8_t error); // Invalid data
        ~ThreeDimensionData() = default;
        int16_t GetRawX();
        int16_t GetRawY();
        int16_t GetRawZ();

        float GetX();
        float GetY();
        float GetZ();

        int8_t GetError();
};

template<class T>
class InertialSensor
{
    protected:
        SerialDevice &serial_device;
    public:
        InertialSensor(SerialDevice &device) : serial_device(device) {}
        ~InertialSensor() = default;
        virtual T GetData() = 0;
};

template<class T>
class ThreeDimensionInertialSensor : public InertialSensor<T>
{
    private:
        const int16_t RANGE_MIN;
        const int16_t RANGE_MAX;

        const uint8_t ADDR_ACC_X;
        const uint8_t ADDR_ACC_Y;
        const uint8_t ADDR_ACC_Z;
        const uint8_t ADDR_BLOCK_ACCESS;

    protected:
        uint8_t GetDataCommon(uint8_t* data, const uint8_t dim_num, const uint8_t reg_num)
        {
            uint8_t* data_ptr = data;
            uint8_t success = 0;
            if (ADDR_BLOCK_ACCESS)
            {
                uint8_t elements = reg_num * dim_num;
                success = this->serial_device.ReadSerialBlock(ADDR_BLOCK_ACCESS, data_ptr, elements) == elements;
            }
            else
            {
                success |= (this->serial_device.ReadSerialBlock(ADDR_ACC_X, data_ptr, reg_num) == reg_num) << 1;
                data_ptr += reg_num;
                success |= (this->serial_device.ReadSerialBlock(ADDR_ACC_Y, data_ptr, reg_num) == reg_num) << 2;
                data_ptr += reg_num;
                success |= (this->serial_device.ReadSerialBlock(ADDR_ACC_Z, data_ptr, reg_num) == reg_num) << 3;
            }

            return success;
        }

    public:
        // individual axis access
        ThreeDimensionInertialSensor(SerialDevice &device, uint8_t addr_x, uint8_t addr_y, uint8_t addr_z, int16_t min, int16_t max) :
            InertialSensor<T>(device),
            ADDR_ACC_X(addr_x),
            ADDR_ACC_Y(addr_y),
            ADDR_ACC_Z(addr_z),
            ADDR_BLOCK_ACCESS(0),
            RANGE_MIN(min),
            RANGE_MAX(max) {}
        // block axis access
        ThreeDimensionInertialSensor(SerialDevice &device, uint8_t addr_full_block, int16_t min, int16_t max) :
            InertialSensor<T>(device),
            ADDR_ACC_X(0),
            ADDR_ACC_Y(0),
            ADDR_ACC_Z(0),
            ADDR_BLOCK_ACCESS(addr_full_block),
            RANGE_MIN(min),
            RANGE_MAX(max) {}
        ~ThreeDimensionInertialSensor() = default;

        virtual T GetData() = 0;
};

#endif // INERTIAL_SENSOR_H