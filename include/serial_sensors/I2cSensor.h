#include "SerialSensor.h"

#include <cstdint>

template<class T>
class I2cSensor : public SerialSensor
{
    private:
        static I2C_FLAGS = 0;

        uint8_t i2c_bus;
        uint8_t i2c_addr;

        virtual void fill_data(T &data) = 0;
        uint8_t get_data(uint8_t addr);

    public:
        I2cSensor(uint8_t bus, uint8_t addr);
        ~I2cSensor();
        void Start() override;
        void Stop() override;
        T Read() override;
}