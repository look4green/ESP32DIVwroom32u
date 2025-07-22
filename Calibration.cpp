#include "Calibration.h"

// Define screen touch zones based on UI layout
struct TouchZone {
  int x_min;
  int x_max;
  int y_min;
  int y_max;
};

TouchZone menuZones[] = {
  {10, 230, 30, 60},   // WiFi Scanner
  {10, 230, 60, 90},   // Deauth Attack
  {10, 230, 90, 120},  // Packet Sniff
  {10, 230, 120, 150}, // Settings
  {10, 230, 150, 180}  // Status Screen
};

void initTouchZones() {
  // Optional: load zones from SD or config
}

int getTouchZone(int x, int y) {
  for (int i = 0; i < sizeof(menuZones) / sizeof(TouchZone); i++) {
    if (x >= menuZones[i].x_min && x <= menuZones[i].x_max &&
        y >= menuZones[i].y_min && y <= menuZones[i].y_max) {
      return i;
    }
  }
  return -1;  // No match
}
