#ifndef DHTXX_I2C_HPP_
#define DHTXX_I2C_HPP_

#include "Sensor.hpp"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class DHTxx_I2C : public Sensor, public RemPrinter, public Beginer
{
  public:
    DHTxx_I2C(int address = 0x5c, uint8_t type = 11);
    ~DHTxx_I2C();

    void begin();
    int read_values();
    int action_interval() { return 3000; };

    void print_info(Print * pr);

    const char *get_sensor_name() const
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
