#ifndef DHTXX_2WIRE_HPP_
#define DHTXX_2WIRE_HPP_

#include "DHT.h"
#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class DHTxx_2Wire : public Sensor, public RemPrinter, public Beginer
{
  public:
    DHTxx_2Wire(uint8_t, uint8_t);
    ~DHTxx_2Wire();

    void begin();
    int read_values();
    int action_interval() { return 3000; };

    void print_info(Print * pr);

    const char *get_sensor_name() const
    {
        return sensor_name;
    };

  private:
    DHT dhtxx_obj;
    char *sensor_name;
    float temperature_value = 0;
    float humidity_value = 0;
};

#endif /* !DHTXX_2WIRE_HPP_ */
