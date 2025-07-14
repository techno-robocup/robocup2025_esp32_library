#include "armio.hpp"

ARMIO::ARMIO()
    : ARM_PIN(-1)
    , ARM_FEEDBACK_PIN(-1)
    , WIRE_PIN(-1)
    , arm_goal_position(0)
    , arm_current_position(0) {}

ARMIO::ARMIO(const std::int8_t& _ARM_PIN, const std::int8_t& _ARM_FEEDBACK_PIN,
             const std::int8_t& _WIRE_PIN)
    : ARM_PIN(_ARM_PIN)
    , ARM_FEEDBACK_PIN(_ARM_FEEDBACK_PIN)
    , WIRE_PIN(_WIRE_PIN)
    , arm_goal_position(0)
    , arm_current_position(0) {
  pinMode(ARM_PIN, OUTPUT);
  pinMode(ARM_FEEDBACK_PIN, INPUT);
  pinMode(WIRE_PIN, OUTPUT);
  wireServo.attach(WIRE_PIN);
}

void ARMIO::read_arm_feedback() { arm_current_position = analogRead(ARM_FEEDBACK_PIN); }

void ARMIO::arm_set_position(const int& goal) {
  arm_goal_position = goal;
  read_arm_feedback();

  int pwm_value = 128;  // FIXME: 適切な値に調整
  if (arm_goal_position > arm_current_position) {
    analogWrite(ARM_PIN, pwm_value);
  } else if (arm_goal_position < arm_current_position) {
    analogWrite(ARM_PIN, 255 - pwm_value);
  } else {
    analogWrite(ARM_PIN, 0);
  }
}

void ARMIO::wire_tension_function(const bool& wire_option) {
  if (wire_option) {
    wireServo.write(WIRE_THIN);
  } else {
    wireServo.write(WIRE_LOOSE);
  }
}
