#ifndef RF_H
#define RF_H

#include <Arduino.h>

// RF module setup and control
void initRFModules();
void scanNRFNetworks();
void jamNRF();
void startCCReplay();
void stopCCReplay();

#endif
