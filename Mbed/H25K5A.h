#ifndef MBED_H25K5A_H
#define MBED_H25K5A_H
 
#include "mbed.h"

#define BUFFER_SIZE 32
#define FREQUENCY 1000 //Hz -> 1kHz Frequency
#define RADIANS 6.28318530717959 //  Phase difference φ in radians
#define SAMPLES 8
 
class H25K5A {
public:
    H25K5A(PinName pin_aout, PinName pin_ain);
    void Sample_timer_interrupt(); // sinewave output
    void generate_sine_wave();
    void output_sine_wave();
    void take_samples(int);
    void countUout();
    void setUout(float);
    void returnUout();
    float humidity(int); // calculate humidity
  
private:  
    AnalogOut dac;
    AnalogIn adc;
    Ticker Sample_Period;
    double buffer[BUFFER_SIZE];
    uint16_t samples[SAMPLES];
    float Urms;
    int R1; // Front resistor
    float Rh; // H25K5A
    float Uout; // Voltage between R1 and Rh
};
 
#endif