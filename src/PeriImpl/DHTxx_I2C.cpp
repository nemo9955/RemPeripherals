#include "DHTxx_I2C.hpp"

DHTxx_I2C::DHTxx_I2C(int address, uint8_t type) : device_address(address)
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

DHTxx_I2C::~DHTxx_I2C()
{
}

void DHTxx_I2C::begin()
{
    // dht12.begin();
    Wire.begin();
    read_values();
}

int DHTxx_I2C::read_values()
{
    Wire.beginTransmission(device_address);

    Wire.write(0);

    if (Wire.endTransmission() != 0)
        return 1;

    Wire.requestFrom(device_address, 5);

    for (int i = 0; i < 5; i++)
    {
        data[i] = Wire.read();
    };

    delay(50);

    if (Wire.available() != 0)
        return 1;

    if (data[4] != (data[0] + data[1] + data[2] + data[3]))
        return 1;

    // Convert the data
    temperature_value = (data[2] + (float)data[3] / 10);
    humidity_value = (data[0] + (float)data[1] / 10);
    reset_interval();
    return 0;
}

void DHTxx_I2C::print_info(Print *pr)
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
