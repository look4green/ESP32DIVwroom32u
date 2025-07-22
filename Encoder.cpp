#include "Encoder.h"

AiEsp32RotaryEncoder rotaryEncoder(
  ROTARY_ENCODER_A_PIN,
  ROTARY_ENCODER_B_PIN,
  ROTARY_ENCODER_BUTTON_PIN,
  -1,
  ROTARY_ENCODER_STEPS
);

void IRAM_ATTR readEncoderISR() {
  rotaryEncoder.readEncoder_ISR();
}

void initEncoder() {
  rotaryEncoder.begin();
  rotaryEncoder.setup(readEncoderISR);
  rotaryEncoder.setBoundaries(0, 100, true);  // Wraparound enabled
  rotaryEncoder.setAcceleration(250);
}

void updateEncoder() {
  rotaryEncoder.loop();
}

bool encoderMoved() {
  return rotaryEncoder.encoderChanged();
}

int getEncoderValue() {
  return rotaryEncoder.readEncoder();
}

bool encoderClicked() {
  return rotaryEncoder.isEncoderButtonClicked();
}
