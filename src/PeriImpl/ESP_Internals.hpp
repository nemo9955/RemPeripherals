#ifndef ESP_INTERNALS_HPP_
#define ESP_INTERNALS_HPP_

#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class ESP_Internals : public Sensor, public RemPrinter, public Beginer
{
  public:
    ESP_Internals();
    ~ESP_Internals();

    void begin();
    int read_values();
    int action_interval() { return 4000; };

    void print_info(Print *pr);

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name); };

  private:
    char *sensor_name;
    int current_rssi_value;
    int free_heap_value;
};

#endif /* !ESP_INTERNALS_HPP_ */
