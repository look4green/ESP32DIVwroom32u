#ifndef BLUETOOTHTOOLS_H
#define BLUETOOTHTOOLS_H

#include <Arduino.h>

void initBluetooth();
void sendBluetoothMessage(const String& message);
String receiveBluetoothMessage();
bool isBluetoothConnected();

#endif
