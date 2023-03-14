#include "MPU6050.h"

MPU6050 mpu6050;

float gyro[3], accl[3], temp;

void setup(){
  mpu6050.init();
  Serial.begin(9600);
}
void loop(){
  mpu6050.get_gyro(gyro);
  mpu6050.get_accl(accl);

  Serial.print("Gyro : ");
  for(int i = 0; i<3; i++){
    Serial.print(gyro[i]);
    Serial.print('\t');
  }
  Serial.println(" ");
  Serial.print("Gyro : ");
  for(int i = 0; i<3; i++){
    Serial.print(accl[i]);
    Serial.print('\t');
  }
  Serial.println(" ");
  Serial.print("Temp = ");Serial.println(mpu6050.get_temp());
  Serial.println(" ");

  delay(500);
}
