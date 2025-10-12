#include "Sensor.h"
#include "Actuator.h"
#include "Predictor.h"

Sensor    sensor;    // HC-SR04 
Actuator  actuator;  // servo/LED 
Predictor pred;      // math predictor
// will store the start time when teh prgram begins
unsigned long t0;  

void setup() {
  Serial.begin(115200);
  // trigpin =9 and sends a short pulse to start a measurement, echopin=8  that listens for a returning pulse
  sensor.begin( 9, 8);
  // sets up servo motor on pin 5 and the LED on pin 6
  actuator.begin( 5, 6);
  // saves the current time in milliseconds 
  t0 = millis();
  // to help read the output
  Serial.println("t_ms,range_cm");        // CSV header
}

void loop() {
  // starts the fixed loop rate at 50 ms thats 20hz
  static const unsigned long PERIOD_MS = 50;
  // collects the time stamp and measure how long each loop took
  unsigned long start = millis();

  // Convert how long the echo to get back and convert it into distance
  float range_cm = sensor.readRangeCm();
  unsigned long t_ms = millis() - t0;

  // CSV log that outputs the data with the timestamp and the distance from 
  Serial.print(t_ms);
  Serial.print(",");
  Serial.println(range_cm, 2);

  // (In later weeks you'll call pred.estimateVelocity(...), etc.)

  // rate control, measure how long the loop took, if it took less than 50 ms it waits for the remaining time
  unsigned long elapsed = millis() - start;
  if (elapsed < PERIOD_MS) delay(PERIOD_MS - elapsed);
}
