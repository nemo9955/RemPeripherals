#ifndef IR_Recv_Switch_HPP_
#define IR_Recv_Switch_HPP_

#include "Actuator.h"
#include "Switcher.h"

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

typedef void (*IR_RECV_FunctionCb)(decode_results *results);

class IR_Recv_Switch : public Switcher
{
  public:
    IR_Recv_Switch(uint16_t recvpin,
                   uint16_t bufsize = kRawBuf,
                   uint8_t timeout = kTimeoutMs,
                   bool save_buffer = false);
    ~IR_Recv_Switch();

    void update();
    void begin();
    void callListeners();

    void attachFunction(IR_RECV_FunctionCb sfcb);
    void attachActuator(Actuator *);
    Actuator *getActuator(){ return THE_ACTUATOR; };

  private:
    const uint8_t PIN_BUTTON;
    IRrecv irrecv;
    decode_results results;
    Actuator *THE_ACTUATOR;
    IR_RECV_FunctionCb func_cb;
const uint16_t kCaptureBufferSize = 1024;


};

#endif /* !IR_Recv_Switch_HPP_ */
