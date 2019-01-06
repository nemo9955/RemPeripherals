#include "DS18B20.hpp"

DS18B20::DS18B20(uint8_t pin)
    : onewire_obj(pin),
      dallas_obj(&onewire_obj),
      device_pin(pin)
{
    sensor_name = "DS18B20";
}

void DS18B20::begin()
{
    dallas_obj.begin();
    // Serial.println(" DS18B20::begin()  ");
}

int DS18B20::read_values()
{
    dallas_obj.requestTemperatures(); // Send the command to get temperatures
    temperature_value = dallas_obj.getTempCByIndex(0);
    reset_interval();
    return 0;
}

void DS18B20::print_info(Print *pr)
{
    pr->print(sensor_name);
    pr->println(" :");
    pr->print("  temperature ");
    pr->print(temperature_value);
    pr->println();
}