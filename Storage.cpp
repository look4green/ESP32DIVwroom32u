#include "Storage.h"

#define SD_CS 5  // Adjust if needed

bool initStorage() {
  if (!SD.begin(SD_CS)) {
    Serial.println("SD init failed");
    return false;
  }
  Serial.println("SD initialized");
  return true;
}

bool saveToFile(const String& filename, const String& data) {
  File file = SD.open(filename, FILE_WRITE);
  if (!file) return false;
  file.println(data);
  file.close();
  return true;
}

bool appendToFile(const String& filename, const String& data) {
  File file = SD.open(filename, FILE_APPEND);
  if (!file) return false;
  file.println(data);
  file.close();
  return true;
}

String readFile(const String& filename) {
  File file = SD.open(filename);
  if (!file) return "";
  String content;
  while (file.available()) {
    content += char(file.read());
  }
  file.close();
  return content;
}

bool deleteFile(const String& filename) {
  return SD.exists(filename) ? SD.remove(filename) : false;
}

void listFiles(const String& path) {
  File dir = SD.open(path);
  if (!dir || !dir.isDirectory()) return;

  File file = dir.openNextFile();
  while (file) {
    Serial.println(file.name());
    file = dir.openNextFile();
  }
}

bool fileExists(const String& filename) {
  return SD.exists(filename);
}

String getFileNameByIndex(int index) {
  File dir = SD.open("/");
  if (!dir || !dir.isDirectory()) return "";

  int count = 0;
  File file = dir.openNextFile();
  while (file) {
    if (count == index) return String(file.name());
    file = dir.openNextFile();
    count++;
  }
  return "";
}

int getFileCount(const String& path) {
  File dir = SD.open(path);
  if (!dir || !dir.isDirectory()) return 0;

  int count = 0;
  File file = dir.openNextFile();
  while (file) {
    count++;
    file = dir.openNextFile();
  }
  return count;
}
