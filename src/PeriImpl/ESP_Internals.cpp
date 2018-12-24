#include "ESP_Internals.hpp"

#include <ESP8266WiFi.h>

ESP_Internals::ESP_Internals()
{
    rssi = 0;
    freeHeap = 0;
    type_str = "HP303B";
}

ESP_Internals::~ESP_Internals()
{
}

void ESP_Internals::begin()
{
}

void ESP_Internals::sensorRead()
{
    rssi = WiFi.RSSI();

    freeHeap = ESP.getFreeHeap();
}

void ESP_Internals::sensorPrint()
{

    Serial.print("rssi  ");
    Serial.println(rssi);

    Serial.print("freeHeap  ");
    Serial.println(freeHeap);
}