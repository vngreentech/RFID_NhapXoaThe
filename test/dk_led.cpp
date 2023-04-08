#include <Arduino.h>

#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN         9
#define SS_PIN          10

unsigned long UID[4]; 
//unsigned long ID;
unsigned int i;

//int ID1[4] = {91, 37, 120, 34}; //Thẻ bật tắt đèn
unsigned long ID1 = 89159; 
int led = 7;

int dem = 0;
 
MFRC522 mfrc522(SS_PIN, RST_PIN);

void docthe()
{
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  { 
    return; 
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {  
    return;  
  } 
  
  for (byte i = 0; i < 4; i++) 
  { 
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "" : "");   
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
    //stringOne =  String(45, HEX);
    UID[i] = mfrc522.uid.uidByte[i];
    // Serial.print(UID[i], HEX); Serial.print(" ");
    Serial.print(UID[i]); Serial.print(" ");
  }

  Serial.println(" ");
  
  // if (UID[i] == ID1[i])
  // {
  //   dem ++;
  //   Serial.print("Biến Đếm: ");
  //   Serial.println(dem);
    
  //     if ( (dem % 2) == 1) //Số lẻ đèn ON
  //     {
  //       digitalWrite(led, HIGH);
  //       Serial.println("ĐÈN ON");    
  //     }
  //     else
  //     {
  //       digitalWrite(led, LOW);
  //       Serial.println("ĐÈN OFF");       
  //     }
  // }
  
  // else
  // {
  //   Serial.println("SAI THẺ........");
  // }
// int a;
//   Serial.print("a : "); Serial.println(UID[i]);
  mfrc522.PICC_HaltA();  
  mfrc522.PCD_StopCrypto1();
}

void setup() 
{

    Serial.begin(9600);   

    pinMode(led, OUTPUT);
    digitalWrite(led, LOW);
    
    SPI.begin();    
    mfrc522.PCD_Init();

}

void loop() 
{
 if ( ! mfrc522.PICC_IsNewCardPresent()) 
  { 
    return; 
  }
  
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {  
    return;  
  } 
  
  for (byte i = 0; i < 4; i++) 
  { 
    //Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? "" : "");   
    //Serial.print(mfrc522.uid.uidByte[i], HEX);
    //stringOne =  String(45, HEX);
    UID[i] = mfrc522.uid.uidByte[i];
    // Serial.print(UID[i], HEX); Serial.print(" ");
    Serial.print(UID[i]); Serial.print(" ");
  }

  Serial.println(" ");
  
  // if (UID[i] == ID1[i])
  // {
  //   dem ++;
  //   Serial.print("Biến Đếm: ");
  //   Serial.println(dem);
    
  //     if ( (dem % 2) == 1) //Số lẻ đèn ON
  //     {
  //       digitalWrite(led, HIGH);
  //       Serial.println("ĐÈN ON");    
  //     }
  //     else
  //     {
  //       digitalWrite(led, LOW);
  //       Serial.println("ĐÈN OFF");       
  //     }
  // }
  
  // else
  // {
  //   Serial.println("SAI THẺ........");
  // }
// int a;
//   Serial.print("a : "); Serial.println(UID[i]);
  mfrc522.PICC_HaltA();  
  mfrc522.PCD_StopCrypto1();
}