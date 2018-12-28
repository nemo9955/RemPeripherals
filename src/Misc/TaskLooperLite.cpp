#include "TaskLooperLite.hpp"
#include "Arduino.h"


#define tli_slow (40 * 1000)
#define tli_norm (20 * 1000)
#define tli_fast (10 * 1000)

TaskLooperLite::TaskLooperLite()
{
    stop();
};

void TaskLooperLite::begin()
{
    set_norm();
};

TaskLooperLite::~TaskLooperLite(){

};

bool TaskLooperLite::check()
{
    if (next_ts > 0 && millis() > next_ts)
    {
        next_ts = millis() + tl_interval;
        return true;
    }
    return false;
};

void TaskLooperLite::start()
{
    next_ts = millis() + tl_interval;
};

void TaskLooperLite::now()
{
    next_ts = millis();
};

void TaskLooperLite::stop()
{
    next_ts = -1;
};

void TaskLooperLite::set(uint16_t milis)
{
    tl_interval = milis;
    start();
};

void TaskLooperLite::set_slow()
{
    tl_interval = tli_slow;
    start();
};

void TaskLooperLite::set_norm()
{

    tl_interval = tli_norm;
    start();
};

void TaskLooperLite::set_fast()
{
    tl_interval = tli_fast;
    start();
};
