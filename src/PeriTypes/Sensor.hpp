#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>

class Sensor {
   public:
    // Sensor();
    // virtual ~Sensor() {}

    virtual void begin() = 0;
    virtual void read_values() = 0;

};

#endif