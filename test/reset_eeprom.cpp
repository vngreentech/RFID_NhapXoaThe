
#include <Arduino.h>
#include <Eeprom24Cxx.h>
#include <SPI.h>
#include <Wire.h> 

void setup() 
{
  for (int diachi = 0; diachi<EEPROM.length(); diachi++) 
  {
    AVR_EEPROM.write_2_byte(diachi, 0);
  }

}

void loop() 
{
  /** Empty loop. **/
}