#ifndef _LOADINGSCREEN_H_
#define _LOADINGSCREEN_H_

#include "SSD1306Wire.h"
#include "Screen.h"
#include <Arduino.h>

#define INDETERMINATE -1

class LoadingScreen : public Screen {
private:
  int mProgress;
  const String mMessage;
  long mLastUpdateTime;
  int mLastIndeterminateProgress;

public:
  LoadingScreen(SSD1306Wire *display, const String message);
  ~LoadingScreen();
  void draw();
  inline void setProgress(int newProgress) { mProgress = newProgress; }
};

#endif //_LOADINGSCREEN_H_
