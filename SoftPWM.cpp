#include "Arduino.h"
#include "SoftPWM.h"

SoftPWM::SoftPWM(unsigned short pin, unsigned long period_us, unsigned short led){
  _initialise(pin, period_us);
  _led = led;
  pinMode(_led, OUTPUT);
}

SoftPWM::SoftPWM(unsigned short pin, unsigned long period_us){
  _initialise(pin, period_us);
}

void SoftPWM::setInverted(unsigned short inv){
  _inverted = inv;
}

void SoftPWM::_initialise(unsigned short pin, unsigned long period_us){
  pinMode(pin, OUTPUT);
  _pin = pin;
  _led = NULL;
  _period_us = period_us;
  _resolution = 256;
}

// force start a new duty period
void SoftPWM::cycle(){
  _state = 0;
  _period_end = 0;
}

void SoftPWM::setStep(unsigned int step){
  _resolution = _period_us / step;
}

void SoftPWM::_off(){
  digitalWrite(_pin, _inverted ? HIGH : LOW);
}

void SoftPWM::_on(){
  digitalWrite(_pin, _inverted ? LOW : HIGH);
}

void SoftPWM::analogWrite(unsigned short duty){
  _duty = duty;
  if(duty == 0){
    _off();
    if(_led) digitalWrite(_led, LOW);
  }
  _period_high_us = _period_us;
  _period_high_us = _period_high_us * duty / _resolution;
  //_period_end = 0;
  //_high_end = 0;
}

void SoftPWM::run(){
  if(_period_us == NULL) return;
  if(_period_high_us == NULL) return;

  unsigned long now = millis();

  if(_state == 1 && now >= _high_end && _duty < 255){
    _off();
    if(_led) digitalWrite(_led, LOW);
    _state = 0;
  }else if(now >= _period_end){
    _period_end = now + _period_us;
    _high_end = now + _period_high_us;
    _on();
    if(_led) digitalWrite(_led, HIGH);
    _state = 1;
  }
}
