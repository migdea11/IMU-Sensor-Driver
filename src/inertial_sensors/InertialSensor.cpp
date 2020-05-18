#include "inertial_sensors/InertialSensor.h"

InertialSensor::InertialSensor(SerialDevice &device) : serial_device(device) {}
InertialSensor::~InertialSensor() {}