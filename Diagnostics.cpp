#include "Diagnostics.h"
#include "Display.h"

void runDiagnostics() {
  clearScreen();
  drawStatus("Running diagnostics...");
  showSignalStrength();
  checkModuleHealth();
}

void showSignalStrength() {
  int rssi = WiFi.RSSI();
  drawStatus("WiFi RSSI: " + String(rssi));
}

void checkModuleHealth() {
  drawStatus("Modules OK");  // Placeholder — expand with actual checks
}
