#include "Splash.h"
#include "Display.h"

void showSplashScreen() {
  clearScreen();
  tft.setTextColor(TFT_CYAN, TFT_BLACK);
  tft.setTextSize(2);
  tft.setCursor(20, 80);
  tft.print("ESP32-DIV");

  tft.setTextSize(1);
  tft.setCursor(20, 110);
  tft.print("Wireless Toolkit v1.0");

  delay(2000);  // Hold splash for 2 seconds
}
