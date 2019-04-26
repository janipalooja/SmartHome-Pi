// H25K5A Datasheet

int const temperatures = 11;
int const humidities = 15;

int temps_[temperatures] = {0, 5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
int humids_[humidities] = {20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90};

// HUOM! Kilo ohm!
float resistance[humidities][temperatures] = {
        //  0C      5C      10C     15C     20C     25C     30C     35C     40C     45C     50C
/*20 %RH*/ {0,      0,      0,      21000,  13500,  9800,   8000,   6300,   4600,   3800,   3200},
/*25 %RH*/ {0,      19800,  16000,  10500,  6700,   4803,   3900,   3100,   2300,   1850,   1550},
/*30 %RH*/ {12000,  9800,   7200,   5100,   3300,   2500,   2000,   1500,   1100,   900,    750},
/*35 %RH*/ {5200,   4700,   3200,   2350,   1800,   1300,   980,    750,    575,    430,    350},
/*40 %RH*/ {2800,   2000,   1400,   1050,   840,    630,    470,    385,    282,    210,    170},
/*45 %RH*/ {720,    510,    386,    287,    216,    166,    131,    104,    80,     66,     51},
/*50 %RH*/ {384,    271,    211,    159,    123,    95,     77,     63,     52,     45,     38},
/*55 %RH*/ {200,    149,    118,    91,     70,     55,     44,     38,     32,     30,     24},
/*60 %RH*/ {108,    82,     64,     51,     40,     31,     25,     21,     17,     14,     12},
/*65 %RH*/ {64,     48,     38,     31,     25,     20,     17,     13,     11,     9,      8},
/*70 %RH*/ {38,     29,     24,     19,     16,     13,     10.5,   9,      8.2,    7.1,    6},
/*75 %RH*/ {23,     18,     15,     12,     10,     8.5,    7.2,    6.4,    5.8,    5,      4.1},
/*80 %RH*/ {16,     12,     10.2,   8.1,    7.2,    5.7,    5,      4.4,    4,      3.3,    2.9},
/*85 %RH*/ {10.2,   8.2,    6.9,    5.5,    4.7,    4,      3.6,    3.2,    2.9,    2.4,    2},
/*90 %RH*/ {6.9,    5.4,    4.7,    4.1,    3.2,    2.8,    2.5,    2.3,    2.1,    1.8,    1.5}

};