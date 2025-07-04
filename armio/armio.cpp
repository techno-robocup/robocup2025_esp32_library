#include "armio.hpp"

ARMIO::ARMIO() {}
ARMIO::ARMIO(std::int8_t _ArmPin, std::int8_t _ArmFeedbackPin, std::int8_t _WirePin)
    : ArmPIN(_ArmPin), ArmFeedbackPIN(_ArmFeedbackPin), WirePIN(_WirePin) {
  pinMode(ArmPIN, OUTPUT);
  pinMode(ArmFeedbackPIN, INPUT);
  wire.attach(WirePIN);
}

void ARMIO::arm_setposition(const int8_t& goal) {
  int feedback = analogRead(ArmFeedbackPIN);
  if (feedback > goal) {
    analogWrite(ArmPIN, goal);
  } else {
    analogWrite(ArmPIN, goal);  // TODO: FIx PWM
  }
}

void ARMIO::wire_tension(const bool& tension) {
  if (tension) {
    wire.write(ARMIO::loose);
  } else {
    wire.write(ARMIO::tight);
  }
}
