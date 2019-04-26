#include "MF52_10K3470.h"
#include "mbed.h"
 
MF52_10K3470::MF52_10K3470(PinName pin_ain) : adc(pin_ain) {

}

void MF52_10K3470::readUout() {
    sensorValue = adc.read_u16();
    Uout = sensorValue / pow(2.0, 16) * 3.3;
}

void MF52_10K3470::countResistance() {
    Rntc = 10000 * (3.3 / Uout - 1);
}

double MF52_10K3470::returnTemperature() {
    readUout();
    countResistance();
    temperature = 1/(0.000984226 + 0.000239975 * log(Rntc) + 0.000000204 * pow(log(Rntc), 3)) -273.15;
    return temperature;
}