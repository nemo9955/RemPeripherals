#ifndef BMP180_HPP_
#define BMP180_HPP_

#include "Adafruit_BMP085.h"
#include "Sensor.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class BMP180 : public Sensor, public Updater, public RemPrinter
{
  public:
    BMP180();
    ~BMP180();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const { return sensor_name; };

  private:
    char *sensor_name;
    float temperature_value;
    int32_t pressure_value;
    Adafruit_BMP085 bmp_obj;
};
#endif /* !BMP180_HPP_ */
