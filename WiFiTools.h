#ifndef WIFITOOLS_H
#define WIFITOOLS_H

#include <Arduino.h>

// Wi-Fi tools based on original ESP32-DIV
void initWiFiTools();
void runWiFiScanner();
void performDeauthAttack();
void sniffPackets();

#endif
