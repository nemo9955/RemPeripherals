#ifndef SHT30_HPP_
#define SHT30_HPP_

#include "Sensor.h"

class SHT30 : public Sensor
{
  public:
    SHT30(uint8_t _add = 0x45);
    ~SHT30();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const { return type_str; };

  private:
    char *type_str;
    uint8_t sht30_address;

    float temper_sht = 0;
    float humid_sht = 0;
};

#endif /* !SHT30_HPP_ */
