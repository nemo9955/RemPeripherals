#ifndef Servo_Rem_HPP
#define Servo_Rem_HPP

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
    bool setState(int);
    const int getState() const { return actor_state; }

  private:
    Servo servo_obj;
    const uint8_t device_pin;
    int actor_state ;
};
#endif