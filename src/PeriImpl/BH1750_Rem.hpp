#ifndef BH1750_REM_HPP_
#define BH1750_REM_HPP_

#include <BH1750.h>
#include "Sensor.hpp"
#include "RemPrinter.hpp"
#include "Beginer.hpp"

class BH1750_Rem : public Sensor, public RemPrinter, public Beginer
{
  public:
    BH1750_Rem();
    ~BH1750_Rem();

    void begin();
    int read_values();
    int action_interval() { return 500; };

    void print_info(Print *pr);

    const char *get_sensor_name() const { return sensor_name; };
    uint32_t get_peri_uuid() { return reinterpret_cast<uint32_t>(sensor_name); };

  private:
    char *sensor_name;
    int32_t ambient_light_value;
    BH1750 lightMeter;

  protected:
};

#endif /* !BH1750_REM_HPP_ */
