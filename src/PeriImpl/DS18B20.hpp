#ifndef DS18B20_H
#define DS18B20_H

#include "Sensor.h"

#include <DallasTemperature.h>
#include <OneWire.h>

class DS18B20 : public Sensor
{
  public:
    DS18B20(uint8_t);

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const { return type_str; };

  private:
    OneWire oneWire;
    DallasTemperature sensors;
    char *type_str;
    float temper = 0;
};
#endif