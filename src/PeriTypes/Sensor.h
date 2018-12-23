#ifndef SENSOR_H
#define SENSOR_H

#include <stdint.h>
// #include "CONSTANTS.h"

class Sensor {
   public:
    // Sensor();
    // virtual ~Sensor() {}

    virtual void begin() = 0;
    virtual void sensorRead() = 0;
    virtual void sensorPrint() = 0;

};

#endif