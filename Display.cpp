#include "Display.h"

TFT_eSPI tft = TFT_eSPI();  // TFT instance

void initDisplay() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextFont(2);
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
}

void drawMenuItem(const char* label, int y, bool selected) {
  if (selected) {
    tft.setTextColor(TFT_BLACK, TFT_WHITE);
  } else {
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
  }
  tft.setCursor(10, y);
  tft.print(label);
}

void drawStatus(const char* message) {
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.setCursor(10, 220);
  tft.print(message);
}

void clearScreen() {
  tft.fillScreen(TFT_BLACK);
}
