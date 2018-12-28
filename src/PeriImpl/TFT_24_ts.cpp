#include "TFT_24_ts.hpp"

TFT_24_ts::TFT_24_ts(uint8_t _TFT_CS, uint8_t _TFT_DC, uint8_t _TFT_RST, uint8_t _TS_CS)
    : TFT_CS(_TFT_CS),
      TFT_DC(_TFT_DC),
      TFT_RST(_TFT_RST),
      TS_CS(_TS_CS),
      touch_obj(TS_CS),
      display_obj(TFT_CS, TFT_DC, TFT_RST)
{
    disp_btn_cnt = 0;
}

void TFT_24_ts::begin()
{
    touch_obj.begin();
    touch_obj.setRotation(3);

    display_obj.begin();
    display_obj.setRotation(1);
    display_obj.fillScreen(ILI9341_BLACK);
    display_obj.setTextColor(ILI9341_WHITE);
    display_obj.setTextSize(2);
}

void TFT_24_ts::reset()
{
    display_obj.setCursor(0, 0);
    display_obj.fillScreen(ILI9341_BLACK);
    display_obj.setTextColor(ILI9341_WHITE);
    display_obj.setTextSize(2);
}

void TFT_24_ts::update()
{

    // uint16_t tx, ty;
    // uint8_t tz;
    // bool tched;
    // tched = touch_obj.touched();
    // touch_obj.readData(&tx, &ty, &tz);
    // Serial.printf("TOUCH %i ::: %u %u %u  <<<<<<<<<<<<<< \n", tched, tx, ty, tz);

    // TS_Point p = touch_obj.getPoint();
    // Serial.print("Pressure = ");
    // Serial.println(p.z);
    // Serial.print("X = ");
    // Serial.println(p.x);
    // Serial.print("Y = ");
    // Serial.println(p.y);


    if (screen_obj)
    {
        reset();
        screen_obj->print_info(&display_obj);
    }

    // display_obj.println("----");
    for (TFT_24_ts_ScreenButton *btn : disp_buttons)
    {
        if (btn)
        {
            btn->display_button();
        }
    }
}

void TFT_24_ts::add_button(TFT_24_ts_ScreenButton *btn)
{
    if (disp_btn_cnt >= (sizeof(disp_buttons) / sizeof(disp_buttons[0])))
        return;

    disp_buttons[disp_btn_cnt] = btn;
    disp_btn_cnt++;
}

////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

TFT_24_ts_ScreenButton::TFT_24_ts_ScreenButton(TFT_24_ts *_obj, int state, char *_symbols)
{
    par_obj = _obj;
    actor_state = state;
    disp_symbols = _symbols;
    par_obj->add_button(this);
}

void TFT_24_ts_ScreenButton::display_button()
{

    par_obj->display_obj.print(" ");
    int16_t cx, cy;
    cx = par_obj->display_obj.getCursorX();
    cy = par_obj->display_obj.getCursorY();
    par_obj->display_obj.getTextBounds(disp_symbols, cx, cy, &box_x, &box_y, &box_w, &box_h);

    par_obj->display_obj.setTextSize(4);
    par_obj->display_obj.setTextColor(ILI9341_WHITE, ILI9341_GREEN);
    par_obj->display_obj.print(disp_symbols);
    par_obj->display_obj.setTextColor(ILI9341_WHITE);
    par_obj->display_obj.setTextSize(2);

    par_obj->display_obj.print(" ");
    Serial.printf("%s : cx %i , cy %i , box_x %i , box_y %i , box_w %i , box_h %i \n", disp_symbols, cx, cy, box_x, box_y, box_w, box_h);
}

void TFT_24_ts_ScreenButton::callListeners()
{

    if (func_cb)
    {
        func_cb(actor_state);
    }

    if (actuator_obj)
    {
        actuator_obj->setState(actor_state);
    }
}

void TFT_24_ts_ScreenButton::attachFunction(TouchFunctionCb sfcb)
{
    func_cb = sfcb;
    Serial.println("added CB function  !!!!!!!   ");
    callListeners();
}

void TFT_24_ts_ScreenButton::attachActuator(Actuator *act)
{
    actuator_obj = act;
    Serial.println("added ACTUATOR  !!!!!!!   ");
    callListeners();
}
