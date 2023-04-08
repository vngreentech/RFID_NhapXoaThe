
#include <Arduino.h>
#include <Eeprom24Cxx.h>
#include <SPI.h>
#include <Wire.h> 

int gt = 0;

void setup() 
{
  Serial.begin(9600);

  for (int diachi = 0; diachi < 20; diachi+=2) 
  {
    gt = AVR_EEPROM.read_2_byte(diachi);
    Serial.println(gt);
  }

}

void loop() 
{
  //.........
}