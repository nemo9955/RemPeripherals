#ifndef DS18B20_HPP
#define DS18B20_HPP

#include "Sensor.hpp"

#include <DallasTemperature.h>
#include <OneWire.h>
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class DS18B20 : public Sensor,  public RemPrinter, public Beginer
{
  public:
    DS18B20(uint8_t);

    void begin();
    int read_values();
    int action_interval() { return 2000; };

    void print_info(Print * pr);

    const char *get_sensor_name() const { return sensor_name; };

  private:
    OneWire onewire_obj;
    DallasTemperature dallas_obj;
    char *sensor_name;
    float temperature_value = 0;
};
#endif