#ifndef SHT30_HPP_
#define SHT30_HPP_

#include "Sensor.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class SHT30 : public Sensor, public Updater, public RemPrinter
{
  public:
    SHT30(int _add = 0x45);
    ~SHT30();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const { return sensor_name; };

  private:
    char *sensor_name;
    int device_address;
    unsigned int data[6];

    float temperature_value = 0;
    float humidity_value = 0;
};

#endif /* !SHT30_HPP_ */
