#ifndef _MESSAGESCREEN_H_
#define _MESSAGESCREEN_H_

#include <Wire.h>
#include "SSD1306Wire.h"
#include "Screen.h"
#include <Arduino.h>

class MessageScreen : public Screen {
private:
  String mMessage;
  const String mAckMessage;

public:
  MessageScreen(SSD1306Wire *display, const String message,
                const String ackMessage);
  ~MessageScreen();
  void draw();
  inline void setMessage(String &message) { mMessage = message; }
};

#endif //_MESSAGESCREEN_H_
