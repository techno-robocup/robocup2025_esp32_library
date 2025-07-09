#include <motorio.hpp>

MOTORIO::MOTORIO(const std::int8_t& _PIN, const int& _interval)
    : PIN(_PIN), interval(_interval), prev_msec(micros()), is_running(false) {
  pinMode(PIN, OUTPUT);
}

MOTORIO::MOTORIO() {}

void MOTORIO::run_msec(const int& msec) {
  unsigned long now = micros();
  if (is_running) {
    if (now - prev_msec >= msec) {
      digitalWrite(PIN, LOW);
      Serial.print("MOTORIO::run_msec LOW ");
      Serial.println(now - prev_msec);
      is_running = false;
      prev_msec = now;
    }
  } else {
    if (now - prev_msec >= interval) {
      digitalWrite(PIN, HIGH);
      Serial.print("MOTORIO::run_msec HIGH ");
      Serial.println(now - prev_msec);
      is_running = true;
      prev_msec = now;
    }
  }
}
