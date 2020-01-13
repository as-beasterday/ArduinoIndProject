/*
 * Programmer: Braeden
 * Program: Medical sensor suit
 * 
 * The suit will have many sensors that monitor a person's vitals
 * Sensors will be added as I progress
 */

int pulseSensor = 0;
int led13 = 13;
int Signal;
int threshold = 550;

void setup() {
  pinMode(led13, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  Signal = analogRead(pulseSensor);
  Serial.println(Signal);
  if(Signal > threshold){
    digitalWrite(led13,HIGH);
  }else{
    digitalWrite(led13,LOW);
  }
}
