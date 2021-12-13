# FHT20-Library
Arduino library for the FHT20 humidity sensor

This is my fisrt atempt at an arduino library
This library is for use with the FHT20 temperature and humidity sensor that is commonly found on ebay. 
It uses I2C communication. The address of the sensor is 0x40

Below are the commands that you can use with this library

GetTempF() <--returns temperature in °F
GetTempC() <--returns temperature in °C

GetHumid() <--returns relative humidity

If you want to do the calculations yourself you can use the following commands to get indavidual bytes from the sensor

GetTempHighByte() <--returns High byte of the tempearure reading
GetTempLowByte()  <--returns Low byte of the tempearure reading
GetHumidHighByte() <--returns high byte of the humidity reading
GetTempHumidLowByte() <--returns low byte of the humidity reading
