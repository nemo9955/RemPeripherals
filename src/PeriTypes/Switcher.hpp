#ifndef SWITCHER_HPP
#define SWITCHER_HPP

#include "SimpleList.h"
#include "Actuator.hpp"

class Switcher
{
  public:
    Switcher()
    {
        switchersList.push_back(this);
    };

    virtual void attachActuator(Actuator *) = 0;
    virtual Actuator *getActuator() = 0;

    static SimpleList<Switcher *> switchersList;

  protected:
  private:
};

#endif