#ifndef SWITCHER_HPP
#define SWITCHER_HPP

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