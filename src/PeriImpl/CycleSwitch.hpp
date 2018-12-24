
#ifndef CYCLESWITCH_HPP_
#define CYCLESWITCH_HPP_

#include "Actuator.h"
#include "Switcher.h"
#include <Arduino.h>


typedef void (*CycleFunctionCb)(uint32_t state);

class CycleSwitch : public Switcher
{
  public:
    CycleSwitch(uint8_t pb, uint32_t cycle = 2, uint16_t step = 1, uint16_t wait_change = 2000);
    ~CycleSwitch();

    void update();
    void begin();
    void advanceState();
    void callListeners();

    void attachFunction(CycleFunctionCb sfcb);
    void attachActuator(Actuator *);
    Actuator *getActuator();


  private:
    uint16_t switch_state;
    const uint32_t cycle_size;
    const uint16_t cycle_step;
    const uint16_t TOG_SWITCH_MIN_DURATION;

    CycleFunctionCb func_cb ;

    Actuator *THE_ACTUATOR;
    const uint8_t PIN_BUTTON;
    int LAST_MILLS_TOSW;
    bool INTERRUPT_CALLED_TOGS;

  private:
    uint8_t cb_index;
    static uint8_t used_cbs;

    static CycleSwitch *list_obj[8];

    static void cb_func_0()
    {
        if (list_obj[0])
            list_obj[0]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 0);
    }

    static void cb_func_1()
    {
        if (list_obj[1])
            list_obj[1]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 1);
    }

    static void cb_func_2()
    {
        if (list_obj[2])
            list_obj[2]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 2);
    }

    static void cb_func_3()
    {
        if (list_obj[3])
            list_obj[3]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 3);
    }

    static void cb_func_4()
    {
        if (list_obj[4])
            list_obj[4]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 4);
    }

    static void cb_func_5()
    {
        if (list_obj[5])
            list_obj[5]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 5);
    }

    static void cb_func_6()
    {
        if (list_obj[6])
            list_obj[6]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 6);
    }

    static void cb_func_7()
    {
        if (list_obj[7])
            list_obj[7]->INTERRUPT_CALLED_TOGS = true;
        else
            Serial.printf("ERRRRRO, this func is not here : %i\n", 7);
    }
};

#endif /* !CYCLESWITCH_HPP_ */
