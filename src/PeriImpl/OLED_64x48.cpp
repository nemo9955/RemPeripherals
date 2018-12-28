#include "OLED_64x48.hpp"

OLED_64x48::OLED_64x48(uint8_t pin_)
    : oled_obj(-1),
      actor_state(0),
      device_pin(pin_)
{
}

void OLED_64x48::begin()
{
    oled_obj.begin(SSD1306_SWITCHCAPVCC, device_pin);
    reset();
}

void OLED_64x48::reset()
{
    oled_obj.clearDisplay();
    oled_obj.setTextSize(1);
    oled_obj.setCursor(0, 0);
    oled_obj.setTextColor(WHITE);
}

void OLED_64x48::update()
{
    if (screen_obj)
    {
        reset();
        screen_obj->print_info(&oled_obj);
        oled_obj.display();
    }
}
