#include "HP303B.hpp"

HP303B::HP303B()
{
    sensor_name = "HP303B";
    oversampling = 2;
}

HP303B::~HP303B()
{
}

void HP303B::begin()
{
    HP303BPressureSensor.begin();
}

int HP303B::read_values()
{
    HP303BPressureSensor.measureTempOnce(temperature_value, oversampling);
    HP303BPressureSensor.measurePressureOnce(pressure_value, oversampling);
    reset_interval();
    return 0;
}
void HP303B::print_info(Print * pr)
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