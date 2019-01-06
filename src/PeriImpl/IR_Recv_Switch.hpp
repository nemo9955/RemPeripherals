#ifndef IR_Recv_Switch_HPP_
#define IR_Recv_Switch_HPP_

#include "Actuator.hpp"
#include "Switcher.hpp"
#include "Updater.hpp"

#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>
#include "RemPrinter.hpp"
#include "Beginer.hpp"

typedef void (*IR_RECV_FunctionCb)(decode_results *decode_results_obj);

class IR_Recv_Switch : public Switcher, public Updater, public Beginer
{
  public:
    IR_Recv_Switch(uint16_t recvpin,
                   uint16_t bufsize = kRawBuf,
                   uint8_t timeout = kTimeoutMs,
                   bool save_buffer = false);
    ~IR_Recv_Switch();

    void begin();
    void update();
    void callListeners();

    void attachFunction(IR_RECV_FunctionCb sfcb);
    void attachActuator(Actuator *);
    Actuator *getActuator() { return actuator_obj; };

  private:
    const uint8_t device_pin;
    IRrecv irrecv_obj;
    decode_results decode_results_obj;
    Actuator *actuator_obj;
    IR_RECV_FunctionCb func_cb;
    const uint16_t kCaptureBufferSize = 1024;
};

#endif /* !IR_Recv_Switch_HPP_ */
