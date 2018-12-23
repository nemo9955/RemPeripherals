/*
** EPITECH PROJECT, 2018
** RemPeripherals
** File description:
** HP303B
*/

#ifndef HP303B_HPP_
#define HP303B_HPP_

#include "Sensor.h"

#include <LOLIN_HP303B.h>

class HP303B : public Sensor
{
  public:
    HP303B();
    ~HP303B();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const
    {
        return type_str;
    };

  private:
    char *type_str;
    LOLIN_HP303B HP303BPressureSensor;

    int32_t temperature;
    int32_t pressure;
    int16_t oversampling;
    int16_t ret;

  protected:
};

#endif /* !HP303B_HPP_ */
