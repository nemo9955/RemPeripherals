#ifndef DS18B20_HPP
#define DS18B20_HPP

#include "Sensor.hpp"

#include <DallasTemperature.h>
#include <OneWire.h>
#include "RemPrinter.hpp"
#include "Beginer.hpp"
#include "SensorReading.hpp"

class DS18B20 : public Sensor, public RemPrinter, public Beginer
{
  public:
    DS18B20(uint8_t);

    void begin();
    int read_values();
    int reading_interval() { return 2000; };

    void print_info(Print *pr);
    SensorReading **get_readings() { return nullptr; };


    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name); };

  private:
    OneWire onewire_obj;
    DallasTemperature dallas_obj;
    char *sensor_name;
    float temperature_value = 0;
    // SensorReading *sensor_values[1];

    const uint8_t device_pin;
};
#endif