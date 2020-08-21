/*
This example simply grabs the humidity and temperature from the FHT20 and prints them out over the serial port.

---The library has multiple functions that can be called------

i2cStart() // this will need to be called as the wire library is curretnly built into the FHT20 library.
              I will likely separate it out in future revisions.
 
GetTempF() // get the temperature in Fahrenheit
GetTempC() // get temperarture in Celcius
GetHumid() // get the relative humidity level
           
GetTempHighByte() //The sensor sends out temperature and humidity in 2 bytes these functions can be used          
GetTempLowByte()  //for direct access to those bytes if needed
GetHumidHighByte()
GetHumidLowByte()

-code by Ryan Peters 8-21-2020

*/
#include "FHT20.h" //include the FHT20 library

void setup()
{
    Serial.begin(9600); //begin Serial communication
    
    i2cStart(); // call the libaries i2c start function
}

void loop() {

  Serial.print("Temp: ");
  Serial.println(GetTempF());// Call the GetTempF() function to to get temperature in degress fahrenheit
  Serial.print("Humidity: ");
  Serial.println(GetHumid()); // Call the GetHumid() function to to get the current relitive humidity level
  
  delay(2000); // wait 2 seconds before printing it out again. 

}
