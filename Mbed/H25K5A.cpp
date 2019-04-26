#include "H25K5A.h"
#include "H25K5A_datasheet.h"
#include "mbed.h"
 
H25K5A::H25K5A(PinName pin_aout, PinName pin_ain) : dac(pin_aout), adc(pin_ain) {
    Urms = sqrt(2.0); // 1.4142V
    R1 = 1027000; // 1027000
    generate_sine_wave();
}

// Generates 1kHz sine wave for 1 period (Time delay 1ms)
void H25K5A::generate_sine_wave() {
    for(int k = 0; k < BUFFER_SIZE; k++) {
        buffer[k]=((1.0 + sin((double(k)/BUFFER_SIZE*RADIANS)))/2.0);
    }
}

// sinewave output
void H25K5A::output_sine_wave() {
    // sinewave output
    for (int i = 0; i < BUFFER_SIZE; i++) {
        dac = buffer[i];
        take_samples(i);
        wait( (1 / FREQUENCY) / BUFFER_SIZE);
    }
}

void H25K5A::take_samples(int i) {
    for(int j = 0; j < SAMPLES; j++) {
        if(i == BUFFER_SIZE/SAMPLES*j) {
            samples[j] = adc.read_u16();
        }
    }
}

void H25K5A::returnUout() {
    Uout = 0;
    for(int i = 0; i < SAMPLES; i++) {
        Uout += samples[i] / pow(2.0, 16) * Urms;
    }
    
    Uout = Uout/SAMPLES;
    Rh = Uout / (Urms - Uout) * R1;
}

float H25K5A::humidity(int temp){
    returnUout();
    int indexFrom = NULL;
    int indexTo = NULL;
    float smaller[humidities];
    float koostettu[humidities]; // Kahdesta sarakkeesta koostettu yksi saraka.
    float bigger[humidities];
    bool end = false;
    float kulmakerroin;
    float poikkeama;
    float x_muutos;
    float tulos;
    for(int i = 0; i < temperatures; i++) {
        if(temp == temps_[i]) {
            indexFrom = i;
            indexTo = i;
        }
        else if(temp > temps_[i]) {
            indexFrom = i;
        }
        else if(temp < temps_[i]) {
            if(!end) {
                indexTo = i;
                end = true;
            }
        }
    }
    
    for(int i = 0; i < humidities; i++) {
        smaller[i] = resistance[i][indexFrom];
        bigger[i] = resistance[i][indexTo];
        koostettu[i] = smaller[i] + (bigger[i] - smaller[i]) / ((indexTo*5) - (indexFrom*5)) * (temp - (indexFrom*5));
    }
    
     end = false;
     indexFrom = NULL;
     indexTo = NULL;
    
    for(int i = 0; i < humidities; i++) {
        if(Rh == koostettu[i]*1000) {
            indexFrom = i;
            indexTo = i;
        }
        else if(Rh < koostettu[i]*1000) {
            indexFrom = i;
        }
        else if(Rh > koostettu[i]*1000) {
            if(!end) {
                indexTo = i;
                end = true;
            }
        }
    }
    
    kulmakerroin = ((koostettu[indexTo]*1000)-(koostettu[indexFrom]*1000))/(humids_[indexTo] - humids_[indexFrom]);
    
    poikkeama = Rh - (koostettu[indexFrom]*1000);
    
    x_muutos = poikkeama / kulmakerroin;
    
    tulos = humids_[indexFrom] + x_muutos - 0; // -0 on vain kalibroinnin takia
    
    return tulos;
}