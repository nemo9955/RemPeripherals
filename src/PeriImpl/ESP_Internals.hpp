#ifndef ESP_INTERNALS_HPP_
#define ESP_INTERNALS_HPP_

#include "Sensor.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

class ESP_Internals : public Sensor, public Updater, public RemPrinter
{
  public:
    ESP_Internals();
    ~ESP_Internals();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const { return sensor_name; };

  private:
    char *sensor_name;
    int current_rssi_value;
    int free_heap_value;
};

#endif /* !ESP_INTERNALS_HPP_ */
