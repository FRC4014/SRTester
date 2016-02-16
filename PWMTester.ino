#include <Servo.h>

int value = 0;
Servo controller1, controller2;

void setup() {
  Serial.begin(9600);
  Serial.println("you called, master?\n");
  controller1.attach(5); //associate object with pin
  controller2.attach(6);
  delay(1000);
  Serial.println("type in a percent, and I will output your PWM.\n");
  
}


void loop() {
  int PWMvalue = value * 5 + 1500; //scale up to 1000-2000

  controller1.writeMicroseconds(PWMvalue);
  controller2.writeMicroseconds(PWMvalue);

  if (Serial.available() > 1) {
    long proposedValue = Serial.parseInt();
    if (proposedValue == 0) {
      Serial.println("ah... stop!  yes, right on it.");
      value = 0;
    } else if (proposedValue >= -100 && proposedValue <= 100) {
      value = proposedValue;
      Serial.print("of course. value set to ");
      Serial.print(value);
      Serial.println("%");
    } else {
      Serial.println("oh dear. that won't do.");
    }
  }
}
