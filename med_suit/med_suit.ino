/*
 * Programmer: Braeden
 * Program: Medical sensor suit
 * 
 * The suit will have many sensors that monitor a person's vitals
 * Sensors will be added as I progress
 */

int thermistorPin = 0;
int Vo;
float R1 = 10000;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

int pulseSensor = 1;
int Signal;



void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(pulseSensor);
  Vo = analogRead(thermistorPin);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0; 
  
  
  Serial.print(Signal);
  Serial.print(" ");
  Serial.println(T);
  
  delay(500);
}
