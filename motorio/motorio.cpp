#include <motorio.hpp>

MOTORIO::MOTORIO(const std::int8_t& _PIN) : PIN(_PIN), prev_msec(micros()), is_running(false){ pinMode(PIN, OUTPUT); }

MOTORIO::MOTORIO() {}
void MOTORIO::run_msec(const int& msec) {
  if(is_running) {
    if(micros() - prev_msec > msec) {
      digitalWrite(PIN, LOW);
      is_running = false;
      prev_msec = micros();
    }
  }
  else {
    digitalWrite(PIN, HIGH);
    is_running = true;
    prev_msec = micros();
  }
  return;
}
