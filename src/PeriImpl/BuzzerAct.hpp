#ifndef BuzzerAct_H
#define BuzzerAct_H

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
    bool setState(uint32_t);
    void buzz(uint32_t);
    const uint32_t getState() const { return actor_state; }

  private:
    const uint8_t device_pin;
    uint32_t actor_state ;
    int freq[8];
    String note[8];
};
#endif