#include <motorio.hpp>

MOTORIO::MOTORIO(const std::int8_t& _PIN) : PIN(_PIN) { pinMode(PIN, OUTPUT); }

MOTORIO::MOTORIO() {}
void MOTORIO::run_msec(const int& msec) {
  digitalWrite(PIN, HIGH);
  delayMicroseconds(msec);
  digitalWrite(PIN, LOW);
  return;
}

void setup() {
  pinMode(tyre_1, OUTPUT);
  pinMode(tyre_2, OUTPUT);
  pinMode(tyre_3, OUTPUT);
  pinMode(tyre_4, OUTPUT);
}
