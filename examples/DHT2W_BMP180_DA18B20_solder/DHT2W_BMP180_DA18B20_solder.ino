#include "Wire.h"
#include <LOLIN_HP303B.h>
#include <SPI.h>
#include <BH1750.h>
#include "Adafruit_BMP085.h"
#include <DallasTemperature.h>
#include <OneWire.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "DHT.h"

#include "DHTxx_2Wire.hpp"
#include "DS18B20.hpp"
#include "BMP180.hpp"

// examples/DHT2W_BMP180_DA18B20_solder/DHT2W_BMP180_DA18B20_solder.ino

DHTxx_2Wire dhtxx_2wire(D3, 22);
DS18B20 ds18b20(D7);
BMP180 bmp180;

void setup()
{
    Serial.begin(115200);

    dhtxx_2wire.begin();
    ds18b20.begin();
    bmp180.begin();
}

void loop()
{
    dhtxx_2wire.read_values();
    dhtxx_2wire.print_info(&Serial);
    ds18b20.read_values();
    ds18b20.print_info(&Serial);
    bmp180.read_values();
    bmp180.print_info(&Serial);

    Serial.println();
    delay(3000);
}
