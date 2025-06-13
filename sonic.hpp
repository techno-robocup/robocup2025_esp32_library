#include <Arduino.h>
#include <Wire.h>
#include <motorio.hpp>

constexpr int trig_1 = 9, trig_2 = 22, trig_3 = 26;
constexpr int echo_1 = 8, echo_2 = 23, echo_3 = 27;

long measure_distance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  long duration = pulseIn(echo, HIGH, 30000);  // tim out over 5m
  return duration * 0.034 / 2;
}

void setup() {
  Serial.begin(115200);

  pinMode(trig_1, OUTPUT);
  pinMode(trig_2, OUTPUT);
  pinMode(trig_3, OUTPUT);

  pinMode(echo_1, INPUT);
  pinMode(echo_2, INPUT);
  pinMode(echo_3, INPUT);
}

void loop() {
  for (int i = 1000; i <= 2000; i++) {
    long d1 = measure_distance(trig_1, echo_1);
    delay(20);
    long d2 = measure_distance(trig_2, echo_2);
    delay(20);
    long d3 = measure_distance(trig_3, echo_3);
    delay(20);

    Serial.print("i: ");
    Serial.print(i);
    Serial.print(" d1: ");
    Serial.print(d1);
    Serial.print(" d2: ");
    Serial.print(d2);
    Serial.print(" d3: ");
    Serial.println(d3);
  }
}
