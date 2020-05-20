#include "drivers/Mpu9250I2c.h"
#include "inertial_sensors/AccSensor.h"

#include <iostream>
#include <unistd.h>
using namespace std;

int main()
{
    Mpu9250I2c* inertial_device = new Mpu9250I2c(0x1, Mpu9250Config::I2C_ADDR_AD0, Mpu9250Config::AccConfig::RANGE_16G_BITS, Mpu9250Config::AccConfig::BW_5Hz);
    inertial_device->Initialize();

    float x = 0, y = 0, z = 0, count = 0;
    for (int i = 0; i < 200; ++i) {
        AccData data = inertial_device->GetAccData();
        x += data.GetX();
        y += data.GetY();
        z += data.GetZ();
        count++;
        cout<<data.GetX()<<", "<<data.GetY()<<", "<<data.GetZ()<<endl;
        usleep(100000);
    }

    cout<<"Offsets"<<endl;
    cout<<x / count<<", "<<y / count<<", "<<z / count<<endl<<endl;
    return 0;
}