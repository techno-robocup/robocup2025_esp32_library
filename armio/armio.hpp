#ifndef __ROBOT__ARMIO__HPP
#define __ROBOT__ARMIO__HPP

#include <Arduino.h>
#include <ESP32Servo.h>

class ARMIO {
 public:
  ARMIO();
  ARMIO(std::int8_t armPin, std::int8_t armFeedbackPin, std::int8_t wirePin);
  ARMIO& operator=(const ARMIO&) = default;

  void arm_setposition(std::int8_t goal);
  void wire_tension(bool tension);

 private:
  std::int8_t ArmPIN;
  std::int8_t ArmFeedbackPIN;
  std::int8_t WirePIN;
  Servo wire;
  static constexpr int loose = 0;  // TODO: Set correct values
  static constexpr int tight = 180;
};

#endif
