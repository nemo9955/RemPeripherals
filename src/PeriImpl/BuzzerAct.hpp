#ifndef BuzzerAct_HPP
#define BuzzerAct_HPP

#include <Arduino.h>
#include "Actuator.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class BuzzerAct : public Actuator, public Updater, public RemPrinter
{
  public:
    BuzzerAct(uint8_t pin_);

    void begin();
    void update();
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