#include "utils.h"

TFT_eSPI tft = TFT_eSPI();  // Global instance

void updateStatusBar() {
  float voltage = readBatteryVoltage();
  drawStatusBar(voltage, true);
}

float readBatteryVoltage() {
  // Replace with actual battery ADC pin if available
  return 3.7;
}

float readInternalTemperature() {
  // ESP32 internal temperature approximation (dummy value)
  return 32.5;
}

bool isSDCardAvailable() {
  return SD.begin();
}

void drawStatusBar(float batteryVoltage, bool forceUpdate) {
  tft.setTextSize(1);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.fillRect(0, 0, tft.width(), 10, TFT_BLACK);
  tft.setCursor(5, 0);
  tft.print("BAT: ");
  tft.print(batteryVoltage, 2);
  tft.print("V");
}

void initDisplay() {
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
}

void showNotification(const char* title, const char* message) {
  tft.setTextSize(2);
  tft.setTextColor(TFT_YELLOW, TFT_BLACK);
  tft.fillRect(0, 100, tft.width(), 40, TFT_BLACK);
  tft.setCursor(10, 105);
  tft.print(title);
  tft.setCursor(10, 125);
  tft.setTextSize(1);
  tft.print(message);
}

void hideNotification() {
  tft.fillRect(0, 100, tft.width(), 40, TFT_BLACK);
}

void printWrappedText(int x, int y, int maxWidth, const char* text) {
  tft.setCursor(x, y);
  tft.setTextSize(1);
  String str = text;
  int lineHeight = 10;
  while (str.length() > 0) {
    int cut = maxWidth / 6;
    if (cut > str.length()) cut = str.length();
    tft.print(str.substring(0, cut));
    str = str.substring(cut);
    y += lineHeight;
    tft.setCursor(x, y);
  }
}

void loading(int frameDelay, uint16_t color, int16_t x, int16_t y, int repeats, bool center) {
  for (int i = 0; i < repeats; ++i) {
    tft.fillCircle(x, y, (i % 3) + 3, color);
    delay(frameDelay);
    tft.fillCircle(x, y, (i % 3) + 3, TFT_BLACK);
  }
}

void displayLogo(uint16_t color, int displayTime) {
  tft.setTextColor(color, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(40, 60);
  tft.print("ESP32-DIV");
  delay(displayTime);
}

namespace Terminal {
  void terminalSetup() {
    Serial.begin(115200);
  }

  void terminalLoop() {
    if (Serial.available()) {
      String cmd = Serial.readStringUntil('\n');
      Serial.println("Received: " + cmd);
    }
  }
}
