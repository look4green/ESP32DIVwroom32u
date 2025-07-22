#ifndef DISPLAY_H
#define DISPLAY_H

#include <TFT_eSPI.h>

extern TFT_eSPI tft;

void initDisplay();
void drawMenuItem(const char* label, int y, bool selected);
void drawStatus(const char* message);
void clearScreen();

#endif
