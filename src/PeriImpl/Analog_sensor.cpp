#include "Analog_sensor.hpp"

#include <Arduino.h>

uint32_t SUM_AN = 0;
uint16_t CNT_AN = 0;
uint32_t dump = 0;

Analog_sensor::Analog_sensor(uint8_t pin_, char *sensName, char *readName,
                             int32_t minmap, int32_t maxmap)
    : Analog_sensor_PIN(pin_),
      sensorName(sensName),
      reading_name(readName),
      min_map(minmap),
      max_map(maxmap) {}

void Analog_sensor::sensorRead()
{
    dump = map(analogRead(Analog_sensor_PIN), 0, 1023, min_map, max_map);
}

void Analog_sensor::sensorPrint()
{
    Serial.printf("Analog_sensor %s %s : %i \n", sensorName, reading_name, sens_value);
}