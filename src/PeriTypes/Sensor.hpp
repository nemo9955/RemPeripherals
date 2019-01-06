#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <stdint.h>
#include "SimpleList.h"

class Sensor
{
  public:
    Sensor()
    {
        sensorsList.push_back(this);
    };

    virtual uint32_t get_peri_uuid() = 0;
    virtual const char *get_sensor_name() const = 0;
    virtual int read_values() = 0;
    virtual int action_interval() = 0;

    virtual void reset_interval() { cooldown_time = millis() + action_interval(); };
    virtual bool action_ready() { return millis() >= cooldown_time; };

    static SimpleList<Sensor *> sensorsList;

  private:
    uint32_t cooldown_time;

  protected:
};

#endif