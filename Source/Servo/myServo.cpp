#include "myServo.h"

myServo::myServo(){
}

void myServo::init(int pin){
  servo.attach(pin);
}

void myServo::set_speed(float value){
  float rpm = 0.92 * value + 92;
  servo.write(rpm);
}
