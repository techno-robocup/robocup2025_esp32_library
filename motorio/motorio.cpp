#include <motorio.hpp>

MOTORIO::MOTORIO(const std::int8_t& _PIN, const int& _interval) : PIN(_PIN), interval(_interval), prev_msec(micros()), is_running(false){ pinMode(PIN, OUTPUT); }

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
    if(micros() - prev_msec >= interval) {
      digitalWrite(PIN, HIGH);
      is_running = true;
      prev_msec = micros();
    }
  }
  return;
}
