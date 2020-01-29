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

int thermistorPin2 = 2;
int Vo2;
float D1 = 10000;
float logD2, D2, T2;
float j1 = 1.009249522e-03, j2 = 2.378405444e-04, j3 = 2.019202697e-07;




void setup() {
  Serial.begin(9600);
}

void loop() {
  Signal = analogRead(pulseSensor);
  Vo = analogRead(thermistorPin);
  Vo2 = analogRead(thermistorPin2);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  D2 = D1 * (1023.0 / (float)Vo2 - 1.0);
  logR2 = log(R2);
  logD2 = log(D2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T2 = (1.0 / (j1 + j2*logD2 + j3*logD2*logD2*logD2));
  T = T - 273.15;
  T2 = T2 - 273.15;
  T = (T * 9.0)/ 5.0 + 32.0;
  T2 = (T2 * 9.0)/ 5.0 + 32.0;
  
  
  Serial.print(Signal + 500);
  Serial.print(" ");
  Serial.print(T);
  Serial.print(" ");
  Serial.println(T2);
  
  delay(100);
}

/*
 * green = thermistor mask
 * blue = pulse sensor
 * red = forehead thermistor
 */

/*
 * Equip Procedure
 * 
 * pulse sensor attached to finger - side with heart facing fingertip - good
 * mask on face
 * body temp thermistor attached to forehead - good
 * 
 */
