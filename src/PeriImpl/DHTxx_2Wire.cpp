#include "DHTxx_2Wire.hpp"


DHTxx_2Wire::DHTxx_2Wire(uint8_t pin, uint8_t type)
    : dhtxx_obj(pin, type)
{
    switch (type)
    {
    case 11:
        sensor_name = "DHT11";
        break;
    case 21:
        sensor_name = "DHT21";
        break;
    case 22:
        sensor_name = "DHT22";
        break;
    }
}


DHTxx_2Wire::~DHTxx_2Wire()
{
}


void DHTxx_2Wire::begin()
{
    dhtxx_obj.begin();
    // Serial.println(" DHTxx_2Wire::begin()  ");
}


int DHTxx_2Wire::read_values()
{
    temperature_value = dhtxx_obj.readTemperature();
    humidity_value = dhtxx_obj.readHumidity();
    reset_interval();
    return 0;
}

void DHTxx_2Wire::print_info(Print * pr)
{


    pr->print(sensor_name);
    pr->println(" :");
    pr->print("  temperature ");
    pr->print(temperature_value);
    pr->println();
    pr->print("  humidity ");
    pr->print(humidity_value);
    pr->println();


}