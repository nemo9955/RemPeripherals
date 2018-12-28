#include "BuzzerAct.hpp"

// int BuzzerAct::freq[] = {1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093}; //Note name: C6 D6 E6 F6 G6 A6 B6 C7   http://newt.phys.unsw.edu.au/jw/notes.html
// String BuzzerAct::note[] = {"C6", "D6", "E6", "F6", "G6", "A6", "B6", "C7"};

BuzzerAct::BuzzerAct(uint8_t pin_)
    : device_pin(pin_),
     actor_state(0),
      freq{1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093},
      note{"C6", "D6", "E6", "F6", "G6", "A6", "B6", "C7"}
{
}

void BuzzerAct::begin()
{
    pinMode(device_pin, OUTPUT);
    digitalWrite(device_pin, 0);

    Serial.printf("BuzzerAct BEGIN on pin : %u \n", device_pin);
}

void BuzzerAct::update()
{
}

bool BuzzerAct::setState(int state)
{
    actor_state = state;
    buzz(state);
    Serial.printf("BuzzerAct state : %u \n", actor_state);
    return true;
}

void BuzzerAct::buzz(uint32_t state)
{
    if (state >= (sizeof(freq) / sizeof(freq[0])))
        return;

    analogWriteRange(freq[state]);
    Serial.print("Note name: ");
    Serial.print(note[state]);
    Serial.print(", Freq: ");
    Serial.print(freq[state]);
    Serial.println("Hz");

    analogWrite(device_pin, 512);
    delay(500);
    analogWrite(device_pin, 0);
    pinMode(device_pin, OUTPUT);
    digitalWrite(device_pin, LOW);
}