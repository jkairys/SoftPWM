#ifndef SoftPWM_h
#define SoftPWM_h

#include "Arduino.h"
class SoftPWM
{
  public:
    SoftPWM(unsigned short pin, unsigned long period_us);
    SoftPWM(unsigned short pin, unsigned long period_us, unsigned short led);
    void run();
    void setInverted(unsigned short inv);
    void analogWrite(unsigned short duty);
    void setStep(unsigned int resolution);
    void cycle();
  private:
    void _initialise(unsigned short pin, unsigned long period_us);
    void _off();
    void _on();
    unsigned short _duty;
    unsigned short _inverted;
    unsigned short _pin; // pin number
    unsigned short _led;
    unsigned long _period_us; // period in microseconds (uS)
    unsigned long _period_high_us; // high state for this duration (uS)
    unsigned short _state; // current pin state
    unsigned int _resolution;
    unsigned long _high_end; // micros() when the high should change to low
    unsigned long _period_end; // micros() when the period should restart
};

#endif
