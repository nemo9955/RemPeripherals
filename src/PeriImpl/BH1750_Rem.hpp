/*
** EPITECH PROJECT, 2018
** RemPeripherals
** File description:
** BH1750_Rem
*/

#ifndef BH1750_REM_HPP_
#define BH1750_REM_HPP_

#include <BH1750.h>

class BH1750_Rem
{
  public:
    BH1750_Rem();
    ~BH1750_Rem();

    void begin();
    void sensorRead();
    void sensorPrint();

    char *getPerName() const    {        return type_str;    };

  private:
    char *type_str;
    int32_t ambient_lux;
    BH1750 lightMeter;

  protected:
};

#endif /* !BH1750_REM_HPP_ */
