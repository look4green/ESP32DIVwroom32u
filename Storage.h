#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>
#include <FS.h>
#include <SD.h>

// Core functions
bool initStorage();
bool saveToFile(const String& filename, const String& data);
bool appendToFile(const String& filename, const String& data);
String readFile(const String& filename);
bool deleteFile(const String& filename);
void listFiles(const String& path = "/");

// DIV-style helpers
bool fileExists(const String& filename);
String getFileNameByIndex(int index);
int getFileCount(const String& path = "/");

#endif
