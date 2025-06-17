#include <arm.hpp>

constexpr int wire_pin = 32;
constexpr int arm_pin = 17;
constexpr int arm_feedback = 34;

MOTORIO::MOTORIO(const std::int8_t& _PIN) : PIN(_PIN) { pinMode(PIN, OUTPUT); }

void MOTORIO::write(int degree) {
  int pulse = map(degree, 0, 180, 500, 2500);
  ledcWrite(PIN, pulse);
}

MOTORIO wire(wire_pin);
MOTORIO arm(arm_pin);

// Arm関数
void Arm() {
  wire.write(90);
  arm.write(90);
}
