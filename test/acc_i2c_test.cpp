#include "drivers/Mpu9250I2c.h"
#include "inertial_sensors/AccSensor.h"

#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    Mpu9250I2c* inertial_device = new Mpu9250I2c();
    inertial_device->Initialize();

    for (int i = 0; i < 10; ++i) {
        AccData data = inertial_device->GetAccData();
        cout<<data.GetX()<<", "<<data.GetY()<<", "<<data.GetZ()<<endl;
        usleep(1000);
    }

    return 0;
}