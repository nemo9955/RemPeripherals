#include "SensorReading.hpp"

SensorReading::SensorReading(char *_reading_name)
    : reading_name(_reading_name)
{
}

SensorReading::~SensorReading()
{
}

void SensorReading::print_name(Print *pr)
{
    pr->print(reading_name);
}

void SensorReading::print_value(Print *pr)
{

    switch (reading_type)
    {
    case ReadingType::_float:
        pr->print(reading_value._float);
        break;

    case ReadingType::_int:
        pr->print(reading_value._int);
        break;
    }
}

void SensorReading::set_int_value(int _int_value)
{
    reading_type = ReadingType::_int;
    reading_value._int = _int_value;
}

void SensorReading::set_float_value(float _float_value)
{
    reading_type = ReadingType::_float;
    reading_value._float = _float_value;
}
