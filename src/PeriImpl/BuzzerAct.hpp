#ifndef BuzzerAct_HPP
#define BuzzerAct_HPP

#include <Arduino.h>
#include "Actuator.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class BuzzerAct : public Actuator, public RemPrinter, public Beginer
{
  public:
    BuzzerAct(uint8_t pin_);

    void begin();
    bool setState(int);
    void buzz(uint32_t);
    const int getState() const { return actor_state; }

  private:
    const uint8_t device_pin;
    int actor_state ;
    int freq[8];
    String note[8];
};
#endif