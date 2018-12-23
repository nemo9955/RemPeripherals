#include "Wire.h"
#include <LOLIN_HP303B.h>

#include "CycleSwitch.hpp"

// examples/CycleSwitch_1/CycleSwitch_1.ino

CycleSwitch btn1(D3, 5);
CycleSwitch btn2(D4, 2);

void setup()
{
    Serial.begin(115200);
    btn1.begin();
    btn2.begin();
}

void loop()
{
    btn1.update();
    btn2.update();

}
