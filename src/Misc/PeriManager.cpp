#include "PeriManager.hpp"

#include "SimpleList.h"

#include "Actuator.hpp"
#include "Beginer.hpp"
#include "RemPrinter.hpp"
#include "Sensor.hpp"
#include "Switcher.hpp"
#include "Updater.hpp"

SimpleList<Actuator *> Actuator::actuatorsList;
SimpleList<Beginer *> Beginer::beginersList;
SimpleList<RemPrinter *> RemPrinter::remprintersList;
SimpleList<Sensor *> Sensor::sensorsList;
SimpleList<Switcher *> Switcher::switchersList;
SimpleList<Updater *> Updater::updatersList;

PeriManager::PeriManager()
{
}

PeriManager::~PeriManager()
{
}

void PeriManager::begin()
{

    for (Beginer *beg_ : Beginer::beginersList)
    {
        beg_->begin();
    }
}

void PeriManager::update()
{
    for (Updater *upd_ : Updater::updatersList)
    {
        upd_->update();
    }

    for (Sensor *sens_ : Sensor::sensorsList)
    {
        if (sens_->action_ready())
        {
            // Serial.printf("Reading sensor : %s\n", sens_->get_sensor_name());
            sens_->read_values();
            // Serial.printf("Address of Sensor is %p\n", (void *)sens_);

            break; // BREAK SO ONLY 1 READ IS DONE PER LOOP CYCLE !!!
        }
    }
}

void PeriManager::print_info(Print *pr)
{

    for (RemPrinter *prnt_ : RemPrinter::remprintersList)
    {
        prnt_->print_info(pr);
        // Serial.printf("Address of RemPrinter is %p\n", (void *)prnt_);
    }
}