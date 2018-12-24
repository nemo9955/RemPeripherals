#ifndef DHTXX_2WIRE_HPP_
#define DHTXX_2WIRE_HPP_

#include "DHT.h"
#include "Sensor.h"

class DHTxx_2Wire : public Sensor
{
  public:
    DHTxx_2Wire(uint8_t, uint8_t);
    ~DHTxx_2Wire();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const
    {
        return type_str;
    };

  private:
    DHT dht_xx;
    char *type_str;
    float temper_dht = 0;
    float humid_dht = 0;
};

#endif /* !DHTXX_2WIRE_HPP_ */
