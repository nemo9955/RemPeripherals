#ifndef Servo_Rem_H
#define Servo_Rem_H

// #include <Arduino.h>
#include "Actuator.h"

#include <Servo.h>

// abstract class Servo_Rem
class Servo_Rem : public Actuator
{
  public:
    Servo_Rem(uint8_t pin_);

    void begin();
    bool setState(uint32_t);
    const uint32_t getState() const { return act_state; }

  private:
    Servo myservo;
    const uint8_t Servo_Rem_PIN;
    uint32_t act_state ;
};
#endif