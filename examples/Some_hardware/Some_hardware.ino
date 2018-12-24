#include "Wire.h"
#include <LOLIN_HP303B.h>
#include <SPI.h>
#include <BH1750.h>

#include "HP303B.hpp"
#include <BH1750_Rem.hpp>
#include <SHT30.hpp>
#include "DHTxx_I2C.hpp"

#include "CycleSwitch.hpp"
#include "Servo_Rem.hpp"

#include <Servo.h>

// examples/Some_hardware/Some_hardware.ino

// HP303B press_sens;
// BH1750_Rem lux_sens;
// SHT30 sht_sens;
// DHTxx_I2C dhtxx_i2c;

CycleSwitch btn1(D3, 200, 20, 500);
Servo_Rem srv1(D6);

void asdf(uint32_t state)
{
    Serial.printf("ASDF : %u\n", state);
}

void setup()
{
    Serial.begin(115200);

    // press_sens.begin();
    // lux_sens.begin();
    // sht_sens.begin();
    // dhtxx_i2c.begin();

    btn1.begin();
    srv1.begin();

    btn1.attachFunction(&asdf);
    // btn1.attachActuator(&srv1);
}

void loop()
{
    // press_sens.sensorRead();
    // press_sens.sensorPrint();
    // lux_sens.sensorRead();
    // lux_sens.sensorPrint();
    // sht_sens.sensorRead();
    // sht_sens.sensorPrint();
    // dhtxx_i2c.sensorRead();
    // dhtxx_i2c.sensorPrint();

    btn1.update();

    // Serial.println();
    delay(100);
}
