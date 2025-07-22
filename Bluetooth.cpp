#include "BluetoothTools.h"
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void initBluetooth() {
  SerialBT.begin("ESP32DIV");
  Serial.println("Bluetooth initialized");
}

void sendBluetoothMessage(const String& message) {
  if (SerialBT.connected()) {
    SerialBT.println(message);
  }
}

String receiveBluetoothMessage() {
  if (SerialBT.available()) {
    return SerialBT.readStringUntil('\n');
  }
  return "";
}

bool isBluetoothConnected() {
  return SerialBT.connected();
}
