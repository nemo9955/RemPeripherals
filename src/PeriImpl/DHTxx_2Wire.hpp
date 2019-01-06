#ifndef DHTXX_2WIRE_HPP_
#define DHTXX_2WIRE_HPP_

#include "DHT.h"
#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"
#include "SensorReading.hpp"

class DHTxx_2Wire : public Sensor, public RemPrinter, public Beginer
{
  public:
    DHTxx_2Wire(uint8_t, uint8_t);
    ~DHTxx_2Wire();

    void begin();
    int read_values();
    int reading_interval() { return 3000; };

    void print_info(Print *pr);
    SensorReading **get_readings() { return nullptr; };


    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name) + device_pin + device_type; };

  private:
    DHT dhtxx_obj;
    const uint8_t device_pin, device_type;
    char *sensor_name;
    float temperature_value = 0;
    float humidity_value = 0;
    // SensorReading *sensor_values[2];
};

#endif /* !DHTXX_2WIRE_HPP_ */
