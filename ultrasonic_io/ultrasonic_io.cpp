#include "ultrasonic_io.hpp"

UltrasonicIO::UltrasonicIO(int _trig, int _echo) : trig(_trig), echo(_echo) {
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void UltrasonicIO::read(long* values) {
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duration = pulseIn(echo, HIGH);
  // Convert to centimeters: (duration * 0.034) / 2
  // Simplified: (duration * 17) / 1000
  duration = (duration * 17) / 1000;
  *values = duration;
  return;
}
