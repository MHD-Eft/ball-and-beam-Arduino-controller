//Mahdieh Eftekharian
#include "NewPing.h"
#define TRIGGER_PIN 5
#define ECHO_PIN 6
#define MAX_DISTANCE 400 
int enA =3;
int in1=7;
int in2=8;
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
float duration, distance;
int pwm;
int pwm15=100;


void setup() {
  Serial.begin(19200);
  pinMode(enA, OUTPUT); //ENA
  pinMode(in2, OUTPUT); //IN2
  pinMode(in1, OUTPUT); //IN1  
}


void loop() {

  
  distance = sonar.ping_cm();
  Serial.print("Distance = ");
  Serial.print(distance);
  Serial.println(" cm");
  Serial.print("  pwm = ");
  Serial.print(pwm);

  if (distance >=15)
  {
  pwm=pwm15;
  digitalWrite(in2, HIGH);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  delay(10);
  
  }

  
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  
  if(distance >= 14  && distance <15)
  {
  pwm=100;
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  delay(4);
  }

  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  
   if(distance >= 5  && distance <12)
  {
  pwm=0;
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  }

  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);

   if(0 <= distance && distance <2)
  {
  pwm=80;
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  delay(1);
  }
  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);
  
   if(distance ==0)
  {
   pwm15=95;
   pwm=100;
  digitalWrite(in2, LOW);
  digitalWrite(in1, HIGH);
  analogWrite(enA, pwm);
   delay(2);
  }

  digitalWrite(in2, LOW);
  digitalWrite(in1, LOW);
  analogWrite(enA, pwm);

}
