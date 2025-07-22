#ifndef CALIBRATION_H
#define CALIBRATION_H

#include <Arduino.h>

void initTouchZones();
int getTouchZone(int x, int y);  // Returns index of tapped menu item

#endif
