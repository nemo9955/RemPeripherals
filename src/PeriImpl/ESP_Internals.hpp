#ifndef ESP_INTERNALS_HPP_
#define ESP_INTERNALS_HPP_

#include "Sensor.h"

class ESP_Internals : public Sensor
{
  public:
    ESP_Internals();
    ~ESP_Internals();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const { return type_str; };

  private:
    char *type_str;
    int rssi;
    int freeHeap;
};

#endif /* !ESP_INTERNALS_HPP_ */
