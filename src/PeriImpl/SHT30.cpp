#include "SHT30.hpp"
#include <Arduino.h>
#include <Wire.h>
#include "UTILS.h"

SHT30::SHT30(uint8_t _add)
    : sht30_address(_add)
{
    type_str = "SHT30";
}

SHT30::~SHT30()
{
}

void SHT30::begin()
{
    Wire.begin();
}

void SHT30::sensorRead()
{
    unsigned int data[6];
    Wire.beginTransmission(sht30_address);
    Wire.write(0x2C);
    Wire.write(0x06);
    Wire.endTransmission();
    Wire.requestFrom(sht30_address, (uint8_t)6);

    if (Wire.available() == 6)
    {
        data[0] = Wire.read();
        data[1] = Wire.read();
        data[2] = Wire.read();
        data[3] = Wire.read();
        data[4] = Wire.read();
        data[5] = Wire.read();
    }

    temper_sht = ((((data[0] * 256.0) + data[1]) * 175) / 65535.0) - 45;
    humid_sht = ((((data[3] * 256.0) + data[4]) * 100) / 65535.0);
}

void SHT30::sensorPrint()
{
    Serial.print("SUM_TEMP_SHT  ");
    Serial.println(temper_sht);

    Serial.print("SUM_HUMI_SHT ");
    Serial.println(humid_sht);
}