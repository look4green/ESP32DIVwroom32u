#ifndef ENCODER_H
#define ENCODER_H

#include <AiEsp32RotaryEncoder.h>

// Encoder pin definitions
#define ROTARY_ENCODER_A_PIN 25
#define ROTARY_ENCODER_B_PIN 26
#define ROTARY_ENCODER_BUTTON_PIN 27
#define ROTARY_ENCODER_STEPS 4

void initEncoder();
void updateEncoder();
bool encoderMoved();
int getEncoderValue();
bool encoderClicked();

#endif
