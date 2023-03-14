/*
 * Servo Example Library
 */
#ifndef _MY_SERVO_H_
#define _MY_SERVO_H_

#include <Arduino.h>
#include <Servo.h>


class myServo{
  public:
    myServo();
    void init(int pin);
    void set_speed(float value);
  private:
    Servo servo;
};

#endif
 
