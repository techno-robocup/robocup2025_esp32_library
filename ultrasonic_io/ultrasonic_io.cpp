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
  // 0.000001 * 3400 / 2.0 = 0.0017, so multiply by 17 and divide by 10000
  duration = (duration * 17.0) / 10000.0;
  *values = duration;
}
