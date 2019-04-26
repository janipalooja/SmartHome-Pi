#include "lightswitch.h"
#include "mbed.h"
 
Lightswitch::Lightswitch(int index, PinName pin_din, PinName pin_dout, Serial* serial) : button(pin_din), led(pin_dout), _serial(serial) {
    button.mode(PullDown);
    button.rise(callback(this, &Lightswitch::switch_ISR)); 
    debounce_ticker.attach(callback(this, &Lightswitch::initialize_debounce_count), 0.25);
    led = 0;
    index_ = index;
}

void Lightswitch::switch_ISR() {
    debounce_count++;
    if(debounce_count == 1) {
        led = !led;
        sendDataToSerial();
        reset_debounce_ticker();
    }
}

void Lightswitch::reset_debounce_ticker() {
    debounce_ticker.detach(); 
    debounce_ticker.attach(callback(this, &Lightswitch::initialize_debounce_count), 0.25);
}

void Lightswitch::initialize_debounce_count() {
    debounce_count = 0;
}

void Lightswitch::flipState() {
    led = !led;
    sendDataToSerial();
}

int Lightswitch::state() {
    return (int)led;
}

void Lightswitch::sendDataToSerial() {
    _serial->printf("%i;%i;%i\r\n", SERIAL_DATA_ID, index_, (int)led);
}