#ifndef DHTXX_I2C_HPP_
#define DHTXX_I2C_HPP_

#include "Sensor.h"

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "Wire.h"

class DHTxx_I2C : public Sensor
{
  public:
    DHTxx_I2C(int address = 0x5c, uint8_t type = 11);
    ~DHTxx_I2C();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const
    {
        return type_str;
    };

  private:
    int _address;
    unsigned int data[5];

    char *type_str;

    float _cTemp;
    float _fTemp;
    float _humidity;
};

#endif /* !DHTXX_I2C_HPP_ */
