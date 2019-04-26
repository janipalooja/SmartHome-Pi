#include "mbed.h"
#include "H25K5A.h"
#include "MF52_10K3470.h"
#include "MQ135.h"
#include "lightswitch.h"

H25K5A h25k5a(PA_4, A0);
MF52_10K3470 ntc(A1);
MQ135 q135(A4);

AnalogIn daylight(A3);
int amountOfDaylight;
int twilightSwitchValue = 65000;

Serial RaspBerry(USBTX, USBRX);  // tx, rx
Serial arduino(D14, D15); // tx, rx

volatile char c = '\0'; // Initialized to the NULL character

void onCharReceived()
{
    c = RaspBerry.getc();
}

DigitalOut outdoorLight(D3);

Lightswitch sw1(1, D13, D7, &RaspBerry); // Hallway
Lightswitch sw2(2, D12, D6, &RaspBerry); // Kitchen
Lightswitch sw3(3, D11, D5, &RaspBerry); // Bedroom
Lightswitch sw4(4, D8,  D4, &RaspBerry); // Livingroom

Ticker ticker;
Ticker outdoorLight_ticker;

double temp;
float humi;

void outdoorLightControl() {
    if(amountOfDaylight < twilightSwitchValue) {
        outdoorLight = 1;
    }
    else {
        outdoorLight = 0;
    }
}

bool print_serial = false;

void flip_print_serial() {
    print_serial = true;
}

int main()
{
    
    RaspBerry.attach(&onCharReceived);
    
    ticker.attach(&flip_print_serial, 2);
    outdoorLight_ticker.attach(&outdoorLightControl, 5);
    
    arduino.baud(9600);
    
    while(1) {
        
        h25k5a.output_sine_wave();
        temp = ntc.returnTemperature();
        humi = h25k5a.humidity( (int)temp + 0.5 );
        
        amountOfDaylight = daylight.read_u16();
        
        if(c == 'A') {
            c = '\0';
            arduino.printf("1");
        }
        if(c == 'B') {
            c = '\0';
            arduino.printf("2");
        }
        if (c == '1') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            sw1.flipState();
        }
        if (c == '2') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            sw2.flipState();
        }
        if (c == '3') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            sw3.flipState();
        }
        if (c == '4') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            sw4.flipState();
        }
        if (c == '5') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            twilightSwitchValue = 13107;
        }
        if (c == '6') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            twilightSwitchValue = 26214;
        }
        if (c == '7') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            twilightSwitchValue = 39321;
        }
        if (c == '8') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            twilightSwitchValue = 52428;
        }
        if (c == '9') {
            c = '\0';  // To avoid execution of this block until if statement is true again.
            twilightSwitchValue = 65535;
        }
        
        if(print_serial == true) {
            RaspBerry.printf("%i;%.2f;%.2f;%.2f;%i", 2, temp, humi, q135.getPPM(), amountOfDaylight);
            print_serial = false;
        }

    }
}