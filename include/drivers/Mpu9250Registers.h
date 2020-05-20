#ifndef MPU_9250_REGISTERS_H
#define MPU_9250_REGISTERS_H

#include <cstdint>

enum Mpu9250Registers : uint8_t {
    SELF_TEST_X_GYRO = 0x00,        // Interface R/W
    SELF_TEST_Y_GYRO = 0x01,        // Interface R/W
    SELF_TEST_Z_GYRO = 0x02,        // Interface R/W
    SELF_TEST_X_ACCEL = 0x0D,       // Interface R/W
    SELF_TEST_Y_ACCEL = 0x0E,       // Interface R/W
    SELF_TEST_Z_ACCEL = 0x0F,       // Interface R/W

    XG_OFFSET_H = 0x13,             // Interface R/W
    XG_OFFSET_L = 0x14,             // Interface R/W
    YG_OFFSET_H = 0x15,             // Interface R/W
    YG_OFFSET_L = 0x16,             // Interface R/W
    ZG_OFFSET_H = 0x17,             // Interface R/W
    ZG_OFFSET_L = 0x18,             // Interface R/W

    SMPLRT_DIV = 0x19,              // Interface R/W
    CONFIG = 0x1A,                  // Interface R/W
    GYRO_CONFIG = 0x1B,             // Interface R/W
    ACCEL_CONFIG_1 = 0x1C,          // Interface R/W
    ACCEL_CONFIG_2 = 0x1D,          // Interface 2
    LP_ACCEL_ODR = 0x1E,            // Interface R/W
    WOM_THR = 0x1F,                 // Interface R/W
    FIFO_EN = 0x23,                 // Interface R/W

    I2C_MST_CTRL = 0x24,            // Interface R/W
    I2C_SLV0_ADDR = 0x25,           // Interface R/W
    I2C_SLV0_REG = 0x26,            // Interface R/W
    I2C_SLV0_CTRL = 0x27,           // Interface R/W
    I2C_SLV1_ADDR = 0x28,           // Interface R/W
    I2C_SLV1_REG = 0x29,            // Interface R/W
    I2C_SLV1_CTRL = 0x2A,           // Interface R/W
    I2C_SLV2_ADDR = 0x2B,           // Interface R/W
    I2C_SLV2_REG = 0x2C,            // Interface R/W
    I2C_SLV2_CTRL = 0x2D,           // Interface R/W
    I2C_SLV3_ADDR = 0x2E,           // Interface R/W
    I2C_SLV3_REG = 0x2F,            // Interface R/W
    I2C_SLV3_CTRL = 0x30,           // Interface R/W
    I2C_SLV4_ADDR = 0x31,           // Interface R/W
    I2C_SLV4_REG = 0x32,            // Interface R/W
    I2C_SLV4_DO = 0x33,             // Interface R/W
    I2C_SLV4_CTRL = 0x34,           // Interface R/W
    I2C_SLV4_DI = 0x35,             // Interface R
    I2C_MST_STATUS = 0x36,          // Interface R

    INT_PIN_CFG = 0x37,             // Interface R/W
    INT_ENABLE = 0x38,              // Interface R/W
    INT_STATUS = 0x3A,              // Interface R

    ACCEL_XOUT_H = 0x3B,            // Interface R
    ACCEL_XOUT_L = 0x3C,            // Interface R
    ACCEL_YOUT_H = 0x3D,            // Interface R
    ACCEL_YOUT_L = 0x3E,            // Interface R
    ACCEL_ZOUT_H = 0x3F,            // Interface R
    ACCEL_ZOUT_L = 0x40,            // Interface R

    TEMP_OUT_H = 0x41,              // Interface R
    TEMP_OUT_L = 0x42,              // Interface R

    GYRO_XOUT_H = 0x43,             // Interface R
    GYRO_XOUT_L = 0x44,             // Interface R
    GYRO_YOUT_H = 0x45,             // Interface R
    GYRO_YOUT_L = 0x46,             // Interface R
    GYRO_ZOUT_H = 0x47,             // Interface R
    GYRO_ZOUT_L = 0x48,             // Interface R

    EXT_SENS_DATA_00 = 0x49,        // Interface R
    EXT_SENS_DATA_01 = 0x4A,        // Interface R
    EXT_SENS_DATA_02 = 0x4B,        // Interface R
    EXT_SENS_DATA_03 = 0x4C,        // Interface R
    EXT_SENS_DATA_04 = 0x4D,        // Interface R
    EXT_SENS_DATA_05 = 0x4E,        // Interface R
    EXT_SENS_DATA_06 = 0x4F,        // Interface R
    EXT_SENS_DATA_07 = 0x50,        // Interface R
    EXT_SENS_DATA_08 = 0x51,        // Interface R
    EXT_SENS_DATA_09 = 0x52,        // Interface R
    EXT_SENS_DATA_10 = 0x53,        // Interface R
    EXT_SENS_DATA_11 = 0x54,        // Interface R
    EXT_SENS_DATA_12 = 0x55,        // Interface R
    EXT_SENS_DATA_13 = 0x56,        // Interface R
    EXT_SENS_DATA_14 = 0x57,        // Interface R
    EXT_SENS_DATA_15 = 0x58,        // Interface R
    EXT_SENS_DATA_16 = 0x59,        // Interface R
    EXT_SENS_DATA_17 = 0x5A,        // Interface R
    EXT_SENS_DATA_18 = 0x5B,        // Interface R
    EXT_SENS_DATA_19 = 0x5C,        // Interface R
    EXT_SENS_DATA_20 = 0x5D,        // Interface R
    EXT_SENS_DATA_21 = 0x5E,        // Interface R
    EXT_SENS_DATA_22 = 0x5F,        // Interface R
    EXT_SENS_DATA_23 = 0x60,        // Interface R

    I2C_SLV0_DO = 0x63,             // Interface R/W
    I2C_SLV1_DO = 0x64,             // Interface R/W
    I2C_SLV2_DO = 0x65,             // Interface R/W
    I2C_SLV3_DO = 0x66,             // Interface R/W

    I2C_MST_DELAY_CTRL = 0x67,      // Interface R/W
    SIGNAL_PATH_RESET = 0x68,       // Interface R/W
    MOT_DETECT_CTRL = 0x69,         // Interface R/W
    USER_CTRL = 0x6A,               // Interface R/W

    PWR_MGMT_1 = 0x6B,              // Interface R/W
    PWR_MGMT_2 = 0x6C,              // Interface R/W

    FIFO_COUNTH = 0x72,             // Interface R/W
    FIFO_COUNTL = 0x73,             // Interface R/W
    FIFO_R_W = 0x74,                // Interface R/W
    WHO_AM_I = 0x75,                // Interface R

    XA_OFFSET_H = 0x77,             // Interface R/W
    XA_OFFSET_L = 0x78,             // Interface R/W
    YA_OFFSET_H = 0x7A,             // Interface R/W
    YA_OFFSET_L = 0x7B,             // Interface R/W
    ZA_OFFSET_H = 0x7D,             // Interface R/W
    ZA_OFFSET_L = 0x7E,             // Interface R/W
};

#endif // MPU_9250_REGISTERS_H