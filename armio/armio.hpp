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
  const int WIRE_THIN = 45;  // FIXME: 適切な角度に変更
  const int WIRE_LOOSE = 135;
  Servo wireServo;
};

#endif
