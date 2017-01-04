# SoftPWM
Software PWM for Arduino / ESP8266

## Purpose
Use this library when you need PWM with a duty cycle measured in seconds or minutes, rather than microseconds.


## Usage

~~~~
#include <SoftPWM.h>

#define LED 1

// setup a pin to toggle every 1000ms / 1s
SoftPWM circulator(LED, 1000);

void setup(){
  // approx 10% duty cycle
  circulator.analogWrite(25);
}

void loop(){
  // nuthin
}
~~~~
