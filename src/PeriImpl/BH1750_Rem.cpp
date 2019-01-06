#include "BH1750_Rem.hpp"

BH1750_Rem::BH1750_Rem()
{
    sensor_name = "BH1750";
}

BH1750_Rem::~BH1750_Rem()
{
}

void BH1750_Rem::begin()
{
    lightMeter.begin();
}

int BH1750_Rem::read_values()
{
    ambient_light_value = lightMeter.readLightLevel();

    reset_interval();
    return 0;
}

void BH1750_Rem::print_info(Print *pr)
{

    pr->print(sensor_name);
    pr->println(" :");
    pr->print("  Light ");
    pr->print(ambient_light_value);
    pr->print(" lux");
    pr->println();
}