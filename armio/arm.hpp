#ifndef __ROBOT__ARMIO__HPP
#define __ROBOT__ARMIO__HPP 1
#include <Arduino.h>
#include <ESP32Servo.h> //NOTE: Include

class ARMIO {
 public:
  ARMIO();
  ARMIO(const std::int8_t&);
  ARMIO& operator=(const ARMIO&) = default;
  void wire_pulse(const int& tension);
  void arm_position(const int position) {}

 private:
  std::int8_t PIN;
}
#endif
