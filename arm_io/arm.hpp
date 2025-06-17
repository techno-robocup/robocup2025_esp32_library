#include <Arduino.h>

class ARMIO {
 public:
  ARMIO(int pin, int channel) : PIN(pin), CHANNEL(channel) {
    pinMode(PIN, OUTPUT);
    ledcSetup(CHANNEL, 50, 16);
    ledcAttachPin(PIN, CHANNEL);
  }

  void write(int degree) {
    int pulse = map(degree, 0, 180, 1638, 8192);
    ledcWrite(CHANNEL, pulse);
  }

 private:
  int PIN;
  int CHANNEL;
};
