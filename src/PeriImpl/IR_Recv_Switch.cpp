#include "IR_Recv_Switch.hpp"

IR_Recv_Switch::IR_Recv_Switch(uint16_t recvpin,
                               uint16_t bufsize,
                               uint8_t timeout,
                               bool save_buffer)
    : device_pin(recvpin),
      irrecv_obj(device_pin, bufsize, timeout, save_buffer)
{
}

IR_Recv_Switch::~IR_Recv_Switch()
{
}

void IR_Recv_Switch::begin()
{
    irrecv_obj.enableIRIn();
}


void IR_Recv_Switch::update()
{
    if (irrecv_obj.decode(&decode_results_obj))
    {
        // Display a crude timestamp.
        uint32_t now = millis();
        Serial.printf("Timestamp : %06u.%03u\n", now / 1000, now % 1000);
        if (decode_results_obj.overflow)
            Serial.printf(
                "WARNING: IR code is too big for buffer (>= %d). "
                "This result shouldn't be trusted until this is resolved. "
                "Edit & increase kCaptureBufferSize.\n",
                kCaptureBufferSize);
        // Display the basic output of what we found.
        Serial.print(resultToHumanReadableBasic(&decode_results_obj));
        yield();              // Feed the WDT as the text output can take a while to print.

        // Display the library version the message was captured with.
        Serial.print("Library   : v");
        Serial.println(_IRREMOTEESP8266_VERSION_);
        Serial.println();

        // Output RAW timing info of the result.
        Serial.println(resultToTimingInfo(&decode_results_obj));
        yield(); // Feed the WDT (again)

        // Output the decode_results_obj as source code
        Serial.println(resultToSourceCode(&decode_results_obj));
        Serial.println(""); // Blank line between entries
        yield();            // Feed the WDT (again)
    }
}

void IR_Recv_Switch::callListeners()
{
    if (func_cb)
    {
        func_cb(&decode_results_obj);
    }

    if (actuator_obj)
    {
        actuator_obj->setState( 000000000000 );
    }
}

void IR_Recv_Switch::attachFunction(IR_RECV_FunctionCb sfcb)
{
    func_cb = sfcb;
    Serial.println("added CB function  !!!!!!!   ");
    callListeners();
}

void IR_Recv_Switch::attachActuator(Actuator *act)
{
    actuator_obj = act;
    Serial.println("added ACTUATOR  !!!!!!!   ");
    callListeners();
}
