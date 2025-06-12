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

void SerialIO::sendMessage(const Message& message) {
  Serial.println(String(message.getID()) + String(" ") + String(message.getMessage()));
  return;
}

Message SerialIO::receiveMessage() {
  String str = Serial.readStringUntil('\n');
  int id_end = str.indexOf(' ');
  long long id = str.substring(0, id_end).toInt();
  String message = str.substring(id_end + 1);
  return Message(id, message);
}

bool SerialIO::isMessageAvailable() { return Serial.available() > 0; }
