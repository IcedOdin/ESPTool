#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <OLEDDisplay.h>
#include <Wire.h>
#include "SSD1306Wire.h"
#include <Arduino.h>

#define DISPLAY_HEIGHT 64
#define SCREEN_HEIGHT 50
#define SCREEN_WIDTH 128
#define SCREEN_START_X 0
#define SCREEN_START_Y ((DISPLAY_HEIGHT) - (SCREEN_HEIGHT))

class Screen {
private:
protected:
  SSD1306Wire *mDisplay;

public:
  Screen(SSD1306Wire *display) : mDisplay(display) {}
  virtual ~Screen(){};
  virtual void draw() = 0;
  inline SSD1306Wire *getDisplay() { return mDisplay; }

  void clear() {
    mDisplay->setColor(BLACK);
    mDisplay->fillRect(SCREEN_START_X, SCREEN_START_Y, SCREEN_WIDTH,
                       SCREEN_HEIGHT);
    mDisplay->setColor(WHITE);
  }

  inline String trimStringToLength(String input, int maxLength) {
    String empty = "";
    if (maxLength <= 0) {
      return empty;
    }

    while (mDisplay->getStringWidth(input) > maxLength) {
      int charsLeft = input.length();
      if (charsLeft <= 4) {
        return empty;
      }
      input.remove(charsLeft - 4);
      input += "...";
    }

    return input;
  }
};

#endif //_SCREEN_H_
