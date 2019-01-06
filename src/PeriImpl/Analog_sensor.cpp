#include "Analog_sensor.hpp"

#include "Arduino.h"

Analog_sensor::Analog_sensor(uint8_t pin_, char *sensName, char *readName,
                             int32_t minmap, int32_t maxmap)
    : device_pin(pin_),
      sensor_name(sensName),
      reading_name(readName),
      min_map(minmap),
      max_map(maxmap)
{

    sens_value = 0;
}

int Analog_sensor::read_values()
{
    sens_value = map(analogRead(device_pin), 0, 1023, min_map, max_map);
    reset_interval();
    return 0;
}

void Analog_sensor::begin()
{
}

void Analog_sensor::print_info(Print * pr)
{

    pr->print("Analog_sensor, ");
    pr->print(sensor_name);
    pr->println(" :");
    pr->print("  ");
    pr->print(reading_name);
    pr->print(" ");
    pr->print(sens_value);
    pr->println();

}