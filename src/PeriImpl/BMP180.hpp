#ifndef BMP180_HPP_
#define BMP180_HPP_

#include "Adafruit_BMP085.h"
#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"
#include "SensorReading.hpp"

class BMP180 : public Sensor, public RemPrinter, public Beginer
{
  public:
    BMP180();
    ~BMP180();

    void begin();
    int read_values();
    int reading_interval() { return 5000; };

    void print_info(Print *pr);
    SensorReading **get_readings() { return sensor_values; };

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name); };

  private:
    char *sensor_name;
    Adafruit_BMP085 bmp_obj;
    SensorReading temperature_value;
    SensorReading pressure_value;
    SensorReading *sensor_values[2];
};
#endif /* !BMP180_HPP_ */
