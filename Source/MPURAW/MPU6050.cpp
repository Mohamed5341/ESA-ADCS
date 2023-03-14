#include "MPU6050.h"

MPU6050::MPU6050(){}

void MPU6050::init(){
  Wire.begin();

  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(PWR_MGMT_1);
  Wire.write(0);
  Wire.endTransmission();
}

void MPU6050::get_gyro(float gyro[]){
  int16_t g[3];
  
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(GYRO_XOUT_H);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDRESS, 6, true);

  g[0] = Wire.read() << 8 | Wire.read();
  g[1] = Wire.read() << 8 | Wire.read();
  g[2] = Wire.read() << 8 | Wire.read();

  gyro[0] = g[0] / 131.0;
  gyro[1] = g[1] / 131.0;
  gyro[2] = g[2] / 131.0;
}

void MPU6050::get_accl(float accl[]){
  int16_t a[3];
  
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(ACCEL_XOUT_H);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDRESS, 6, true);

  a[0] = Wire.read() << 8 | Wire.read();
  a[1] = Wire.read() << 8 | Wire.read();
  a[2] = Wire.read() << 8 | Wire.read();

  accl[0] = a[0] * 9.8 / 16384.0;
  accl[1] = a[1] * 9.8 / 16384.0;
  accl[2] = a[2] * 9.8 / 16384.0;
}

float MPU6050::get_temp(){
  int16_t temp;
  
  Wire.beginTransmission(MPU_ADDRESS);
  Wire.write(TEMP_OUT_H);
  Wire.endTransmission(false);

  Wire.requestFrom(MPU_ADDRESS, 2, true);

  temp = Wire.read() << 8 | Wire.read();

  return temp / 340.0 + 36.53;
}
