#include <Arduino.h>
int n=13;
void setup() {
  pinMode(n,OUTPUT);
  pinMode(7,OUTPUT);
  // put your setup code here, to run once:
}

void loop() {
  digitalWrite(n,HIGH);
  digitalWrite(7,HIGH);
  delay(500);
  digitalWrite(n,LOW);
  digitalWrite(7,LOW);
  delay(500);
  // put your main code here, to run repeatedly:
}
