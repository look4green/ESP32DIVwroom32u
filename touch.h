
#ifndef TOUCHSCREEN_H
#define TOUCHSCREEN_H

#include <Arduino.h>

// Touchscreen API
void initTouchscreen();
bool isTouched();
int getTouchX();
int getTouchY();
void updateTouch();          // Polls and stores latest point
bool touchClicked();         // One-time tap detection

#endif
