#pragma once
#include <Arduino.h>

class Sensor {
public:
  void begin(uint8_t trigPin, uint8_t echoPin) {
    _trig = trigPin; _echo = echoPin;
    pinMode(_trig, OUTPUT);
    pinMode(_echo, INPUT);
    digitalWrite(_trig, LOW);
    delay(50);
  }

  float readRangeCm() {
    // Trigger: 10 us HIGH
    digitalWrite(_trig, LOW); delayMicroseconds(2);
    digitalWrite(_trig, HIGH); delayMicroseconds(10);
    digitalWrite(_trig, LOW);

    // Read echo pulse length in microseconds
    unsigned long dur = pulseIn(_echo, HIGH, 30000UL); // timeout 30 ms (~5 m)
    if (dur == 0) return NAN; // no echo

    // HC-SR04: distance cm ≈ duration_us / 58.0
    return dur / 58.0f;
  }

private:
  uint8_t _trig = 255, _echo = 255;
};
