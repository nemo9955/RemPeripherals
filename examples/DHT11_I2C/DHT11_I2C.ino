#include "Wire.h"
#include <LOLIN_HP303B.h>

#include "DHTxx_I2C.hpp"

// examples/DHT11_I2C/DHT11_I2C.ino

DHTxx_I2C dhtxx_i2c;

void setup()
{
    Serial.begin(115200);
    dhtxx_i2c.begin();
}

void loop()
{
    dhtxx_i2c.read_values();
    dhtxx_i2c.print_info(&Serial);

    Serial.println();
    delay(1000);
}
