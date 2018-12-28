#ifndef Analog_sensor_HPP
#define Analog_sensor_HPP

// #include <stdint.h>
#include "Sensor.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class Analog_sensor : public Sensor, public Updater, public RemPrinter
{
  public:
    Analog_sensor(uint8_t pin_, char *sensName, char *readName,
                  int32_t minmap = 0, int32_t maxmap = 1023);

    ~Analog_sensor();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

  private:
    const uint8_t device_pin;
    char *sensor_name;
    char *reading_name;
    const int32_t min_map, max_map;
    int32_t sens_value;
};
#endif