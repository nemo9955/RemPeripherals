#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <stdint.h>
#include "SimpleList.h"
#include "SensorReading.hpp"

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
    virtual int reading_interval() = 0;

    virtual void reset_interval() { cooldown_time = millis() + reading_interval(); };
    virtual bool ready_to_read() { return millis() >= cooldown_time; };

    virtual SensorReading **get_readings() = 0;

    static SimpleList<Sensor *> sensorsList;

  private:
    uint32_t cooldown_time;

  protected:
};

#endif