#ifndef INERTIAL_SENSOR_H
#define INERTIAL_SENSOR_H

#include "serial_devices/SerialDevice.h"

#include <cstdint>

template<class T>
class InertialSensor
{
    protected:
        SerialDevice<T> &serial_device;
    public:
        InertialSensor(SerialDevice<T> &device);
        ~InertialSensor();
        virtual T GetData() = 0;
};

#endif // INERTIAL_SENSOR_H