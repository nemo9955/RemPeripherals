/*
** EPITECH PROJECT, 2018
** RemPeripherals
** File description:
** HP303B
*/

#ifndef HP303B_HPP_
#define HP303B_HPP_

#include "Sensor.hpp"

#include <LOLIN_HP303B.h>
#include "Updater.hpp"
#include "RemPrinter.hpp"

class HP303B : public Sensor, public Updater, public RemPrinter
{
  public:
    HP303B();
    ~HP303B();

    void begin();
    void update();
    void read_values();
    void print_info(Print * pr);

    char *getPerName() const { return sensor_name; };

  private:
    char *sensor_name;
    LOLIN_HP303B HP303BPressureSensor;
    int16_t oversampling;

    int32_t temperature_value;
    int32_t pressure_value;

  protected:
};

#endif /* !HP303B_HPP_ */
