#include "DS18B20.hpp"

DS18B20::DS18B20(uint8_t pin)
    : oneWire(pin),
      sensors(&oneWire)
{
    type_str = "DS18B20";
}

void DS18B20::begin()
{
    sensors.begin();
}

void DS18B20::sensorRead()
{
    sensors.requestTemperatures(); // Send the command to get temperatures
    temper = sensors.getTempCByIndex(0);
}

void DS18B20::sensorPrint()
{
    Serial.print("DS18B20 temper  ");
    Serial.println(temper);
}