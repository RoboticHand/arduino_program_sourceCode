#include <Servo.h>

const byte fingers = 5;

int PWMpins[fingers] = {3,5,6,9,10};        
int sensor[fingers] = {A0,A1,A2,A3,A4};     

Servo servoMotor[fingers];                  

int sensorValue[fingers];                   
int servoAngle[fingers];

const int readingMax = 1024;            
const int readingMin = 0;                

const int angleMax = 180;
const int angleMin = 0;

void setup() {
  for (int i = 0; i<fingers; i++) {
    servoMotor[i].attach(PWMpins[i]);
    pinMode(sensor[i], INPUT);
    Serial.begin(9600);
  }
}

void loop() {
  sensorRead();
  calculateAngle();
  writePower();
  
  delay(100);
}

void sensorRead() {
  for (int i = 0; i<fingers; i++) {
      sensorValue[i] = analogRead(sensor[i]);
  }
}

void calculateAngle() {
  for (int i = 0; i<fingers; i++) {
    servoAngle[i] = map(sensorValue[i], readingMin, readingMax, angleMin, angleMax);
  }
}

void writePower() {
  for (int i = 0; i<fingers; i++) {
    servoMotor[i].write(servoAngle[i]);
    delay(15);
  }
}
