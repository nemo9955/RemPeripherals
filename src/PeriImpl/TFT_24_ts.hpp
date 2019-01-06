#ifndef TFT_24_TS_HPP_
#define TFT_24_TS_HPP_

#include "Actuator.hpp"
#include "Updater.hpp"
#include "Switcher.hpp"
#include "RemPrinter.hpp"

#include <SPI.h>
#include <XPT2046_Touchscreen.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include "Beginer.hpp"

class TFT_24_ts_ScreenButton;

class TFT_24_ts : public Updater, public Beginer
{
  public:
    TFT_24_ts(uint8_t _TFT_CS = D0, uint8_t _TFT_DC = D8, uint8_t _TFT_RST = -1, uint8_t _TS_CS = D3);

    void begin();
    void update();
    void reset();

    void add_button(TFT_24_ts_ScreenButton *btn);

    bool set_screen(RemPrinter *_screen_obj)
    {
        screen_obj = _screen_obj;
    };

  private:
    const uint8_t TFT_CS;
    const uint8_t TFT_DC;
    const uint8_t TFT_RST;
    const uint8_t TS_CS;

  public:
    XPT2046_Touchscreen touch_obj;
    Adafruit_ILI9341 display_obj;

  private:
    RemPrinter *screen_obj;
    uint8_t disp_btn_cnt;
    TFT_24_ts_ScreenButton *disp_buttons[8];
};

typedef void (*TouchFunctionCb)(int state);

// class TFT_24_ts_ScreenButton : public Switcher
class TFT_24_ts_ScreenButton
{

  public:
    TFT_24_ts_ScreenButton(TFT_24_ts *_obj, int state, char *_symbols);

    bool setState(int state) { actor_state = state; };
    const int getState() const { return actor_state; }

    void display_button();

    void callListeners();
    void attachFunction(TouchFunctionCb sfcb);
    void attachActuator(Actuator *);
    Actuator *getActuator() { return actuator_obj; };

  private:
    TFT_24_ts *par_obj;
    int actor_state;
    char *disp_symbols;
    int16_t box_x, box_y;
    uint16_t box_w, box_h;
    Actuator *actuator_obj;
    TouchFunctionCb func_cb;
};

#endif /* !TFT_24_TS_HPP_ */
