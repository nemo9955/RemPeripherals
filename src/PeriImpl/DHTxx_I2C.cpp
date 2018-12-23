#include "DHTxx_I2C.hpp"

DHTxx_I2C::DHTxx_I2C(int address, uint8_t type) : _address(address)
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

DHTxx_I2C::~DHTxx_I2C()
{
}

void DHTxx_I2C::begin()
{
    // dht12.begin();
    Wire.begin();
    sensorRead();
}

void DHTxx_I2C::sensorPrint()
{

    Serial.print("Temperature in Celsius : ");
    Serial.println(_cTemp);

    // Serial.print("Temperature in Fahrenheit : ");
    // Serial.println(_fTemp);

    Serial.print("Relative Humidity : ");
    Serial.println(_humidity);

    Serial.println();
}

void DHTxx_I2C::sensorRead()
{
    Wire.beginTransmission(_address);

    Wire.write(0);

    if (Wire.endTransmission() != 0)
        return ;

    Wire.requestFrom(_address, 5);

    for (int i = 0; i < 5; i++)
    {
        data[i] = Wire.read();
    };

    delay(50);

    if (Wire.available() != 0)
        return ;

    if (data[4] != (data[0] + data[1] + data[2] + data[3]))
        return ;

    else
    {
        // Convert the data
        _cTemp = (data[2] + (float)data[3] / 10);
        _fTemp = (_cTemp * 1.8) + 32;
        _humidity = (data[0] + (float)data[1] / 10);
        return ;
    }
}