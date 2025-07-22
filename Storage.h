#ifndef STORAGE_H
#define STORAGE_H

#include <Arduino.h>

// Storage API
bool initStorage();
bool writeLog(const String& filename, const String& data);
bool appendLog(const String& filename, const String& data);
String readLog(const String& filename);
bool deleteFile(const String& filename);

#endif
