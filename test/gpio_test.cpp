#include <pigpio.h>

#include <iostream>

int main() {
    gpioInitialise();

    int32_t handle = i2cOpen(0x1, 0x68, 0);

    if (handle >= 0) {
        std::cout<<"this is a good start"<<std::endl;
    }
    uint16_t ACCEL_CONFIG = 0x1C;
    uint16_t ACCEL_XOUT_L = 0x3C;
    uint16_t ACCEL_XOUT_H = 0x3B;
    
    uint16_t reading = i2cReadByteData(handle, ACCEL_XOUT_H);
    std::cout<<reading<<std::endl;
    reading = reading << 8;
    reading = i2cReadByteData(handle, ACCEL_CONFIG);
    std::cout<<std::endl<<reading<<std::endl<<std::endl;

    std::cout<<"bad bus:\t"<<PI_BAD_I2C_BUS<<std::endl;
    std::cout<<"bad addr:\t"<<PI_BAD_I2C_BUS<<std::endl;
    std::cout<<"bad flag:\t"<<PI_BAD_I2C_BUS<<std::endl;
    std::cout<<"bad hndl:\t"<<PI_BAD_I2C_BUS<<std::endl;
    std::cout<<"bad open:\t"<<PI_BAD_I2C_BUS<<std::endl;

    gpioTerminate();
    return 0;
}
