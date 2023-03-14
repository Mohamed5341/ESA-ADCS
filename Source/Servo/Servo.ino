#include "myServo.h"

myServo servo;

int val;
char arr[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.init(9);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.readBytesUntil(',', arr, 3);
    arr[3] = '\n';
    Serial.println(arr);
    servo.set_speed(atoi(arr));
    delay(15);
}
