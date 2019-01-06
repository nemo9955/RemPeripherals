#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP

#include <stdint.h>
#include "SimpleList.h"

class Actuator
{
  public:
    Actuator()
    {
        actuatorsList.push_back(this);
    };

    virtual bool setState(int) = 0;
    virtual const int getState() const = 0;

    static SimpleList<Actuator *> actuatorsList;

  protected:
  private:
};

#endif