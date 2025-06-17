#include <arm.hpp>

constexpr int wire_pin = 32;
constexpr int arm_pin = 17;
constexpr int arm_feedback = 34;

ARMIO wire(wire_pin, 0);
ARMIO arm(arm_pin, 1);
void ARMIO::write(int degree) {
  int pulse = map(degree, 0, 180, 500, 2500);
  ledcWrite(PIN, pulse);
}

void Arm() {
  wire.write(90);
  arm.write(90);
}
