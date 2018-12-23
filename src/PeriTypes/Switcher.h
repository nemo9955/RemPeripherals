#ifndef SWITCHER_H
#define SWITCHER_H

#include "Actuator.h"
// #include "CONSTANTS.h"


class Switcher
{
  public:
    // Switcher();
    // virtual ~Switcher(){};

    virtual void begin() = 0;
    virtual void update() = 0;

    virtual void attachActuator(Actuator *) = 0;
    Actuator *getActuator();
};

#endif