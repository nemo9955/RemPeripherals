#include "BMP180.hpp"

BMP180::BMP180()
{
    type_str = "BMP180";
    temper_bmp = 0;
    press_bmp = 0;
}

BMP180::~BMP180()
{
}

void BMP180::begin()
{
    bmp_obj.begin();
}

void BMP180::sensorRead()
{
    press_bmp = bmp_obj.readPressure();
    temper_bmp = bmp_obj.readTemperature();
}

void BMP180::sensorPrint()
{
    Serial.printf("BMP180  temper_bmp  : %f  \n", temper_bmp );
    Serial.printf("BMP180  press_bmp  : %i  \n", press_bmp );
}