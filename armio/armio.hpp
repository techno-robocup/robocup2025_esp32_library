#pragma once
#ifndef __ROBOT__ARMIO__HPP
#define __ROBOT__ARMIO__HPP 1

#include <Arduino.h>
#include <ESP32Servo.h>

class ARMIO {
 public:
  ARMIO();
  ARMIO(const std::int8_t&, const std::int8_t&, const std::int8_t&);  // arm, feedback, wire
  ARMIO& operator=(const ARMIO&) = default;
  void arm_set_position(const int&);
  void wire_tension_function(const bool&);
  void read_arm_feedback();

 private:
  std::int8_t ARM_PIN;
  std::int8_t ARM_FEEDBACK_PIN;
  std::int8_t WIRE_PIN;
  int arm_goal_position;
  int arm_current_position;
  constexpr int SERVO_CH = 0;
  constexpr int PWM_FREQ = 50;
  constexpr int PWM_RES = 16;
  const uint32_t WIRE_THIN = 1638;
  const uint32_t WIRE_LOOSE = 7864;
};

#endif
