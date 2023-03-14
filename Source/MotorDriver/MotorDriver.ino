#include "Motor.h"

Motor motor(11, 10, 9);

void setup() {
  // put your setup code here, to run once:
  motor.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  motor.set_speed(1.0);

  delay(3000);

  motor.set_speed(-1.00);

  delay(3000);
}
