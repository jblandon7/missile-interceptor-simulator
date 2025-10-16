#pragma once
#include <Arduino.h>

class Predictor {
public:
  // Stubs for now; you'll flesh out in Week 3–6
  float estimateVelocity(float d_now, float d_prev, float dt_s) {
    if (dt_s <= 0) return NAN;
    return (d_prev - d_now) / dt_s;  // positive when approaching sensor
  }

  float timeToIntercept(float d_now, float v, float d_star) {
    // t* = (d_now - d_star)/v, only if v>0 and d_now>d_star
    if (v <= 0 || d_now <= d_star) return NAN;
    return (d_now - d_star) / v;
  }
};
