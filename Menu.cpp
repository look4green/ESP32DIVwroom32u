#include "Menu.h"
#include "Display.h"  // use drawMenuItem()
#include "Encoder.h"

AppState currentState = MAIN_MENU;
int menuIndex = 0;
const int menuSize = 5;

const char* menuItems[menuSize] = {
  "WiFi Scanner",
  "Deauth Attack",
  "Packet Sniff",
  "Settings",
  "Status Screen"
};

void initMenu() {
  renderMenu();
}

void updateMenu(int direction) {
  menuIndex += direction;
  if (menuIndex < 0) menuIndex = menuSize - 1;
  if (menuIndex >= menuSize) menuIndex = 0;
  renderMenu();
}

void renderMenu() {
  clearScreen();
  for (int i = 0; i < menuSize; i++) {
    drawMenuItem(menuItems[i], 30 + (i * 30), i == menuIndex);
  }
}

AppState getSelectedAppState() {
  return static_cast<AppState>(menuIndex);
}

void selectMenuItem() {
  currentState = getSelectedAppState();
  drawStatus(menuItems[menuIndex]);  // Placeholder for next screen
  // Later: call module based on currentState
}
