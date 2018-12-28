#include "BMP180.hpp"

BMP180::BMP180()
{
    sensor_name = "BMP180";
    temperature_value = 0;
    pressure_value = 0;
}

BMP180::~BMP180()
{
}

void BMP180::begin()
{
    bmp_obj.begin();
}

void BMP180::update()
{
}

void BMP180::read_values()
{
    pressure_value = bmp_obj.readPressure();
    temperature_value = bmp_obj.readTemperature();
}

void BMP180::print_info(Print *pr)
{
    pr->print(sensor_name);
    pr->println(" :");
    pr->print("  temperature ");
    pr->print(temperature_value);
    pr->println();
    pr->print("  pressure ");
    pr->print(pressure_value);
    pr->println();
}