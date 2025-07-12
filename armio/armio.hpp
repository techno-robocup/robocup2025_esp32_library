#pragma once
#ifndef __ROBOT__ARMIO__HPP
#define __ROBOT__ARMIO__HPP 1

#include <Arduino.h>
#include <ESP32Servo.h>
#include "motorio.hpp"
class ARMIO : public MOTORIO {
 public:
  ARMIO();
  ARMIO(const std::int8_t&, const std::int8_t&,
        const std::int8_t&);  // TODO: arm_pin,arm_feedback_pin,wire_pin
  void run_msec(const int&) override;
  void wire_tension_function(const bool&);
  void read_arm_feedback();

 private:
  std::int8_t ARM_PIN;
  std::int8_t ARM_FEEDBACK_PIN;
  std::int8_t WIRE_PIN;
  int arm_goal_position;
  int arm_current_position;
  const int WIRE_THIN = 0;  // FIXME: edit value
  const int WIRE_LOOSE = 0;
  Servo wireServo;
};

#endif
