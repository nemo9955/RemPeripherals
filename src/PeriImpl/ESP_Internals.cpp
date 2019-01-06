#include "ESP_Internals.hpp"

#include <ESP8266WiFi.h>

ESP_Internals::ESP_Internals()
{
    current_rssi_value = 0;
    free_heap_value = 0;
    sensor_name = "HP303B";
}

ESP_Internals::~ESP_Internals()
{
}

void ESP_Internals::begin()
{
}

int ESP_Internals::read_values()
{
    current_rssi_value = WiFi.RSSI();

    free_heap_value = ESP.getFreeHeap();
    reset_interval();
    return 0;
}

void ESP_Internals::print_info(Print *pr)
{
    pr->print(sensor_name);
    pr->println(" :");
    pr->print("  current_rssi ");
    pr->print(current_rssi_value);
    pr->println();
    pr->print("  free_heap ");
    pr->print(free_heap_value);
    pr->println();
}