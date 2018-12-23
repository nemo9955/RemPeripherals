#include "Wire.h"
#include <LOLIN_HP303B.h>

#include "CycleSwitch.hpp"
#include "BuzzerAct.hpp"

// examples/Buzz_Button/Buzz_Button.ino

CycleSwitch btn(D3, 8);
BuzzerAct buzz(D5);

void asdf(uint32_t state){
    Serial.printf("ASDF : %u\n", state);
}

void setup()
{
    Serial.begin(115200);
    btn.begin();

    btn.attachFunction(&asdf);
    btn.attachActuator(&buzz);

}

void loop()
{
    btn.update();
}
