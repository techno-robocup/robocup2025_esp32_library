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
  duration *= 0.000001 * 3400;
  duration /= 2.0;
  *values = duration;
}