#include "CycleSwitch.hpp"

uint8_t CycleSwitch::used_cbs = 0;
CycleSwitch *CycleSwitch::list_obj[8];

CycleSwitch::CycleSwitch(uint8_t pb, uint32_t cycle, uint16_t step, uint16_t wait_change)
    : device_pin(pb),
      cycle_size(cycle),
      cycle_step(step),
      TOG_SWITCH_MIN_DURATION(wait_change)
{
    cb_index = used_cbs++;
    list_obj[cb_index] = this;
    actor_state = 0;
}

CycleSwitch::~CycleSwitch()
{
}

void CycleSwitch::begin()
{
    pinMode(device_pin, INPUT);

    switch (cb_index)
    {
    case 0:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_0, RISING);
        break;
    case 1:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_1, RISING);
        break;
    case 2:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_2, RISING);
        break;
    case 3:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_3, RISING);
        break;
    case 4:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_4, RISING);
        break;
    case 5:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_5, RISING);
        break;
    case 6:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_6, RISING);
        break;
    case 7:
        attachInterrupt(digitalPinToInterrupt(device_pin), cb_func_7, RISING);
        break;

    default:
        break;
    }

    LAST_MILLS_TOSW = millis();

    Serial.printf("CycleSwitch index : %u \n", cb_index);
    Serial.printf("CycleSwitch pin   : %u \n", device_pin);
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

    actor_state += cycle_step;
    actor_state %= cycle_size;
    // if (actor_state >= cycle_size)
    //     actor_state = 0;
    Serial.printf("CycleSwitch %u state : %u \n", cb_index, actor_state);

    callListeners();
}

void CycleSwitch::callListeners()
{

    if (func_cb)
    {
        func_cb(actor_state);
    }

    if (actuator_obj)
    {
        actuator_obj->setState(actor_state);
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
    actuator_obj = act;
    Serial.println("added ACTUATOR  !!!!!!!   ");
    callListeners();
}
