// ESP32DIV.ino

#include "Touchscreen.h"
#include "Display.h"
#include "Splash.h"
#include "Menu.h"
#include "AppState.h"
#include "WiFiTools.h"
#include "SubGHzTools.h"
#include "Storage.h"

// Global instances reflecting the original flow
Touchscreen touchscreen;
Display display;
Splash splash;
Menu menu;
AppState appState;
WiFiTools wifiTools;
SubGHzTools subghzTools;
Storage storage;

void setup() {
  Serial.begin(115200);

  display.init();              // Original TFT init
  touchscreen.init();          // Touch zone setup
  splash.show();               // Boot splash animation
  menu.init();                 // Menu system init
  appState.init();             // App dispatcher

  wifiTools.init();            // Wi-Fi scanner & deauth
  subghzTools.init();          // Sub-GHz replay & capture
  storage.init();              // SD log handling
}

void loop() {
  touchscreen.update();        // Detect UI input
  appState.update();           // Run current mode logic
}
