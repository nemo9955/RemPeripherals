#ifndef HP303B_HPP_
#define HP303B_HPP_

#include "Sensor.hpp"

#include <LOLIN_HP303B.h>
#include "RemPrinter.hpp"
#include "Beginer.hpp"
#include "SensorReading.hpp"

class HP303B : public Sensor, public RemPrinter, public Beginer
{
  public:
    HP303B();
    ~HP303B();

    void begin();
    int read_values();
    int reading_interval() { return 5000; };

    void print_info(Print *pr);
    SensorReading **get_readings() { return nullptr; };

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name); };

  private:
    char *sensor_name;
    LOLIN_HP303B HP303BPressureSensor;
    int16_t oversampling;

    int32_t temperature_value;
    int32_t pressure_value;

  protected:
};

#endif /* !HP303B_HPP_ */
