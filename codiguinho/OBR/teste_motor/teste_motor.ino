#include <Servo.h>
Servo motor;

void setup() {
  motor.attach(7);
}
void loop() {
  motor.write(180);
  delay(1000);
  motor.write(1);
  delay(1000);
  motor.write(90);
  delay(1000);

}
