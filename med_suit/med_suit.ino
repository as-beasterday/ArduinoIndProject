/*
 * Programmer: Braeden
 * Program: Medical sensor suit
 * 
 * The suit will have many sensors that monitor a person's vitals
 * Sensors will be added as I progress
 */

int pulseSensor = 0;
int Signal;

volatile int BPM;
volatile int IBI = 600;
volatile boolean Pulse = false;
volatile boolean QS = false;

static boolean serialVisual = true;

volatile int rate[10];
volatile unsigned long sampleCounter = 0;
volatile unsigned long lastBeatTime = 0;
volatile int P = 512;
volatile int T = 512;
volatile int thresh = 525;
volatile int amp = 100;
volatile boolean firstBeat = true;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  Signal = analogRead(pulseSensor);
  Serial.println(Signal);

  delay(100);
}
