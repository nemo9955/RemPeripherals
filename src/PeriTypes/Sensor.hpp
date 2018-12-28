#ifndef SENSOR_HPP
#define SENSOR_HPP

#include <stdint.h>

class Sensor {
   public:
    // Sensor();
    // virtual ~Sensor() {}

    virtual void begin() = 0;
    virtual void read_values() = 0;

};

#endif