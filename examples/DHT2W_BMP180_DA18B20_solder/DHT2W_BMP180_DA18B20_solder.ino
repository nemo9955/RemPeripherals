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
    dhtxx_2wire.sensorRead();
    dhtxx_2wire.sensorPrint();
    ds18b20.sensorRead();
    ds18b20.sensorPrint();
    bmp180.sensorRead();
    bmp180.sensorPrint();

    Serial.println();
    delay(3000);
}
