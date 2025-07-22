#include "Storage.h"
#include <FS.h>
#include <SD.h>
#include <SPI.h>

#define SD_CS 5  // Chip select pin — adjust if needed

bool initStorage() {
  if (!SD.begin(SD_CS)) {
    Serial.println("SD Card initialization failed!");
    return false;
  }
  Serial.println("SD Card initialized.");
  return true;
}

bool writeLog(const String& filename, const String& data) {
  File file = SD.open(filename, FILE_WRITE);
  if (!file) {
    Serial.println("Failed to open file for writing");
    return false;
  }
  file.println(data);
  file.close();
  return true;
}

bool appendLog(const String& filename, const String& data) {
  File file = SD.open(filename, FILE_APPEND);
  if (!file) {
    Serial.println("Failed to open file for appending");
    return false;
  }
  file.println(data);
  file.close();
  return true;
}

String readLog(const String& filename) {
  File file = SD.open(filename);
  if (!file) {
    Serial.println("Failed to open file for reading");
    return "";
  }
  String content;
  while (file.available()) {
    content += char(file.read());
  }
  file.close();
  return content;
}

bool deleteFile(const String& filename) {
  if (SD.exists(filename)) {
    return SD.remove(filename);
  }
  return false;
}
