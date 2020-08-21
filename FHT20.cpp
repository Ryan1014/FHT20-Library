#include "Arduino.h"
#include "FHT20.h"
#include <Wire.h>
#define address 0x40 //device address
#define getTemp 0b11100011
#define getHum 0b11100101
#define writeReg 0b11100110
#define readReg 0b11100111
#define softReset 0b11111110



/*float GetTempF(){
    return 22.3;
}*/

//SoftWire Wire(PB6, PB7, SOFT_FAST); //use for software I2C

void i2cStart(){
    Wire.begin();
    //SWire.begin(); //use for software I2C
}


    float GetTempF(){
        
        
        byte hiByte, loByte;  // declare local variables
        int St = 0;
        float temperature = 7;

        Wire.beginTransmission(address);   // begin transmision by sending the device address(0x40)
        Wire.write(getTemp);               // send command to request temperature
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);       // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();          // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            St = (hiByte<<8) | (loByte);   // combine the high and low bytes into a 16 bit word
            temperature = ((175.72*St)/65536)-46.85; // do some math on that word to get degrees in F
            temperature = ((175.72*St)/65536)-46.85;
            temperature = ((temperature/5)*9)+32;
            
        }
        return temperature;                // return the temperature value. 
    }

   float GetTempC(){
        byte hiByte, loByte;  // declare local variables
        int St = 0;
        float temperature = 0;
        
        Wire.beginTransmission(address);   // begin transmision by sending the device address(0x40)
        Wire.write(getTemp);               // send command that we want to get the temperature
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);       // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();          // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            St = (hiByte<<8) | (loByte);   // combine the high and low bytes into a 16 bit word
            temperature = ((175.72*St)/65536)-46.85; //do some math on that word to get degrees in C
            return temperature;            // return the temperature value. 
        }
    }

    float GetHumid(){
        byte hiByte, loByte;  // declare local variables
        int Rh = 0;
        float humidity = 0;
        
        Wire.beginTransmission(address);   // begin transmision by sending the device address(0x40)
        Wire.write(getHum);                // send command that we want to get the humidity
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);       // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();          // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            Rh = (hiByte<<8) | (loByte);   // combine the high and low bytes into a 16 bit word
            humidity = ((125.0*Rh)/65536)-6; // do some math on that word to get relative Humidity

            return humidity;               // return the humidity value. 
            }
    }

    byte GetTempHighByte(){

        byte hiByte, loByte;  //declare local variables
        
        Wire.beginTransmission(address);  // begin transmision by sending the device address(0x40)
        Wire.write(getTemp);              // send command that we want to get the temperature
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);      // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();         // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            return hiByte;                // return the temperature highByte value. 
        }

    }

    byte GetTempLowByte(){

                byte hiByte, loByte;  //declare local variables
        
        Wire.beginTransmission(address);  // begin transmision by sending the device address(0x40)
        Wire.write(getTemp);              // send command that we want to get the temperature
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);      // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();         // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            return loByte;                // return the temperature highByte value. 
        }

    }

    byte GetHumidHighByte(){
                byte hiByte, loByte;  //declare local variables
        
        Wire.beginTransmission(address);  // begin transmision by sending the device address(0x40)
        Wire.write(getHum);               // send command that we want to get the temperature
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);      // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();         // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            return hiByte;                // return the Humidity highByte value. 
        }

    }

    byte GetHumidLowByte(){
                byte hiByte, loByte;  //declare local variables
        
        Wire.beginTransmission(address);  // begin transmision by sending the device address(0x40)
        Wire.write(getHum);               // send command that we want to get the temperature
        Wire.endTransmission();
        delay(15);
        
        Wire.requestFrom(address,2);      // request 2 bytes of data from the device
        
            if(Wire.available()){ 
            hiByte = Wire.read();         // read the high and low bytes
            loByte = Wire.read();
            delay(1);
            return loByte;                // return the Humidity lowByte value. 
        }

    }

