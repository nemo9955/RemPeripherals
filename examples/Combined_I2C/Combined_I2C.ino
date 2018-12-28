#include "Wire.h"
#include <LOLIN_HP303B.h>
#include <SPI.h>
#include <BH1750.h>

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "Updater.hpp"
#include "RemPrinter.hpp"
#include "TaskLooperLite.hpp"

#include "HP303B.hpp"
#include <BH1750_Rem.hpp>
#include <SHT30.hpp>
#include "DHTxx_I2C.hpp"

#include "TFT_24_ts.hpp"
// #include "OLED_64x48.hpp"

#include "CycleSwitch.hpp"

// examples/Combined_I2C/Combined_I2C.ino

TaskLooperLite read_vals;

HP303B press_sens;
BH1750_Rem lux_sens;
SHT30 sht_sens;
DHTxx_I2C dhtxx_i2c;

TFT_24_ts disp_obj;
// OLED_64x48 disp_obj;
TFT_24_ts_ScreenButton ts_b_dec(&disp_obj, -1, "-1");
TFT_24_ts_ScreenButton ts_b_inc(&disp_obj, 1, "+1");

RemPrinter *remprinters[] = {
    &press_sens,
    &lux_sens,
    &sht_sens,
    &dhtxx_i2c,
};

const int screens_count = sizeof(remprinters) / sizeof(remprinters[0]);
CycleSwitch btn(D3, screens_count);

Sensor *sensors[] = {
    &press_sens,
    &lux_sens,
    &sht_sens,
    &dhtxx_i2c,
};

Updater *updaters[] = {
    &disp_obj,
    &btn,
    &press_sens,
    &lux_sens,
    &sht_sens,
    &dhtxx_i2c,
};

void increase_screen(int state)
{
    remprinters[state]->print_info(&Serial);

    disp_obj.set_screen(remprinters[state]);
}

void touch_screen_buttons(int state)
{
    Serial.print("TOUCH BUTTON PRESSED : ");
    Serial.println(state);
}

void setup()
{
    Serial.begin(115200);

    read_vals.set(2000);

    for (Updater *upd : updaters)
    {
        upd->begin();
    }

    btn.attachFunction(&increase_screen);
    ts_b_inc.attachFunction(&touch_screen_buttons);
    ts_b_dec.attachFunction(&touch_screen_buttons);

    disp_obj.set_screen(remprinters[0]);

    disp_obj.display_obj.println("Touch Test !!!!!!!!!!!");
}

void loop()
{
    yield();

    if (read_vals.check())
    {
        yield();

        for (Sensor *sens : sensors)
        {
            sens->read_values();
        }

        yield();

        Serial.println();
        for (RemPrinter *prnt : remprinters)
        {
            prnt->print_info(&Serial);
        }

        yield();

        for (Updater *upd : updaters)
        {
            upd->update();
        }
        yield();
    }
    yield();
}
