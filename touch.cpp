
#include "Touchscreen.h"
#include <XPT2046_Touchscreen.h>
#include <SPI.h>

// Customize based on your wiring
#define TOUCH_CS_PIN 21
#define TOUCH_IRQ_PIN 22

XPT2046_Touchscreen ts(TOUCH_CS_PIN, TOUCH_IRQ_PIN);
TS_Point lastTouch;
unsigned long lastTouchTime = 0;
bool tapped = false;

void initTouchscreen() {
  SPI.begin();
  ts.begin();
  ts.setRotation(1);
}

void updateTouch() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    if (millis() - lastTouchTime > 150) {  // debounce 150ms
      lastTouch = p;
      tapped = true;
      lastTouchTime = millis();
    }
  } else {
    tapped = false;
  }
}

bool isTouched() {
  return ts.touched();
}

int getTouchX() {
  return lastTouch.x;
}

int getTouchY() {
  return lastTouch.y;
}

bool touchClicked() {
  if (tapped) {
    tapped = false;
    return true;
  }
  return false;
}
