#include "SHT30.hpp"
#include <Arduino.h>
#include <Wire.h>

SHT30::SHT30(int _add)
    : device_address(_add)
{
    sensor_name = "SHT30";
}

SHT30::~SHT30()
{
}

void SHT30::begin()
{
    Wire.begin();
}

int SHT30::read_values()
{

    // Start I2C Transmission
    Wire.beginTransmission(device_address);
    // Send measurement command
    Wire.write(0x2C);
    Wire.write(0x06);
    // Stop I2C transmission
    if (Wire.endTransmission() != 0)
        return 1;

    delay(500);

    // Request 6 bytes of data
    Wire.requestFrom(device_address, 6);

    // Read 6 bytes of data
    // cTemp msb, cTemp lsb, cTemp crc, humidity msb, humidity lsb, humidity crc
    for (int i = 0; i < 6; i++)
    {
        data[i] = Wire.read();
    };

    delay(50);

    if (Wire.available() != 0)
        return 1;

    temperature_value = ((((data[0] * 256.0) + data[1]) * 175) / 65535.0) - 45;
    humidity_value = ((((data[3] * 256.0) + data[4]) * 100) / 65535.0);
    reset_interval();
    return 0;
}

void SHT30::print_info(Print *pr)
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