#ifndef SWITCHER_H
#define SWITCHER_H

#include <stdint.h>

class Switcher
{
  public:
    // Switcher();
    // virtual ~Switcher(){};

    virtual void begin() = 0;
    virtual void update() = 0;

    virtual void attachActuator(Actuator *) = 0;
    virtual Actuator *getActuator() = 0;
};

#endif