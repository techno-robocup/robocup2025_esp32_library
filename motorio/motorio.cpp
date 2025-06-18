#include <motorio.hpp>

constexpr int tyre_1 = 13, tyre_2 = 14, tyre_3 = 15, tyre_4 = 16;

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
