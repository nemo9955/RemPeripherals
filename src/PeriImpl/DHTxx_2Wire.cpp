#include "DHTxx_2Wire.hpp"


DHTxx_2Wire::DHTxx_2Wire(uint8_t pin, uint8_t type)
    : dht_xx(pin, type)
{
    switch (type)
    {
    case 11:
        type_str = "DHT11";
        break;
    case 21:
        type_str = "DHT21";
        break;
    case 22:
        type_str = "DHT22";
        break;
    }
}


DHTxx_2Wire::~DHTxx_2Wire()
{
}


void DHTxx_2Wire::begin()
{
    dht_xx.begin();
}

void DHTxx_2Wire::sensorRead()
{
    temper_dht = dht_xx.readTemperature();
    humid_dht = dht_xx.readHumidity();
}

void DHTxx_2Wire::sensorPrint()
{
    Serial.printf("DHTxx_2Wire  temper_dht  : %f  \n", temper_dht);
    Serial.printf("DHTxx_2Wire  humid_dht  : %f  \n", humid_dht);
}