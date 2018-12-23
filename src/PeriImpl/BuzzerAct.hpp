#ifndef BuzzerAct_H
#define BuzzerAct_H

#include <Arduino.h>
#include "Actuator.h"

// abstract class BuzzerAct
class BuzzerAct : public Actuator
{
  public:
    BuzzerAct(uint8_t pin_);

    void begin();
    bool setState(uint32_t);
    void buzz(uint32_t);
    const uint32_t getState() const { return act_state; }

  private:
    const uint8_t BuzzerAct_PIN;
    uint32_t act_state = 0;
    int freq[8];
    String note[8];
};
#endif