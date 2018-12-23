#include "Wire.h"
#include <LOLIN_HP303B.h>
#include <SPI.h>
#include <BH1750.h>

#include "HP303B.hpp"
#include <BH1750_Rem.hpp>
#include <SHT30.hpp>
#include "DHTxx_I2C.hpp"

// examples/Combined_I2C/Combined_I2C.ino

HP303B press_sens;
BH1750_Rem lux_sens;
SHT30 sht_sens;
DHTxx_I2C dhtxx_i2c;

void setup()
{
    Serial.begin(115200);
    press_sens.begin();
    lux_sens.begin();
    sht_sens.begin();
    dhtxx_i2c.begin();
}

void loop()
{
    press_sens.sensorRead();
    press_sens.sensorPrint();
    lux_sens.sensorRead();
    lux_sens.sensorPrint();
    sht_sens.sensorRead();
    sht_sens.sensorPrint();
    dhtxx_i2c.sensorRead();
    dhtxx_i2c.sensorPrint();

    Serial.println();
    delay(1000);
}
