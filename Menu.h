#ifndef MENU_H
#define MENU_H

#include <Arduino.h>

// Menu state enum
enum AppState {
  MAIN_MENU,
  WIFI_SCANNER,
  DEAUTH_ATTACK,
  PACKET_SNIFF,
  SETTINGS,
  STATUS_SCREEN
};

void initMenu();
void updateMenu(int direction);    // +1 or -1 from encoder or touch
void renderMenu();
AppState getSelectedAppState();
void selectMenuItem();

#endif
