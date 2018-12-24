#include "CycleSwitch.hpp"

uint8_t CycleSwitch::used_cbs = 0;
CycleSwitch *CycleSwitch::list_obj[8];

CycleSwitch::CycleSwitch(uint8_t pb, uint32_t cycle, uint16_t step, uint16_t wait_change)
    : PIN_BUTTON(pb),
      cycle_size(cycle),
      cycle_step(step),
      TOG_SWITCH_MIN_DURATION(wait_change)
{
    cb_index = used_cbs++;
    list_obj[cb_index] = this;
    switch_state = 0;
}

CycleSwitch::~CycleSwitch()
{
}

void CycleSwitch::begin()
{
    pinMode(PIN_BUTTON, INPUT);

    switch (cb_index)
    {
    case 0:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_0, RISING);
        break;
    case 1:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_1, RISING);
        break;
    case 2:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_2, RISING);
        break;
    case 3:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_3, RISING);
        break;
    case 4:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_4, RISING);
        break;
    case 5:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_5, RISING);
        break;
    case 6:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_6, RISING);
        break;
    case 7:
        attachInterrupt(digitalPinToInterrupt(PIN_BUTTON), cb_func_7, RISING);
        break;

    default:
        break;
    }

    LAST_MILLS_TOSW = millis();

    Serial.printf("CycleSwitch index : %u \n", cb_index);
    Serial.printf("CycleSwitch pin   : %u \n", PIN_BUTTON);
}

void CycleSwitch::update()
{
    if (INTERRUPT_CALLED_TOGS && millis() - LAST_MILLS_TOSW > TOG_SWITCH_MIN_DURATION)
    {
        LAST_MILLS_TOSW = millis();
        INTERRUPT_CALLED_TOGS = false;

        advanceState();
    }
    else
    {
        INTERRUPT_CALLED_TOGS = false;
    }
}

void CycleSwitch::advanceState()
{

    switch_state += cycle_step;
    switch_state %= cycle_size;
    // if (switch_state >= cycle_size)
    //     switch_state = 0;
    Serial.printf("CycleSwitch %u state : %u \n", cb_index, switch_state);

    callListeners();
}

void CycleSwitch::callListeners()
{

    if (func_cb)
    {
        func_cb(switch_state);
    }

    if (THE_ACTUATOR)
    {
        THE_ACTUATOR->setState(switch_state);
    }
}

void CycleSwitch::attachFunction(CycleFunctionCb sfcb)
{
    func_cb = sfcb;
    Serial.println("added CB function  !!!!!!!   ");
    callListeners();
}

void CycleSwitch::attachActuator(Actuator *act)
{
    THE_ACTUATOR = act;
    Serial.println("added ACTUATOR  !!!!!!!   ");
    callListeners();
}

Actuator *CycleSwitch::getActuator() { return THE_ACTUATOR; }
