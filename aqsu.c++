#include <WiFi.h>
#include <ESP32Servo.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_MPU6050.h>

Servo armServo;
Adafruit_MPU6050 mpu;

const int motorL_PWM = 18;
const int motorR_PWM = 19;
const int motorL_DIR = 21;
const int motorR_DIR = 22;
const int armPin = 5;
const int turbiditySensor = 34;
const int depthSensor = 35;

void setup() {
  pinMode(motorL_PWM, OUTPUT);
  pinMode(motorR_PWM, OUTPUT);
  pinMode(motorL_DIR, OUTPUT);
  pinMode(motorR_DIR, OUTPUT);
  
  armServo.attach(armPin);
  armServo.write(0);
  
  Wire.begin();
  mpu.begin();
  
  analogReadResolution(12);
}

void drive(int leftSpeed, int rightSpeed) {
  digitalWrite(motorL_DIR, leftSpeed >= 0 ? HIGH : LOW);
  digitalWrite(motorR_DIR, rightSpeed >= 0 ? HIGH : LOW);
  analogWrite(motorL_PWM, abs(leftSpeed));
  analogWrite(motorR_PWM, abs(rightSpeed));
}

void processWasteCollection() {
  drive(0, 0);
  delay(500);
  armServo.write(180);
  delay(3000);
  armServo.write(0);
  delay(1000);
}

void loop() {
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  
  int turbidity = analogRead(turbiditySensor);
  int depth = analogRead(depthSensor);
  
  if (abs(a.acceleration.x) > 2.0 || abs(a.acceleration.y) > 2.0) {
    drive(150, 150);
  } else if (turbidity > 2500 && depth < 3000) {
    processWasteCollection();
  } else {
    drive(200, 200);
  }
  
  delay(100);
}

```
