#include "OLED_64x48.hpp"

OLED_64x48::OLED_64x48(uint8_t pin_)
    : display_obj(-1),
      actor_state(0),
      device_pin(pin_)
{
}

void OLED_64x48::begin()
{
    display_obj.begin(SSD1306_SWITCHCAPVCC, device_pin);
    reset();
}

void OLED_64x48::reset()
{
    display_obj.clearDisplay();
    display_obj.setTextSize(1);
    display_obj.setCursor(0, 0);
    display_obj.setTextColor(WHITE);
}

void OLED_64x48::update()
{
    if (screen_obj)
    {
        reset();
        screen_obj->print_info(&display_obj);
        display_obj.display();
    }
}
