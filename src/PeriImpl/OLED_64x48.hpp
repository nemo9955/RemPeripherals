#ifndef OLED_64x48_H
#define OLED_64x48_H

#include "Actuator.hpp"
#include "Updater.hpp"
#include "RemPrinter.hpp"

// #include <Wire.h>  // Include Wire if you're using I2C
// #include <SFE_MicroOLED.h>  // Include the SFE_MicroOLED library

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

class OLED_64x48 : public Actuator, public Updater
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
    bool setState(uint32_t){};
    const uint32_t getState() const { return actor_state; }

  public:
    Adafruit_SSD1306 oled_obj;
    // MicroOLED oled_obj;

  private:
    RemPrinter *screen_obj;
    uint32_t actor_state;
    const uint8_t device_pin;
};
#endif