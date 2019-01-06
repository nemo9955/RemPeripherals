#ifndef HP303B_HPP_
#define HP303B_HPP_

#include "Sensor.hpp"

#include <LOLIN_HP303B.h>
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class HP303B : public Sensor, public RemPrinter, public Beginer
{
  public:
    HP303B();
    ~HP303B();

    void begin();
    int read_values();
    int action_interval() { return 5000; };

    void print_info(Print * pr);

    const char *get_sensor_name() const { return sensor_name; };

  private:
    char *sensor_name;
    LOLIN_HP303B HP303BPressureSensor;
    int16_t oversampling;

    int32_t temperature_value;
    int32_t pressure_value;

  protected:
};

#endif /* !HP303B_HPP_ */
