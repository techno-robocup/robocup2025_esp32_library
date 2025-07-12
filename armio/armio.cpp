#include "armio.hpp"

ARMIO::ARMIO(const std::int8_t& _ARM_PIN, const std::int8_t& _ARM_FEEDBACK_PIN,
             const std::int8_t& _WIRE_PIN)
    : MOTORIO(_ARM_PIN, 60)
    , ARM_PIN(_ARM_PIN)
    , ARM_FEEDBACK_PIN(_ARM_FEEDBACK_PIN)
    , WIRE_PIN(_WIRE_PIN)
    , arm_goal_position(0)
    , wireServo.attach(WIRE_PIN)
    , arm_current_position(0) {
  pinMode(ARM_PIN, OUTPUT);
  pinMode(ARM_FEEDBACK_PIN, INPUT);
  pinMode(WIRE_PIN, OUTPUT);
}

void ARMIO::read_arm_feedback() { arm_current_position = analogRead(ARM_FEEDBACK_PIN); }

void ARMIO::run_msec(const int goal) {
  arm_goal_position = goal;
  read_arm_feedback();

  int pwm_value = 128;  // FIXME: edit const value
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
    wireServo.write(WIRE_THIN)
  } else {
    wireServo.write(WIRE_LOOSE);
  }
}
