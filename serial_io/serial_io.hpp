#include <Arduino.h>
class SerialIO {
  public:
    SerialIO();
    Message sendMessage(const Message& message);
    Message receiveMessage();
    bool isMessageAvailable();
    void init();
  private:
    bool isReady;
};

class Message {
  public:
    Message(long long id, const String& message);
    long long getId();
    String getMessage();
  private:
    long long id;
    String message;
};