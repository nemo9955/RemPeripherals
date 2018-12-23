#include "DHTxx_2Wire.hpp"


// // abstract class DHTxx_2Wire
// float SUM_TEMP_DHT = 0;
// float SUM_HUMI_DHT = 0;

// float temper_dht = 0;
// float humid_dht = 0;
// float heatIndex_dht = 0;
// uint8_t CNT_READ_dht = 0;

// DHTxx_2Wire::DHTxx_2Wire(uint8_t pin, uint8_t type) : dht_xx(pin, type) {
//     switch (type) {
//         case 11:
//             type_str = "DHT11";
//             break;
//         case 21:
//             type_str = "DHT21";
//             break;
//         case 22:
//             type_str = "DHT22";
//             break;
//     }
// }

// void DHTxx_2Wire::begin() { dht_xx.begin(); }

// void DHTxx_2Wire::sensorRead() {
//     temper_dht = dht_xx.readTemperature();
//     humid_dht = dht_xx.readHumidity();

// }