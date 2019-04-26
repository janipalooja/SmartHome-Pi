#ifndef MBED_MF52_10K3470_H
#define MBED_MF52_10K3470_H
 
#include "mbed.h"
 
class MF52_10K3470 {
public:
    MF52_10K3470(PinName pin_ain);
    void readUout();
    void countResistance();
    double returnTemperature();
  
private:
    AnalogIn adc;
    int sensorValue;
    double Uout;
    double Rntc; // MF52 10K3470
    double temperature;
};
 
#endif