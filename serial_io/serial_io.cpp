#include "serial_io.hpp"

SerialIO::SerialIO() : isReady(false) { init(); }

void SerialIO::init() { Serial.begin(9600); }

void SerialIO::sendMessage(const Message& message) {
  Serial.println(String(message.getId()) + String(" ") + String(message.getMessage()));
  return;
}

Message SerialIO::receiveMessage() {
  long long id = -1;
  String message = "";
  while (Serial.available()) {
    String str = Serial.readStringUntil('\n');
    int id_end = str.indexOf(' ');
    id = str.substring(0, id_end).toInt();
    message = str.substring(id_end + 1);
    return Message(id, message);
  }
  return Message(id, message);
}

bool SerialIO::isMessageAvailable() { return Serial.available() > 0; }

Message::Message(long long Id, const String& Message) : id(Id), message(Message) {}

long long Message::getId() const { return id; }

String Message::getMessage() const { return message; }