#ifndef OLED_64x48_HPP
#define OLED_64x48_HPP

#include "Actuator.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "Beginer.hpp"

class OLED_64x48 : public Actuator, public Updater, public Beginer
{
  public:
    OLED_64x48(uint8_t pin_ = 0x3C);

    void begin();
    void update();
    void reset();
    bool set_screen(RemPrinter *_screen_obj)
    {
        screen_obj = _screen_obj;
    };
    bool setState(int){};
    const int getState() const { return actor_state; }

  public:
    Adafruit_SSD1306 display_obj;

  private:
    RemPrinter *screen_obj;
    int actor_state;
    const uint8_t device_pin;
};
#endif