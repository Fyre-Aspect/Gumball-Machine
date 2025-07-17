#include <Servo.h>

Servo micro_servo;
const int ULTRASONIC_TRIGGER = 9;
const int ULTRASONIC_ECHO = 8;
const int MICRO_SERVO_SIGNAL = 13;

const int DISTANCE_VALUE = 20;

const int DURATION = 1500;
float ultrasonic_burst(){
  digitalWrite(ULTRASONIC_TRIGGER,LOW);
  delayMicroseconds(2);
  digitalWrite(ULTRASONIC_TRIGGER,HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRASONIC_TRIGGER,LOW);
  
  return pulseIn(ULTRASONIC_ECHO,HIGH);
}

void setup() {
  pinMode(ULTRASONIC_TRIGGER,OUTPUT);
  pinMode(ULTRASONIC_ECHO,INPUT);
  micro_servo.attach(MICRO_SERVO_SIGNAL);
  
  Serial.begin(9600);
  
}

void loop() {
  float duration, distance;
  
  duration = ultrasonic_burst();
  
  distance = (duration + 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if (distance < 300) {
    micro_servo.write();
    delay(DURATION);
    micro_servo.write(90);
    delay(DURATION);
  }
}

