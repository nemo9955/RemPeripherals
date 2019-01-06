// #include <LOLIN_HP303B.h>
// #include <SPI.h>
// #include <BH1750.h>
// #include <IRremoteESP8266.h>
// #include <IRrecv.h>
// #include <IRutils.h>

#include "SimpleList.h"
#include "Beginer.hpp"
#include "RemPrinter.hpp"
#include "Sensor.hpp"
#include "Switcher.hpp"
#include "Updater.hpp"
#include "PeriManager.hpp"

#include "Adafruit_BMP085.h"
#include "Wire.h"
#include <DallasTemperature.h>
#include <OneWire.h>
#include "DHT.h"

#include "DHTxx_2Wire.hpp"
#include "DS18B20.hpp"
#include "BMP180.hpp"
#include "TaskLooperLite.hpp"

// examples/DHT2W_BMP180_DA18B20_solder/DHT2W_BMP180_DA18B20_solder.ino

PeriManager manager;

DHTxx_2Wire dhtxx_2wire(D3, 22);
DS18B20 ds18b20(D7);
BMP180 bmp180;

TaskLooperLite print_vals;

void setup()
{
    Serial.begin(115200);

    delay(100);

    manager.begin();
    print_vals.set(3000);

    // dhtxx_2wire.begin();
    // ds18b20.begin();
    // bmp180.begin();
}

void loop()
{

    manager.update();

    if (print_vals.check())
    {
        Serial.println();
        manager.print_info(&Serial);
    }

    // dhtxx_2wire.read_values();
    // dhtxx_2wire.print_info(&Serial);
    // ds18b20.read_values();
    // ds18b20.print_info(&Serial);
    // bmp180.read_values();
    // bmp180.print_info(&Serial);

    // Serial.println();
    // delay(3000);
}
