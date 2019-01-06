#ifndef SHT30_HPP_
#define SHT30_HPP_

#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class SHT30 : public Sensor, public RemPrinter, public Beginer
{
  public:
    SHT30(int _add = 0x45);
    ~SHT30();

    void begin();
    int read_values();
    int action_interval() { return 1000; };

    void print_info(Print *pr);

    const char *get_sensor_name() const { return sensor_name; };

  private:
    char *sensor_name;
    int device_address;
    unsigned int data[6];

    float temperature_value = 0;
    float humidity_value = 0;
};

#endif /* !SHT30_HPP_ */
