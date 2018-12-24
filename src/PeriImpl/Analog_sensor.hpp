#ifndef Analog_sensor_H
#define Analog_sensor_H

// #include <stdint.h>
#include "Sensor.h"

class Analog_sensor : public Sensor
{
  public:
    Analog_sensor(uint8_t pin_, char *sensName, char *readName,
                  int32_t minmap = 0, int32_t maxmap = 1023);

    ~Analog_sensor();

    void begin();
    void sensorRead();
    void sensorPrint();

  private:
    const uint8_t Analog_sensor_PIN;
    char *sensorName;
    char *reading_name;
    const int32_t min_map, max_map;
    int32_t sens_value;
};
#endif