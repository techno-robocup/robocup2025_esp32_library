#include <motorio.hpp>

MOTORIO::MOTORIO(const std::int8_t& _PIN, const int& _interval)
    : PIN(_PIN), interval(_interval), prev_msec(micros()) {
  pinMode(PIN, OUTPUT);
}

MOTORIO::MOTORIO() {}

void MOTORIO::run_msec(const int& msec) {
  if (micros() - prev_msec < interval) {
    return;
  }
  digitalWrite(PIN, HIGH);
  delay(msec);
  digitalWrite(PIN, LOW);
  prev_msec = micros();
}
