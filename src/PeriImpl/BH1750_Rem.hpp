/*
** EPITECH PROJECT, 2018
** RemPeripherals
** File description:
** BH1750_Rem
*/

#ifndef BH1750_REM_HPP_
#define BH1750_REM_HPP_

#include <BH1750.h>
#include "Updater.hpp"
#include "Sensor.hpp"
#include "RemPrinter.hpp"

class BH1750_Rem : public Sensor, public Updater, public RemPrinter
{
  public:
    BH1750_Rem();
    ~BH1750_Rem();

    void begin();
    void update();
    void read_values();
    void print_info(Print *pr);

    char *getPerName() const { return sensor_name; };

  private:
    char *sensor_name;
    int32_t ambient_light_value;
    BH1750 lightMeter;

  protected:
};

#endif /* !BH1750_REM_HPP_ */
