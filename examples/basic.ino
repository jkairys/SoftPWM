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
