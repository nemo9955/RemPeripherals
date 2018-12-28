#ifndef DHTXX_2WIRE_HPP_
#define DHTXX_2WIRE_HPP_

#include "DHT.h"
#include "Sensor.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class DHTxx_2Wire : public Sensor, public Updater, public RemPrinter
{
  public:
    DHTxx_2Wire(uint8_t, uint8_t);
    ~DHTxx_2Wire();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const
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
