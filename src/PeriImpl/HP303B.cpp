#include "HP303B.hpp"

HP303B::HP303B()
{
    type_str = "HP303B";
    oversampling = 2;
}

HP303B::~HP303B()
{
}

void HP303B::begin()
{
    HP303BPressureSensor.begin();
}

void HP303B::sensorRead()
{
    HP303BPressureSensor.measureTempOnce(temperature, oversampling);
    HP303BPressureSensor.measurePressureOnce(pressure, oversampling);
}
void HP303B::sensorPrint()
{

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" degrees of Celsius");

    Serial.print("Pressure: ");
    Serial.print(pressure);
    Serial.println(" Pascal");
}