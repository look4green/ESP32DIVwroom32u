#include "Encoder.h"
#include "Touchscreen.h"
#include "Display.h"
#include "Menu.h"
#include "AppState.h"
#include "Storage.h"
#include "Splash.h"
#include "Calibration.h"

void setup() {
  Serial.begin(115200);

  initDisplay();
  showSplashScreen();  // Original DIV-style splash

  initEncoder();
  initTouchscreen();
  initStorage();
  initTouchZones();    // Optional: if touch zones are now modular

  initMenu();
  initAppState();
}

void loop() {
  updateEncoder();

  // Rotary input
  if (encoderMoved()) {
    int delta = getEncoderValue();
    updateMenu(delta);  // Scroll menu
  }

  if (encoderClicked()) {
    selectMenuItem();   // Confirm selection
    updateAppState();   // Execute selected mode
  }

  // Touch input
  TS_Point p = getTouchPoint();
  if (p.x != -1 && p.y != -1) {
    int zone = getTouchZone(p.x, p.y);
    if (zone != -1) {
      updateMenu(zone - menuIndex);  // Jump to tapped item
      selectMenuItem();
      updateAppState();
    }
  }
}
