#include "AppState.h"
#include "Menu.h"
#include "Display.h"
#include "RF.h"
#include "Storage.h"

AppState currentAppState = MAIN_MENU;

void initAppState() {
  currentAppState = MAIN_MENU;
  renderCurrentState();
}

void updateAppState() {
  // Example handler: can expand later
  switch (currentAppState) {
    case WIFI_SCANNER:
      scanNRFNetworks();
      break;
    case DEAUTH_ATTACK:
      jamNRF();
      break;
    case PACKET_SNIFF:
      startCCReplay();
      break;
    case SETTINGS:
      drawStatus("Settings Screen");
      break;
    case STATUS_SCREEN:
      listFiles();  // Show saved logs
      break;
    default:
      renderMenu();
      break;
  }
}

void renderCurrentState() {
  clearScreen();
  drawStatus("Mode: " + String(menuItems[menuIndex]));
}
