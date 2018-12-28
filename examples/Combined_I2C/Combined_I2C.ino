#include "Wire.h"
#include <LOLIN_HP303B.h>
#include <SPI.h>
#include <BH1750.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Updater.hpp"
#include "RemPrinter.hpp"

#include "HP303B.hpp"
#include <BH1750_Rem.hpp>
#include <SHT30.hpp>
#include "DHTxx_I2C.hpp"
#include "OLED_64x48.hpp"

#include "CycleSwitch.hpp"

// examples/Combined_I2C/Combined_I2C.ino

HP303B press_sens;
BH1750_Rem lux_sens;
SHT30 sht_sens;
DHTxx_I2C dhtxx_i2c;

OLED_64x48 oled_64x48;
CycleSwitch btn(D3, 5);

Updater *updaters[] = {
    &oled_64x48,
    &btn,
    &press_sens,
    &lux_sens,
    &sht_sens,
    &dhtxx_i2c,
};

RemPrinter *remprinters[] = {
    &press_sens,
    &lux_sens,
    &sht_sens,
    &dhtxx_i2c,
};

Sensor *sensors[] = {
    &press_sens,
    &lux_sens,
    &sht_sens,
    &dhtxx_i2c,
};

const int screens_count = sizeof(remprinters) / sizeof(remprinters[0]);
int current_screen = 0;

void increase_screen(uint32_t state)
{
    current_screen++;
    current_screen %= screens_count;

    // Serial.print(" !!!! screens_count ");
    // Serial.println(screens_count);
    // Serial.print(" !!!! current_screen ");
    // Serial.println(current_screen);
    // Serial.println(" SHOULD ::: ");
    remprinters[current_screen]->print_info(&Serial);

    oled_64x48.set_screen(remprinters[current_screen]);
}

void setup()
{
    Serial.begin(115200);

    for (Updater *upd : updaters)
    {
        upd->begin();
    }

    Serial.print(" !!!! screens_count ");
    Serial.println(screens_count);
    Serial.print(" !!!! current_screen ");
    Serial.println(current_screen);

    btn.attachFunction(&increase_screen);

    oled_64x48.set_screen(remprinters[0]);
}

void loop()
{

    for (Sensor *sens : sensors)
    {
        sens->read_values();
    }

    for (Updater *upd : updaters)
    {
        upd->update();
    }

    // for (RemPrinter *prnt : remprinters)
    // {
    //     prnt->print_info(&Serial);
    // }

    // Serial.println();
    delay(1000);
}
