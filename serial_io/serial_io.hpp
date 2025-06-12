#include <Arduino.h>
class SerialIO {
  public:
    SerialIO();
    void sendMessage(const String& message);
    void sendMessage(const char* message);
    String receiveMessage();
    bool isMessageAvailable();
    void init();
  private:
    bool isReady;
};
