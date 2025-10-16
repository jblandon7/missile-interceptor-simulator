#pragma once
#include <Arduino.h>
#include <Servo.h>

class Actuator {
public:
  void begin(uint8_t servoPin, uint8_t ledPin) {
    _ledPin = ledPin;
    pinMode(_ledPin, OUTPUT);
    _servo.attach(servoPin);
    _servo.write(_rest); // rest angle
  }

  void fire() {
    digitalWrite(_ledPin, HIGH);  // flash LED as "launch"
    _servo.write(_fire);          // swing arm
    delay(150);                   // simple dwell
    digitalWrite(_ledPin, LOW);
    _servo.write(_rest);          // return
  }

  void setAngles(uint8_t rest, uint8_t fire) { _rest=rest; _fire=fire; }

private:
  Servo _servo;
  uint8_t _ledPin = 255;
  uint8_t _rest = 30;    // tune these angles later
  uint8_t _fire = 120;
};
