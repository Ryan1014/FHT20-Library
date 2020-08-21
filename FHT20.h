/*
 Arduino Library for FHT20
 functions:
 GetTempC() Returns temp in Celcius 
 GetTempF() Returns Temp in Fahrenheit
 GetHumid() Returns Relative humidity
*/


#ifndef FHT20_h
#define FHT20_h


#include "Arduino.h"

    void i2cStart();

    float GetTempF();
    float GetTempC();
    float GetHumid();

    byte GetTempHighByte();
    byte GetTempLowByte();
    byte GetHumidHighByte();
    byte GetHumidLowByte();
 




#endif