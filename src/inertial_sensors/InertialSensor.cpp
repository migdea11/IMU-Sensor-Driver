#include "inertial_sensors/InertialSensor.h"

#include <cstdint>

ThreeDimensionData::ThreeDimensionData(int16_t raw_x, int16_t raw_y, int16_t raw_z, float x, float y, float z) :
        raw_x(raw_x), raw_y(raw_y), raw_z(raw_z), x(x), y(y), z(z), error_code(0) {}
ThreeDimensionData::ThreeDimensionData(int8_t error) :
        raw_x(0), raw_y(0), raw_z(0), x(0), y(0), z(0), error_code(error) {}


int16_t ThreeDimensionData::GetRawX() { return raw_x; }
int16_t ThreeDimensionData::GetRawY() { return raw_y; }
int16_t ThreeDimensionData::GetRawZ() { return raw_z; }

float ThreeDimensionData::GetX() { return x; }
float ThreeDimensionData::GetY() { return y; }
float ThreeDimensionData::GetZ() { return z; }

int8_t ThreeDimensionData::GetError() { return error_code; }