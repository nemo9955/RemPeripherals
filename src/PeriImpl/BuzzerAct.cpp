#include "BuzzerAct.hpp"

// int BuzzerAct::freq[] = {1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093}; //Note name: C6 D6 E6 F6 G6 A6 B6 C7   http://newt.phys.unsw.edu.au/jw/notes.html
// String BuzzerAct::note[] = {"C6", "D6", "E6", "F6", "G6", "A6", "B6", "C7"};

BuzzerAct::BuzzerAct(uint8_t pin_)
    : BuzzerAct_PIN(pin_),
     act_state(0),
      freq{1047, 1175, 1319, 1397, 1568, 1760, 1976, 2093},
      note{"C6", "D6", "E6", "F6", "G6", "A6", "B6", "C7"}
{
}

void BuzzerAct::begin()
{
    pinMode(BuzzerAct_PIN, OUTPUT);
    digitalWrite(BuzzerAct_PIN, 0);

    Serial.printf("BuzzerAct BEGIN on pin : %u \n", BuzzerAct_PIN);
}

bool BuzzerAct::setState(uint32_t state)
{
    act_state = state;
    buzz(state);
    Serial.printf("BuzzerAct state : %u \n", act_state);
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

    analogWrite(BuzzerAct_PIN, 512);
    delay(500);
    analogWrite(BuzzerAct_PIN, 0);
    pinMode(BuzzerAct_PIN, OUTPUT);
    digitalWrite(BuzzerAct_PIN, LOW);
}