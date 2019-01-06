#include "Servo_Rem.hpp"

Servo_Rem::Servo_Rem(uint8_t pin_)
    : servo_obj(),
      device_pin(pin_),
      actor_state(0)
{
}

void Servo_Rem::begin()
{
    servo_obj.attach(device_pin);
}

bool Servo_Rem::setState(int state)
{

    actor_state = state;
    servo_obj.write(actor_state);

    Serial.printf("Servo_Rem state : %u \n", actor_state);
    return true;
}

void Servo_Rem::print_info(Print *pr)
{
}