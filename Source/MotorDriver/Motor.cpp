/*
 * L298N Motor Driver Library
 */

#include "Motor.h"

Motor::Motor(){
  ENA = 11;
  IN1 = 10;
  IN2 = 9;
}

Motor::Motor(int ENA_pin, int IN1_pin, int IN2_pin){
  ENA = ENA_pin;
  IN1 = IN1_pin;
  IN2 = IN2_pin;
}

void Motor::init(){
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
}

void Motor::set_speed(float s){
  digitalWrite(IN1, s>0);
  digitalWrite(IN2, s<0);

  analogWrite(ENA, abs(s)*255);
}
 
