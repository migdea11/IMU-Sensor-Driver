#ifndef MPU_9250_CONFIG_H
#define MPU_9250_CONFIG_H

#include <cmath>
#include <cstdint>

namespace Mpu9250Config
{
    enum I2cAddr
    {
        I2C_ADDR_AD0 = 0x68,
        I2C_ADDR_SD0 = 0x69
    };

    namespace AccConfig
    {
        const uint8_t ACC_ENABLE_X = 1 << 5;
        const uint8_t ACC_ENABLE_Y = 1 << 4;
        const uint8_t ACC_ENABLE_Z = 1 << 3;
        const uint8_t ACC_ENABLE_ALL = ACC_ENABLE_X | ACC_ENABLE_Y | ACC_ENABLE_Z;

        enum AccRangeSelect
        {
            RANGE_2G_BITS = 0,
            RANGE_4G_BITS = 1,
            RANGE_8G_BITS = 2,
            RANGE_16G_BITS = 3
        };
        constexpr inline int8_t getAccRange(AccRangeSelect range, bool is_min)
        {
            int8_t ret_val = std::pow(2, range + 1);
            return is_min ? ret_val * -1 : ret_val;
        }
        const uint8_t ACC_RANGE_MASK = 0b00011000;
        const uint8_t ACC_RANGE_OFFSET = 3;

        enum AccFilterBW {
            BW_460Hz = 0,
            BW_184Hz = 1,
            BW_92Hz = 2,
            BW_41Hz = 3,
            BW_20Hz = 4,
            BW_10Hz = 5,
            BW_5Hz = 6,
            // BW_460Hz = 7 Duplicate
        };
        const uint8_t ACC_FILTER_ENABLE = 0b00001000;
        const uint8_t ACC_FILTER_MASK = 0b00001111; // includes enable bit
    }
}

#endif // MPU_9250_CONFIG_H