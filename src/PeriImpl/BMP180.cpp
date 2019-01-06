#include "BMP180.hpp"

BMP180::BMP180()
    : temperature_value("temperature"),
      pressure_value("pressure"),
      sensor_values{&temperature_value, &pressure_value}
{
    sensor_name = "BMP180";
    // temperature_value = 0;
    // pressure_value = 0;
}

BMP180::~BMP180()
{
}

void BMP180::begin()
{
    bmp_obj.begin();
    // Serial.println(" BMP180::begin()  ");
}

int BMP180::read_values()
{
    pressure_value = bmp_obj.readPressure();
    temperature_value = bmp_obj.readTemperature();
    reset_interval();
    return 0;
}

void BMP180::print_info(Print *pr)
{
    pr->print(sensor_name);
    pr->println(" :");

    pr->print(" ");
    temperature_value.print_name(pr);
    pr->print(" ");
    temperature_value.print_value(pr);

    pr->println();

    pr->print(" ");
    pressure_value.print_name(pr);
    pr->print(" ");
    pressure_value.print_value(pr);

    pr->println();
}