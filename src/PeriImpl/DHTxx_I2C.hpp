#ifndef DHTXX_I2C_HPP_
#define DHTXX_I2C_HPP_

#include "Sensor.hpp"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class DHTxx_I2C : public Sensor, public Updater, public RemPrinter
{
  public:
    DHTxx_I2C(int address = 0x5c, uint8_t type = 11);
    ~DHTxx_I2C();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const
    {
        return sensor_name;
    };

  private:
    int device_address;
    unsigned int data[5];

    char *sensor_name;

    float temperature_value;
    float humidity_value;
};

#endif /* !DHTXX_I2C_HPP_ */
