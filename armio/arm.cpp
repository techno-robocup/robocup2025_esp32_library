#include <arm.hpp>

constexpr int arm_feedback = 34, arm_pulse = 17;
constexpr int wire_SIG = 32;

void setup() {
  pinMode(arm_feedback, INPUT);
  pinMode(arm_pulse, OUTPUT);
  pinMode(wire_SIG, OUTPUT);
}

ARMIO::ARMIO(const std::int8_t& _PIN) : PIN(_PIN) { pinMode(PIN, OUTPUT); }

ARMIO::ARMIO() {}

void ARMIO::arm_position(const int& tension) {
  if (tension = 1) {
    Servo.write(180);
  } else if (tension = 0) {
    Servo.write(0);
  } else {
    return;
  }
}
