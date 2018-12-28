#include "TaskLooper.hpp"
#include "Arduino.h"


#define tli_slow (40 * 1000)
#define tli_norm (20 * 1000)
#define tli_fast (10 * 1000)

TaskLooper::TaskLooper()
{
    stop();
};

void TaskLooper::begin()
{
    set_norm();
};

TaskLooper::~TaskLooper(){

};

bool TaskLooper::check()
{
    if (next_ts > 0 && millis() > next_ts)
    {
        next_ts = millis() + tl_interval;
        return true;
    }
    return false;
};

void TaskLooper::start()
{
    next_ts = millis() + tl_interval;
};

void TaskLooper::now()
{
    next_ts = millis();
};

void TaskLooper::stop()
{
    next_ts = -1;
};

void TaskLooper::set(uint16_t milis)
{
    tl_interval = milis;
    start();
};

void TaskLooper::set_slow()
{
    tl_interval = tli_slow;
    start();
};

void TaskLooper::set_norm()
{

    tl_interval = tli_norm;
    start();
};

void TaskLooper::set_fast()
{
    tl_interval = tli_fast;
    start();
};
