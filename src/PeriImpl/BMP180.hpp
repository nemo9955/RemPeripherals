#ifndef BMP180_HPP_
#define BMP180_HPP_

#include "Adafruit_BMP085.h"
#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class BMP180 : public Sensor, public RemPrinter, public Beginer
{
  public:
    BMP180();
    ~BMP180();

    void begin();
    int read_values();
    int action_interval() { return 5000; };

    void print_info(Print *pr);

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name); };

  private:
    char *sensor_name;
    float temperature_value;
    int32_t pressure_value;
    Adafruit_BMP085 bmp_obj;
};
#endif /* !BMP180_HPP_ */
