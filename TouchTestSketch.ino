#include <XPT2046_Touchscreen.h>
#include <SPI.h>

#define CS_PIN 33
#define TIRQ_PIN 36

XPT2046_Touchscreen ts(CS_PIN, TIRQ_PIN);

void setup() {
  Serial.begin(115200);
  SPI.begin();
  ts.begin();
  ts.setRotation(1);
  Serial.println("Touchscreen test started");
}

void loop() {
  if (ts.touched()) {
    TS_Point p = ts.getPoint();
    Serial.print("X = ");
    Serial.print(p.x);
    Serial.print(" | Y = ");
    Serial.println(p.y);
    delay(200);
  }
}
