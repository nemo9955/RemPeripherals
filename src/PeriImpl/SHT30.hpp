#ifndef SHT30_HPP_
#define SHT30_HPP_

#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"
#include "SensorReading.hpp"

class SHT30 : public Sensor, public RemPrinter, public Beginer
{
  public:
    SHT30(int _add = 0x45);
    ~SHT30();

    void begin();
    int read_values();
    int reading_interval() { return 1000; };

    void print_info(Print *pr);
    SensorReading **get_readings() { return nullptr; };

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name) + device_address; };

  private:
    char *sensor_name;
    const int device_address;
    unsigned int data[6];

    float temperature_value = 0;
    float humidity_value = 0;
};

#endif /* !SHT30_HPP_ */
