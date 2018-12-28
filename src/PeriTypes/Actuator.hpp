#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP

#include <stdint.h>

class Actuator {
   public:
    // Actuator();
    // virtual ~Actuator(){};

    virtual void begin() = 0;
    virtual bool setState(int) = 0;
    virtual const int getState() const = 0;

    virtual ~Actuator(){};
};

#endif