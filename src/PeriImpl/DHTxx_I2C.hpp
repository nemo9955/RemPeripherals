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
#include "SensorReading.hpp"

class DHTxx_I2C : public Sensor, public RemPrinter, public Beginer
{
  public:
    DHTxx_I2C(int address = 0x5c, uint8_t type = 11);
    ~DHTxx_I2C();

    void begin();
    int read_values();
    int reading_interval() { return 3000; };

    void print_info(Print *pr);
    SensorReading **get_readings() { return nullptr; };

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name) + device_address +device_type ; };

  private:
    const int device_address;
    const uint8_t device_type;
    unsigned int data[5];

    char *sensor_name;

    float temperature_value;
    float humidity_value;
};

#endif /* !DHTXX_I2C_HPP_ */
