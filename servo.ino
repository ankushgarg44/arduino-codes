#include <Servo.h>

Servo myServo;
int servoPin = 9;

void setup() {
  myServo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  myServo.write(0);
  Serial.println("0 degrees");
  delay(1000);

  myServo.write(90);
  Serial.println("90 degrees");
  delay(1000);

  myServo.write(180);
  Serial.println("180 degrees");
  delay(1000);
}