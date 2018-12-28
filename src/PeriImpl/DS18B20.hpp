#ifndef DS18B20_H
#define DS18B20_H

#include "Sensor.hpp"

#include <DallasTemperature.h>
#include <OneWire.h>
#include "Updater.hpp"
#include "RemPrinter.hpp"

class DS18B20 : public Sensor, public Updater, public RemPrinter
{
  public:
    DS18B20(uint8_t);

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const { return sensor_name; };

  private:
    OneWire onewire_obj;
    DallasTemperature dallas_obj;
    char *sensor_name;
    float temperature_value = 0;
};
#endif