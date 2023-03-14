/*
 * MPU6050 Libaray for RAW data
 */
#ifndef _MPU6050_H_
#define _MPU6050_H_

#include <Arduino.h>
#include <Wire.h>

#define ACCEL_XOUT_H 0x3B
#define ACCEL_XOUT_L 0x3C
#define ACCEL_YOUT_H 0x3D
#define ACCEL_YOUT_L 0x3E
#define ACCEL_ZOUT_H 0x3F
#define ACCEL_ZOUT_L 0x40
#define TEMP_OUT_H 0x41
#define TEMP_OUT_L 0x42
#define GYRO_XOUT_H 0x43
#define GYRO_XOUT_L 0x44
#define GYRO_YOUT_H 0x45
#define GYRO_YOUT_L 0x46
#define GYRO_ZOUT_H 0x47
#define GYRO_ZOUT_L 0x48
#define PWR_MGMT_1 0x6B

#define MPU_ADDRESS 0x68

class MPU6050{
  public:
    MPU6050();
    void init();
    void get_gyro(float gyro[]);
    float get_temp();
    void get_accl(float accl[]);
  private:
};

#endif
 
