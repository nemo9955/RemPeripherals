#include "Servo_Rem.hpp"

Servo_Rem::Servo_Rem(uint8_t pin_)
    : myservo(),
      Servo_Rem_PIN(pin_),
      act_state(0)
{
}

void Servo_Rem::begin()
{
    myservo.attach(Servo_Rem_PIN);

    Serial.printf("Servo_Rem BEGIN on pin : %u \n", Servo_Rem_PIN);
}

bool Servo_Rem::setState(uint32_t state)
{

    act_state = state;
    myservo.write(act_state);

    Serial.printf("Servo_Rem state : %u \n", act_state);
    return true;
}
