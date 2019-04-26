#ifndef MBED_LIGHTSWITCH_H
#define MBED_LIGHTSWITCH_H
 
#include "mbed.h"

#define SERIAL_DATA_ID 1
 
class Lightswitch {
public:
    Lightswitch(int index, PinName pin_din, PinName pin_dout, Serial* serial);
    void switch_ISR();
    void reset_debounce_ticker();
    void initialize_debounce_count();
    void flipState();
    int state();
    void sendDataToSerial();
  
private:
    InterruptIn button;
    DigitalOut led;
    Serial* _serial;
    Ticker debounce_ticker;
    int debounce_count;
    int index_;

};
 
#endif