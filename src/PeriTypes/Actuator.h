#ifndef ACTUATOR_H
#define ACTUATOR_H

#include <stdint.h>
// #include "CONSTANTS.h"

class Actuator {
   public:
    // Actuator();
    // virtual ~Actuator(){};

    virtual void begin() = 0;
    virtual bool setState(uint32_t) = 0;
    virtual const uint32_t getState() const = 0;

    virtual ~Actuator(){};
};

#endif