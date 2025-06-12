#include "serial_io.hpp"

SerialIO::SerialIO() : isReady(false) {
  init();
}

void SerialIO::init() {
  Serial.begin(9600);
  Serial.flush();
  while (true) {
    if (Serial.available()) {
      String str = Serial.readStringUntil('\n');
      if (str == "[RASPI] READY?") {
        Serial.println("[ESP32] READY");
      } else if (str == "[RASPI] READY CONFIRMED") {
        isReady = true;
        break;
      }
    }
  }
}

void SerialIO::sendMessage(const String& message) { Serial.println(message); }

void SerialIO::sendMessage(const char* message) { Serial.println(message); }

String SerialIO::receiveMessage() { return Serial.readStringUntil('\n'); }

bool SerialIO::isMessageAvailable() { return Serial.available() > 0; }
