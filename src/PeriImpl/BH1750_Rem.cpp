#include "BH1750_Rem.hpp"

BH1750_Rem::BH1750_Rem()
{
    type_str = "BH1750_Rem";
}

BH1750_Rem::~BH1750_Rem()
{
}

void BH1750_Rem::begin()
{
    lightMeter.begin();
}

void BH1750_Rem::sensorRead()
{
    ambient_lux = lightMeter.readLightLevel();
}
void BH1750_Rem::sensorPrint()
{

    Serial.print("Light level : ");
    Serial.print(ambient_lux);
    Serial.println(" lux");
}