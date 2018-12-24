#ifndef BMP180_HPP_
#define BMP180_HPP_

#include "Adafruit_BMP085.h"
#include "Sensor.h"

class BMP180 : public Sensor
{
  public:
    BMP180();
    ~BMP180();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const { return type_str; };

  private:
    char *type_str;
    float temper_bmp;
    int32_t press_bmp;
    Adafruit_BMP085 bmp_obj;
};
#endif /* !BMP180_HPP_ */
