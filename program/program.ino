#include <Servo.h>

const byte dits = 5;

int pinsPWM[dits] = {3,5,6,9,10};        
int sensor[dits] = {A0,A1,A2,A3,A4};     

Servo servoMotor[dits];                  

int valorSensor[dits];                   
int angleServo[dits];

const int lecturaMax = 1024;             
const int lecturaMin = 0;                

const int angleMax = 180;
const int angleMin = 0;

void setup() {
  for (int i = 0; i<dits; i++) {
    servoMotor[i].attach(pinsPWM[i]);
    pinMode(sensor[i], INPUT);
    Serial.begin(9600);
  }
}

void loop() {
  for (int i = 0; i<dits; i++) {
      valorSensor[i] = analogRead(sensor[i]);
  }
  
  for (int i = 0; i<dits; i++) {
    angleServo[i] = map(valorSensor[i], lecturaMin, lecturaMax, angleMin, angleMax);
  }
  
  for (int i = 0; i<dits; i++) {
    servoMotor[i].write(angleServo[i]);
    delay(15);
  }
  
  delay(100); 
}
