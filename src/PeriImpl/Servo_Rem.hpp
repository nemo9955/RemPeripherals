#ifndef Servo_Rem_H
#define Servo_Rem_H

// #include <Arduino.h>
#include "Actuator.hpp"

#include <Servo.h>
#include "Updater.hpp"
#include "RemPrinter.hpp"

// abstract class Servo_Rem
class Servo_Rem : public Actuator, public Updater, public RemPrinter
{
  public:
    Servo_Rem(uint8_t pin_);

    void begin();
    void update();
    void print_info(Print * pr);
    bool setState(uint32_t);
    const uint32_t getState() const { return actor_state; }

  private:
    Servo servo_obj;
    const uint8_t device_pin;
    uint32_t actor_state ;
};
#endif