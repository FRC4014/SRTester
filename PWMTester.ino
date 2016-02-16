const int pins[] = {5, 6}; //must be 3, 5, 6, 9, 10, or 11
int value = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("you called, master?\n");
  delay(1000);
  Serial.println("type in a percent, and I will output your PWM.\n");
  
}


void loop() {
  int PWMvalue = value * (double)255/(double)100; //scale up to 255
  
  for (int i=0; i<sizeof(pins); i++) {
    analogWrite(pins[i], value);
  }

  if (Serial.available() > 1) {
    long proposedValue = Serial.parseInt();
    if (proposedValue >= -100 && proposedValue <= 100) {
      value = proposedValue;
      Serial.print("of course. value set to ");
      Serial.print(value);
      Serial.println("%");
      }
    else {
      Serial.println("oh dear. that won't do.");
    }
  }
}
