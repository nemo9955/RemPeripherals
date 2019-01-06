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
        if (sens_->ready_to_read())
        {
            // Serial.printf("Reading sensor : %s\n", sens_->get_sensor_name());
            sens_->read_values();
            print_info_uuid(sens_->get_peri_uuid(), &Serial);
            // RemPrinter *prnt_ = reinterpret_cast<RemPrinter *>(sens_);
            // Serial.printf("Address of Sensor is %u\n", sens_->get_peri_uuid());

            break; // BREAK SO ONLY 1 READ IS DONE PER LOOP CYCLE !!!
        }
    }
}

void PeriManager::print_info_uuid(uint32_t per_uuid, Print *pr)
{

    for (RemPrinter *prnt_ : RemPrinter::remprintersList)
    {
        if (per_uuid == prnt_->get_peri_uuid())
        {
            prnt_->print_info(pr);
            // Serial.printf("Address of RemPrinter is %u\n", prnt_->get_peri_uuid());
        }
    }
}

void PeriManager::print_info_all(Print *pr)
{

    for (RemPrinter *prnt_ : RemPrinter::remprintersList)
    {
        prnt_->print_info(pr);
        // Serial.printf("Address of RemPrinter is %p\n", (void *)prnt_);
        // Serial.printf("Address of RemPrinter is %u\n", prnt_->get_peri_uuid());
    }
}