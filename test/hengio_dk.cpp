#include <Arduino.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

DS3231  rtc(SDA, SCL);
Time  t;

int len = 6; int gtlen;  // Lên là trừ
int xuong = 5; int gtxuong; // Xuống là cộng
int menu = 7; int gtmenu; 
int macdinh = 1;
int relay1 = 9; int relay2 = 10;

int contro = 0; int contro_dk = 5; int hang = 0;

int congtru_tong = 0; int congtru_menudk = 0;
int demtong = 0;

int ngay = 1; int thang = 1; int namng = 0; int namtr = 0; int namch = 0; int namdv = 0; int namtong = 0; //SETUP DATE
int gio = 0; int phut = 0; int giay = 0; //SETUP TIME

int ton1 = 0; int pon1 = 0; int tof1 = 0; int pof1 = 0; //LỆNH 1
int ton2 = 0; int pon2 = 0; int tof2 = 0; int pof2 = 0; //LỆNH 2
int ton3 = 0; int pon3 = 0; int tof3 = 0; int pof3 = 0; //LỆNH 3
int ton4 = 0; int pon4 = 0; int tof4 = 0; int pof4 = 0; //LỆNH 4
int ton5 = 0; int pon5 = 0; int tof5 = 0; int pof5 = 0; //LỆNH 5
int re1 = 1; int re2 = 1; int re3 = 1; int re4 = 1; int re5 = 1; //RELAY

void manhinh()  // HIỂN THỊ MÀN HÌNH CHÍNH
{
  lcd.setCursor(0,0);
  lcd.print("DATE: ");
  lcd.setCursor(0,1);
  lcd.print("TIME: ");
  lcd.setCursor(6,0);
  lcd.print(rtc.getDateStr());
  lcd.setCursor(6,1);
  lcd.print(rtc.getTimeStr());  
}

void menu_tong() // HIỂN THỊ MENU TỔNG
{
  if (congtru_tong == 0)
  {
    lcd.clear();
    lcd.print(">BACK");
    lcd.setCursor(0, 1);
    lcd.print(" DATE");  
  }
  else if (congtru_tong == 1)
  {
    lcd.clear();
    lcd.print(" BACK");
    lcd.setCursor(0, 1);
    lcd.print(">DATE");    
  }
  else if (congtru_tong == 2)
  {
    lcd.clear();
    lcd.print(">TIME");
    lcd.setCursor(0, 1);
    lcd.print(" DIEU KHIEN");   
  }
  else if (congtru_tong == 3)
  {
    lcd.clear();
    lcd.print(" TIME");
    lcd.setCursor(0, 1);
    lcd.print(">DIEU KHIEN");    
  }
}

void chonmenu_tong() // CHỌN MENU TỔNG
{
  switch (congtru_tong) 
  {
    case 0:
      //BACK
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SETUP DATE");
      lcd.setCursor(12,1);
      lcd.print("BACK");      
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("SETUP TIME");
      lcd.setCursor(12,1);
      lcd.print("BACK");       
      break;
    case 3:
      // LỆNH ĐIỀU KHIỂN
      break;                       
  }
}

void menu_dieukhien() // HIỂN THỊ MENU ĐIỀU KHIỂN
{
  if (congtru_menudk == 0)
  {
    lcd.clear();
    lcd.print(">BACK");
    lcd.setCursor(0, 1);
    lcd.print(" LENH 1");  
  }
  else if (congtru_menudk == 1)
  {
    lcd.clear();
    lcd.print(" BACK");
    lcd.setCursor(0, 1);
    lcd.print(">LENH 1");    
  }
  else if (congtru_menudk == 2)
  {
    lcd.clear();
    lcd.print(">LENH 2");
    lcd.setCursor(0, 1);
    lcd.print(" LENH 3");    
  } 
  else if (congtru_menudk == 3)
  {
    lcd.clear();
    lcd.print(" LENH 2");
    lcd.setCursor(0, 1);
    lcd.print(">LENH 3");    
  } 
  else if (congtru_menudk == 4)
  {
    lcd.clear();
    lcd.print(">LENH 4");
    lcd.setCursor(0, 1);
    lcd.print(" LENH 5");    
  } 
  else if (congtru_menudk == 5)
  {
    lcd.clear();
    lcd.print(" LENH 4");
    lcd.setCursor(0, 1);
    lcd.print(">LENH 5");    
  }        
}

void chonmenu_dieukhien() // CHỌN MENU ĐIỀU KHIỂN
{
  switch (congtru_menudk) 
  {
    case 0:
      //BACK
      break;
    case 1:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TON: ");
      lcd.setCursor(11,0);
      lcd.print("RE: ");      
      lcd.setCursor(0,1);
      lcd.print("TOF: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");
      break;
    case 2:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TON: ");
      lcd.setCursor(11,0);
      lcd.print("RE: ");      
      lcd.setCursor(0,1);
      lcd.print("TOF: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");     
      break;
    case 3:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TON: ");
      lcd.setCursor(11,0);
      lcd.print("RE: ");      
      lcd.setCursor(0,1);
      lcd.print("TOF: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");     
      break;
    case 4:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TON: ");
      lcd.setCursor(11,0);
      lcd.print("RE: ");      
      lcd.setCursor(0,1);
      lcd.print("TOF: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");       
      break;
    case 5:
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("TON: ");
      lcd.setCursor(11,0);
      lcd.print("RE: ");      
      lcd.setCursor(0,1);
      lcd.print("TOF: ");
      lcd.setCursor(12,1);
      lcd.print("BACK");       
      break;                             
  }
}

void setup() 
{
  Serial.begin(9600);
  rtc.begin();
  
  lcd.init();
  lcd.backlight();
  
  pinMode(len, INPUT_PULLUP);
  pinMode(xuong, INPUT_PULLUP);
  pinMode(menu, INPUT_PULLUP);
  pinMode(relay1, OUTPUT);
  pinMode(relay2, OUTPUT);

}

void loop() 
{
  t = rtc.getTime();
  
  gtlen = digitalRead(len);  
  gtxuong = digitalRead(xuong);  
  gtmenu = digitalRead(menu);
  // Serial.print("LÊN: "); Serial.print(gtlen); Serial.print("    ");
  // Serial.print("XUỐNG: "); Serial.print(gtxuong); Serial.print("    ");
  // Serial.print("Menu: "); Serial.println(gtmenu);

if (gtlen != macdinh)  // NÚT LÊN
{
  if (gtlen == 0) // Khi nhấn nút lên
  {
    if (demtong == 1)   // LÊN Ở MENU TỔNG  
    {
      if (congtru_tong >= 3)
      { 
        congtru_tong = 0;  
      }
      else
      { 
        congtru_tong++;  
      }   
      menu_tong();
    }
    
    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2))   // + CON TRỎ ở SET DATE và TIME
    {
      contro ++;
      if (contro > 15)
      {
        contro = 0;
      }
    }

    else if (demtong == 3 && congtru_tong == 3)   // + CON TRỎ ở ĐIỀU KHIỂN
    {
      contro_dk ++;
      if (hang == 0){
        if (contro_dk > 15)
        {
          contro_dk = 5;
          hang = 1;
        }
      } else {
        if (contro_dk > 15)
        {
          contro_dk = 5;
          hang = 0;
        }       
      }
    }
    
    else if (demtong == 3 && congtru_tong == 1)   // - ở NGÀY, THÁNG, NĂM
    {
      if ((contro == 0 or contro == 1)){ //NGÀY
        ngay --;
        if (ngay < 1){
          ngay = 31;
        }
      }
      else if ((contro == 3 or contro == 4)){ //THÁNG
        thang --;
        if (thang < 1){
          thang = 12;
        }
      }

        else if (contro == 6){ //NĂM NGHÌN
          namng --;
          if (namng < 0){
            namng = 9;
          }
        }
        else if (contro == 7){ //NĂM TRĂM
          namtr --;
          if (namtr < 0){
            namtr = 9;
          }
        }
        else if (contro == 8){ //NĂM CHỤC
          namch --;
          if (namch < 0){
            namch = 9;
          }
        }
        else if (contro == 9){ //NĂM ĐƠN VỊ
          namdv --;
          if (namdv < 0){
            namdv = 9;
          }
        }

    }

    else if (demtong == 3 && congtru_tong == 2 ) // - ở GIỜ : PHÚT : GIÂY
    {
      if ((contro == 0 or contro == 1)){ //GIỜ
        gio --;
        if (gio < 0){
          gio = 23;
        }
      }
      else if ((contro == 3 or contro == 4)){ //PHÚT
        phut --;
        if (phut < 0){
          phut = 59;
        }
      }
      else if ((contro == 6 or contro == 7)){ //GIÂY
        giay --;
        if (giay < 0){
          giay = 59;
        }    
      }
    }  

    else if (demtong == 2 && congtru_tong == 3) //Lên ở MENU ĐIỀU KHIỂN
    {
      congtru_menudk ++;
      if (congtru_menudk > 5){
        congtru_menudk = 0;
      }
      menu_dieukhien();
    }  
    
    else if (demtong == 4 && congtru_tong == 3) // - ĐIỀU KHIỂN | GIỜ ON - OFF, RELAY
    {
      if (congtru_menudk == 1 && (contro_dk == 5 or contro_dk == 6)){ // - GIỜ ON - OFF 1
        if (hang == 0){ //GIỜ ON 1
          ton1 --;
          if (ton1 < 0){
            ton1 = 23;
          }
        } else if (hang == 1){ //GIỜ OFF 1
          tof1 --;
          if (tof1 < 0){
            tof1 = 23;
          }
        }
      }

      else if (congtru_menudk == 1 && (contro_dk == 8 or contro_dk == 9)){ // - PHÚT ON - OFF 1
        if (hang == 0){ //PHÚT ON 1
          pon1 --;
          if (pon1 < 0){
            pon1 = 59;
          }
        } else if (hang == 1){ //PHÚT OFF 1
          pof1 --;
          if (pof1 < 0){
            pof1 = 59;
          }      
        }
      }

      else if (congtru_menudk == 2 && (contro_dk == 5 or contro_dk == 6)){ // - GIỜ ON - OFF 2
        if (hang == 0){ //GIỜ ON 2
          ton2 --;
          if (ton2 < 0){
            ton2 = 23;
          }
        } else if (hang == 1){ //GIỜ OFF 2
          tof2 --;
          if (tof2 < 0){
            tof2 = 23;
          }
        }
      }

      else if (congtru_menudk == 2 && (contro_dk == 8 or contro_dk == 9)){ // - PHÚT ON - OFF 2
        if (hang == 0){ //PHÚT ON 2
          pon2 --;
          if (pon2 < 0){
            pon2 = 59;
          }
        } else if (hang == 1){ //PHÚT OFF 2
          pof2 --;
          if (pof2 < 0){
            pof2 = 59;
          }      
        }
      }

      else if (congtru_menudk == 3 && (contro_dk == 5 or contro_dk == 6)){ // - GIỜ ON - OFF 3
        if (hang == 0){ //GIỜ ON 3
          ton3 --;
          if (ton3 < 0){
            ton3 = 23;
          }
        } else if (hang == 1){ //GIỜ OFF 3
          tof3 --;
          if (tof3 < 0){
            tof3 = 23;
          }
        }
      }

      else if (congtru_menudk == 3 && (contro_dk == 8 or contro_dk == 9)){ // - PHÚT ON - OFF 3
        if (hang == 0){ //PHÚT ON 3
          pon3 --;
          if (pon3 < 0){
            pon3 = 59;
          }
        } else if (hang == 1){ //PHÚT OFF 3
          pof3 --;
          if (pof3 < 0){
            pof3 = 59;
          }      
        }
      }

      else if (congtru_menudk == 4 && (contro_dk == 5 or contro_dk == 6)){ // - GIỜ ON - OFF 4
        if (hang == 0){ //GIỜ ON 4
          ton4 --;
          if (ton4 < 0){
            ton4 = 23;
          }
        } else if (hang == 1){ //GIỜ OFF 4
          tof4 --;
          if (tof4 < 0){
            tof4 = 23;
          }
        }
      }

      else if (congtru_menudk == 4 && (contro_dk == 8 or contro_dk == 9)){ // - PHÚT ON - OFF 4
        if (hang == 0){ //PHÚT ON 4
          pon4 --;
          if (pon4 < 0){
            pon4 = 59;
          }
        } else if (hang == 1){ //PHÚT OFF 4
          pof4 --;
          if (pof4 < 0){
            pof4 = 59;
          }      
        }
      }

      else if (congtru_menudk == 5 && (contro_dk == 5 or contro_dk == 6)){ // - GIỜ ON - OFF 5
        if (hang == 0){ //GIỜ ON 5
          ton5 --;
          if (ton5 < 0){
            ton5 = 23;
          }
        } else if (hang == 1){ //GIỜ OFF 5
          tof5 --;
          if (tof5 < 0){
            tof5 = 23;
          }
        }
      }

      else if (congtru_menudk == 5 && (contro_dk == 8 or contro_dk == 9)){ // - PHÚT ON - OFF 5
        if (hang == 0){ //PHÚT ON 5
          pon5 --;
          if (pon5 < 0){
            pon5 = 59;
          }
        } else if (hang == 1){ //PHÚT OFF 5
          pof5 --;
          if (pof5 < 0){
            pof5 = 59;
          }      
        }
      }                        

      else if(congtru_menudk == 1 && hang == 0 && contro_dk == 14){ // - RELAY ở LỆNH 1
        re1 --;
        if (re1 < 1){
          re1 = 3;
        }
      }
      else if(congtru_menudk == 2 && hang == 0 && contro_dk == 14){ // - RELAY ở LỆNH 2
        re2 --;
        if (re2 < 1){
          re2 = 3;
        }
      }
      else if(congtru_menudk == 3 && hang == 0 && contro_dk == 14){ // - RELAY ở LỆNH 3
        re3 --;
        if (re3 < 1){
          re3 = 3;
        }
      }
      else if(congtru_menudk == 4 && hang == 0 && contro_dk == 14){ // - RELAY ở LỆNH 4
        re4 --;
        if (re4 < 1){
          re4 = 3;
        }
      }
      else if(congtru_menudk == 5 && hang == 0 && contro_dk == 14){ // - RELAY ở LỆNH 5
        re5 --;
        if (re5 < 1){
          re5 = 3;
        }
      }                        
    }                                         

    delay(200);
  }
  macdinh = gtlen;
}

if (gtxuong != macdinh) // NÚT XUỐNG
{
  if (gtxuong == 0) //Khi nhấn nút xuống
  {
    if (demtong == 1)   // XUỐNG Ở MENU TỔNG
    {
      if (congtru_tong <= 0)
      { 
        congtru_tong = 3;  
      }
      else
      { 
        congtru_tong--;  
      }
      menu_tong();
    }
    
    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2))   // - CON TRỎ ở SET DATE và TIME
    {
      contro --;
      if (contro < 0)
      {
        contro = 15;
      }
    }

    else if (demtong == 3 && congtru_tong == 3) // - CON TRỎ ở ĐIỀU KHIỂN
    {
      contro_dk --;
      if (hang == 0){
        if (contro_dk < 5)
        {
          contro_dk = 15;
          hang = 1;        
        }
      } else {
        if (contro_dk < 5)
        {
          contro_dk = 15;
          hang = 0;        
        }        
      }    
    }
    
    else if (demtong == 3 && congtru_tong == 1)   // + ở NGÀY, THÁNG, NĂM
    {
      if (contro == 0 or contro == 1){ // + NGÀY ở DATE
        ngay ++;
        if (ngay > 31){
          ngay = 1;
        }
      }
      else if (contro == 3 or contro == 4){ // + THÁNG ở DATE
        thang ++;
        if (thang > 12){
          thang = 1;
        }        
      }
      else if (contro == 6){ // + NĂM NGHÌN
        namng ++;
        if (namng > 9){
          namng = 0;
        }
      }
      else if (contro == 7){// + NĂM TRĂM
        namtr ++;
        if (namtr > 9){
          namtr = 0;
        }
      }
      else if (contro == 8){// + NĂM CHỤC
        namch ++;
        if (namch > 9){
          namch = 0;
        }
      }
      else if (contro == 9){// + NĂM ĐƠN VỊ
        namdv ++;
        if (namdv > 9){
          namdv = 0;
        }
      }
    }

    else if (demtong == 3 && congtru_tong == 2) //+ ở GIỜ : PHÚT :GIÂY
    {
      if (contro == 0 or contro == 1){ //GIỜ
        gio ++;
        if (gio > 23){
          gio = 0;
        }      
      }
      else if (contro == 3 or contro == 4){ //PHÚT
        phut ++;
        if (phut > 59){
          phut = 0;
        }
      }
      else if (contro == 6 or contro == 7){ //GIÂY
        giay ++;
        if (giay > 59){
          giay = 0;
        }
      }
    } 

    else if (demtong == 2 && congtru_tong == 3) //Xuống ở MENU ĐIỀU KHIỂN
    {
      congtru_menudk --;
      if (congtru_menudk < 0){
        congtru_menudk = 5;
      }
      menu_dieukhien();
    } 

    else if (demtong == 4 && congtru_tong == 3) //+ ĐIỀU KHIỂN | GIỜ ON - OFF, RELAY
    {
      if (congtru_menudk == 1 && (contro_dk == 5 or contro_dk == 6)){ //+ GIỜ ON - OFF 1
        if (hang == 0){ //GIỜ ON 1
          ton1 ++;
          if (ton1 > 23){
            ton1 = 0;
          }
        } else if (hang == 1){ //GIỜ OFF 1
          tof1 ++;
          if (tof1 > 23){
            tof1 = 0;
          }
        }
      }

      else if (congtru_menudk == 1 && (contro_dk == 8 or contro_dk == 9)){ //+ PHÚT ON - OFF 1
        if (hang == 0){ //PHÚT ON 1
          pon1 ++;
          if (pon1 > 59){
            pon1 = 0;
          }
        } else if (hang == 1){ //PHÚT OFF 1
          pof1 ++;
          if (pof1 > 59){
            pof1 = 0;
          }        
        }
      }

      else if (congtru_menudk == 2 && (contro_dk == 5 or contro_dk == 6)){ //+ GIỜ ON - OFF 2
        if (hang == 0){ //GIỜ ON 2
          ton2 ++;
          if (ton2 > 23){
            ton2 = 0;
          }
        } else if (hang == 1){ //GIỜ OFF 2
          tof2 ++;
          if (tof2 > 23){
            tof2 = 0;
          }
        }
      }

      else if (congtru_menudk == 2 && (contro_dk == 8 or contro_dk == 9)){ //+ PHÚT ON - OFF 2
        if (hang == 0){ //PHÚT ON 2
          pon2 ++;
          if (pon2 > 59){
            pon2 = 0;
          }
        } else if (hang == 1){ //PHÚT OFF 2
          pof2 ++;
          if (pof2 > 59){
            pof2 = 0;
          }        
        }
      }

      else if (congtru_menudk == 3 && (contro_dk == 5 or contro_dk == 6)){ //+ GIỜ ON - OFF 3
        if (hang == 0){ //GIỜ ON 3
          ton3 ++;
          if (ton3 > 23){
            ton3 = 0;
          }
        } else if (hang == 1){ //GIỜ OFF 3
          tof3 ++;
          if (tof3 > 23){
            tof3 = 0;
          }
        }
      }

      else if (congtru_menudk == 3 && (contro_dk == 8 or contro_dk == 9)){ //+ PHÚT ON - OFF 3
        if (hang == 0){ //PHÚT ON 3
          pon3 ++;
          if (pon3 > 59){
            pon3 = 0;
          }
        } else if (hang == 1){ //PHÚT OFF 3
          pof3 ++;
          if (pof3 > 59){
            pof3 = 0;
          }        
        }
      }

      else if (congtru_menudk == 4 && (contro_dk == 5 or contro_dk == 6)){ //+ GIỜ ON - OFF 4
        if (hang == 0){ //GIỜ ON 4
          ton4 ++;
          if (ton4 > 23){
            ton4 = 0;
          }
        } else if (hang == 1){ //GIỜ OFF 4
          tof4 ++;
          if (tof4 > 23){
            tof4 = 0;
          }
        }
      }

      else if (congtru_menudk == 4 && (contro_dk == 8 or contro_dk == 9)){ //+ PHÚT ON - OFF 4
        if (hang == 0){ //PHÚT ON 4
          pon4 ++;
          if (pon4 > 59){
            pon4 = 0;
          }
        } else if (hang == 1){ //PHÚT OFF 4
          pof4 ++;
          if (pof4 > 59){
            pof4 = 0;
          }        
        }
      }

      else if (congtru_menudk == 5 && (contro_dk == 5 or contro_dk == 6)){ //+ GIỜ ON - OFF 5
        if (hang == 0){ //GIỜ ON 5
          ton5 ++;
          if (ton5 > 23){
            ton5 = 0;
          }
        } else if (hang == 1){ //GIỜ OFF 5
          tof5 ++;
          if (tof5 > 23){
            tof5 = 0;
          }
        }
      }

      else if (congtru_menudk == 5 && (contro_dk == 8 or contro_dk == 9)){ //+ PHÚT ON - OFF 5
        if (hang == 0){ //PHÚT ON 5
          pon5 ++;
          if (pon5 > 59){
            pon5 = 0;
          }
        } else if (hang == 1){ //PHÚT OFF 5
          pof5 ++;
          if (pof5 > 59){
            pof5 = 0;
          }        
        }
      }                        

      else if(congtru_menudk == 1 && hang == 0 && contro_dk == 14){ // + RELAY ở LỆNH 1
        re1 ++;
        if (re1 > 3){
          re1 = 1;
        }
      }
      else if(congtru_menudk == 2 && hang == 0 && contro_dk == 14){ // + RELAY ở LỆNH 2
        re2 ++;
        if (re2 > 3){
          re2 = 1;
        }
      }
      else if(congtru_menudk == 3 && hang == 0 && contro_dk == 14){ // + RELAY ở LỆNH 3
        re3 ++;
        if (re3 > 3){
          re3 = 1;
        }
      }
      else if(congtru_menudk == 4 && hang == 0 && contro_dk == 14){ // + RELAY ở LỆNH 4
        re4 ++;
        if (re4 > 3){
          re4 = 1;
        }
      }
      else if(congtru_menudk == 5 && hang == 0 && contro_dk == 14){ // + RELAY ở LỆNH 5
        re5 ++;
        if (re5 > 3){
          re5 = 1;
        }
      }                        
    }                                                  

    delay(200);
  }
  macdinh = gtxuong;
}

if (gtmenu != macdinh)    // NÚT MENU
{  
  if (gtmenu == 0) //Khi nhấn nút
  {  
    demtong ++;

    if (demtong == 1) //Ở menu tổng
    { 
      menu_tong(); 
    }
      else if (demtong == 2 && congtru_tong == 0) //Nhấn BACK từ Menu tổng về màn hình
      {
        demtong = 0;
        manhinh(); 
      }       

    else if (demtong == 2 && (congtru_tong == 1 or congtru_tong == 2)) // chọn menu tổng DATE or TIME
    {
      chonmenu_tong();
    }                                      
      
      else if (demtong == 4 && congtru_tong == 1) //Thoát CON TRỎ từ SET DATE ra
      {
        demtong = 2;
        chonmenu_tong();
      }       
      else if (demtong == 4 && congtru_tong == 2) //Thoát CON TRỎ từ SET TIME ra
      {
        demtong = 2;
        chonmenu_tong();        
      }
    
    else if (demtong == 3 && (congtru_tong == 2 or congtru_tong == 1) && // Thoát từ SET DATE or TIME ra
            (contro == 12 or contro == 13 or contro == 14 or contro == 15)) 
      {
        demtong = 1;
        congtru_tong = 0;
        contro = 0;
        menu_tong();
        lcd.noCursor();
      }      

    else if (demtong == 2 && congtru_tong == 3) //Menu ĐIỀU KHIỂN
    {
      menu_dieukhien();
    }

      else if (demtong == 3 && congtru_tong == 3 && congtru_menudk == 0) //từ Menu ĐIỀU KHIỂN về Menu TỔNG
      {
        demtong = 1;
        congtru_menudk = 0;
        menu_tong();
      }

      else if (demtong == 3 && congtru_tong == 3 && (congtru_menudk == 1 or congtru_menudk == 2 
              or congtru_menudk == 3 or congtru_menudk == 4 or congtru_menudk == 5)) //chọn menu ĐK
      {
        chonmenu_dieukhien();
      }

      else if (demtong == 5 && congtru_tong == 3 && (congtru_menudk == 1 or congtru_menudk == 2
              or congtru_menudk == 3 or congtru_menudk == 4 or congtru_menudk == 5))  //Từ CON TRỎ ĐK chức năng SET ra
      {
        chonmenu_dieukhien();
        demtong = 3;
      }

      else if (demtong == 4 && congtru_tong == 3 && (contro_dk == 12 or 
              contro_dk == 13 or contro_dk == 14 or contro_dk == 15) && hang == 1) //Thoát từ SET BT ra menu báo thức
      {
        menu_dieukhien();
        demtong = 2;
        congtru_tong = 3;
        contro_dk = 5;
        hang = 0;
        lcd.noCursor();
      }

    delay(100);
  }
  macdinh = gtmenu;
}

if (demtong == 0 && congtru_tong == 0) // MÀN HÌNH
{
  manhinh();
  lcd.noCursor();
  
  //int re1 = 1; int re2 = 3; int re3 = 2; int re4 = 3; int re5 = 3; //RELAY
  if(t.hour == ton1 && t.min == pon1 && t.sec == 2){ //LỆNH 1 ON
    if(re1 == 1){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
    }
    else if(re1 == 2){
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}    
    }
    else if(re1 == 3){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}          
    }
  }
  else if (t.hour == tof1 && t.min == pof1 && t.sec == 1){ //LỆNH 1 OFF
    if(re1 == 1){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
    }
    else if(re1 == 2){
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}    
    }
    else if(re1 == 3){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}          
    }
  }
  else if(t.hour == ton2 && t.min == pon2 && t.sec == 2){ //LỆNH 2 ON
    if(re2 == 1){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
    }
    else if(re2 == 2){
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}    
    }
    else if(re2 == 3){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}          
    }
  }
  else if (t.hour == tof2 && t.min == pof2 &&  t.sec == 1){ //LỆNH 2 OFF
    if(re2 == 1){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
    }
    else if(re2 == 2){
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}    
    }
    else if(re2 == 3){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}         
    }
  }
  else if(t.hour == ton3 && t.min == pon3 && t.sec == 2){ //LỆNH 3 ON
    if(re3 == 1){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
    }
    else if(re3 == 2){
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}    
    }
    else if(re3 == 3){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}          
    }
  }
  else if (t.hour == tof3 && t.min == pof3 &&  t.sec == 1){ //LỆNH 3 OFF
    if(re3 == 1){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
    }
    else if(re3 == 2){
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}   
    }
    else if(re3 == 3){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}          
    }
  }
  else if(t.hour == ton4 && t.min == pon4 && t.sec == 2){ //LỆNH 4 ON
    if(re4 == 1){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
    }
    else if(re4 == 2){
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}   
    }
    else if(re4 == 3){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}         
    }
  }
  else if (t.hour == tof4 && t.min == pof4 &&  t.sec == 1){ //LỆNH 4 OFF
    if(re4 == 1){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
    }
    else if(re4 == 2){
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}  
    }
    else if(re4 == 3){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}          
    }
  }
  else if(t.hour == ton5 && t.min == pon5 && t.sec == 2){ //LỆNH 5 ON
    if(re5 == 1){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
    }
    else if(re5 == 2){
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}    
    }
    else if(re5 == 3){
      if (digitalRead(relay1) == LOW){
        digitalWrite(relay1, HIGH);
      } else {digitalWrite(relay1, HIGH);}
      if (digitalRead(relay2) == LOW){
        digitalWrite(relay2, HIGH);
      } else {digitalWrite(relay2, HIGH);}         
    }
  }
  else if (t.hour == tof5 && t.min == pof5 &&  t.sec == 1){ //LỆNH 5 OFF
    if(re5 == 1){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
    }
    else if(re5 == 2){
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}    
    }
    else if(re5 == 3){
      if (digitalRead(relay1) == HIGH){
        digitalWrite(relay1, LOW);
      } else {digitalWrite(relay1, LOW);}
      if (digitalRead(relay2) == HIGH){
        digitalWrite(relay2, LOW);
      } else {digitalWrite(relay2, LOW);}        
    }
  }  
}

else if ((demtong == 2 or demtong == 3) && congtru_tong == 1) //SETUP DATE
{
  if (ngay < 10){
    lcd.setCursor(0,1); lcd.print("0");
    lcd.setCursor(1,1); lcd.print(ngay);
  } else {
    lcd.setCursor(0,1); lcd.print(ngay);    
  }
  lcd.setCursor(2,1); lcd.print("/");
  if (thang < 10){
    lcd.setCursor(3,1); lcd.print("0"); 
    lcd.setCursor(4,1); lcd.print(thang);
  } else {
    lcd.setCursor(3,1); lcd.print(thang);    
  }
  lcd.setCursor(5,1); lcd.print("/"); 
  lcd.setCursor(6,1); lcd.print(namng); lcd.setCursor(7,1); lcd.print(namtr);
  lcd.setCursor(8,1); lcd.print(namch); lcd.setCursor(9,1); lcd.print(namdv);  
  namtong = (namng * 1000) + (namtr * 100) + (namch * 10) + namdv;

  lcd.setCursor(contro, 1); 
  lcd.cursor();
  delay(50);  

  rtc.setDate(ngay, thang, namtong);
}

else if ((demtong == 2 or demtong == 3) && congtru_tong == 2) //SETUP TIME
{
  if (gio < 10){
    lcd.setCursor(0,1); lcd.print("0");
    lcd.setCursor(1,1); lcd.print(gio);
  } else {
    lcd.setCursor(0,1); lcd.print(gio);
  }
  lcd.setCursor(2,1); lcd.print(":");
  if (phut < 10){
    lcd.setCursor(3,1); lcd.print("0"); 
    lcd.setCursor(4,1); lcd.print(phut);
  } else {
    lcd.setCursor(3,1); lcd.print(phut);    
  }  
  lcd.setCursor(5,1); lcd.print(":");
  if (giay < 10){
    lcd.setCursor(6,1); lcd.print("0"); 
    lcd.setCursor(7,1); lcd.print(giay);
  } else {
    lcd.setCursor(6,1); lcd.print(giay);    
  }

  lcd.setCursor(contro, 1); 
  lcd.cursor();
  delay(50);

  rtc.setTime(gio, phut, giay);   
}

else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menudk == 1) //LỆNH 1
{
  if (ton1 < 10){
    lcd.setCursor(5,0); lcd.print("0");
    lcd.setCursor(6,0); lcd.print(ton1);
  } else {
    lcd.setCursor(5,0); lcd.print(ton1);
  }
  lcd.setCursor(7,0); lcd.print(":");
  if (pon1 < 10){
    lcd.setCursor(8,0); lcd.print("0"); 
    lcd.setCursor(9,0); lcd.print(pon1);
  } else {
    lcd.setCursor(8,0); lcd.print(pon1);    
  }

    lcd.setCursor(14,0); lcd.print(re1); //relay 

  if (tof1 < 10){
    lcd.setCursor(5,1); lcd.print("0");
    lcd.setCursor(6,1); lcd.print(tof1);
  } else {
    lcd.setCursor(5,1); lcd.print(tof1);
  }
  lcd.setCursor(7,1); lcd.print(":");
  if (pof1 < 10){
    lcd.setCursor(8,1); lcd.print("0"); 
    lcd.setCursor(9,1); lcd.print(pof1);
  } else {
    lcd.setCursor(8,1); lcd.print(pof1);    
  }

  lcd.setCursor(contro_dk, hang); 
  lcd.cursor();
  delay(50);        
}

else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menudk == 2) //LỆNH 2
{
  if (ton2 < 10){
    lcd.setCursor(5,0); lcd.print("0");
    lcd.setCursor(6,0); lcd.print(ton2);
  } else {
    lcd.setCursor(5,0); lcd.print(ton2);
  }
  lcd.setCursor(7,0); lcd.print(":");
  if (pon2 < 10){
    lcd.setCursor(8,0); lcd.print("0"); 
    lcd.setCursor(9,0); lcd.print(pon2);
  } else {
    lcd.setCursor(8,0); lcd.print(pon2);    
  }

    lcd.setCursor(14,0); lcd.print(re2); //relay 

  if (tof2 < 10){
    lcd.setCursor(5,1); lcd.print("0");
    lcd.setCursor(6,1); lcd.print(tof2);
  } else {
    lcd.setCursor(5,1); lcd.print(tof2);
  }
  lcd.setCursor(7,1); lcd.print(":");
  if (pof2 < 10){
    lcd.setCursor(8,1); lcd.print("0"); 
    lcd.setCursor(9,1); lcd.print(pof2);
  } else {
    lcd.setCursor(8,1); lcd.print(pof2);    
  }

  lcd.setCursor(contro_dk, hang); 
  lcd.cursor();
  delay(50);        
}

else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menudk == 3) //LỆNH 3
{
  if (ton3 < 10){
    lcd.setCursor(5,0); lcd.print("0");
    lcd.setCursor(6,0); lcd.print(ton3);
  } else {
    lcd.setCursor(5,0); lcd.print(ton3);
  }
  lcd.setCursor(7,0); lcd.print(":");
  if (pon3 < 10){
    lcd.setCursor(8,0); lcd.print("0"); 
    lcd.setCursor(9,0); lcd.print(pon3);
  } else {
    lcd.setCursor(8,0); lcd.print(pon3);    
  }

    lcd.setCursor(14,0); lcd.print(re3); //relay 

  if (tof3 < 10){
    lcd.setCursor(5,1); lcd.print("0");
    lcd.setCursor(6,1); lcd.print(tof3);
  } else {
    lcd.setCursor(5,1); lcd.print(tof3);
  }
  lcd.setCursor(7,1); lcd.print(":");
  if (pof3 < 10){
    lcd.setCursor(8,1); lcd.print("0"); 
    lcd.setCursor(9,1); lcd.print(pof3);
  } else {
    lcd.setCursor(8,1); lcd.print(pof3);    
  }

  lcd.setCursor(contro_dk, hang); 
  lcd.cursor();
  delay(50);        
}

else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menudk == 4) //LỆNH 4
{
  if (ton4 < 10){
    lcd.setCursor(5,0); lcd.print("0");
    lcd.setCursor(6,0); lcd.print(ton4);
  } else {
    lcd.setCursor(5,0); lcd.print(ton4);
  }
  lcd.setCursor(7,0); lcd.print(":");
  if (pon4 < 10){
    lcd.setCursor(8,0); lcd.print("0"); 
    lcd.setCursor(9,0); lcd.print(pon4);
  } else {
    lcd.setCursor(8,0); lcd.print(pon4);    
  }

    lcd.setCursor(14,0); lcd.print(re4); //relay 

  if (tof4 < 10){
    lcd.setCursor(5,1); lcd.print("0");
    lcd.setCursor(6,1); lcd.print(tof4);
  } else {
    lcd.setCursor(5,1); lcd.print(tof4);
  }
  lcd.setCursor(7,1); lcd.print(":");
  if (pof4 < 10){
    lcd.setCursor(8,1); lcd.print("0"); 
    lcd.setCursor(9,1); lcd.print(pof4);
  } else {
    lcd.setCursor(8,1); lcd.print(pof4);    
  }

  lcd.setCursor(contro_dk, hang); 
  lcd.cursor();
  delay(50);        
}

else if ((demtong == 3 or demtong == 4) && congtru_tong == 3 && congtru_menudk == 5) //LỆNH 5
{
  if (ton5 < 10){
    lcd.setCursor(5,0); lcd.print("0");
    lcd.setCursor(6,0); lcd.print(ton5);
  } else {
    lcd.setCursor(5,0); lcd.print(ton5);
  }
  lcd.setCursor(7,0); lcd.print(":");
  if (pon5 < 10){
    lcd.setCursor(8,0); lcd.print("0"); 
    lcd.setCursor(9,0); lcd.print(pon5);
  } else {
    lcd.setCursor(8,0); lcd.print(pon5);    
  }

    lcd.setCursor(14,0); lcd.print(re5); //relay 

  if (tof5 < 10){
    lcd.setCursor(5,1); lcd.print("0");
    lcd.setCursor(6,1); lcd.print(tof5);
  } else {
    lcd.setCursor(5,1); lcd.print(tof5);
  }
  lcd.setCursor(7,1); lcd.print(":");
  if (pof5 < 10){
    lcd.setCursor(8,1); lcd.print("0"); 
    lcd.setCursor(9,1); lcd.print(pof5);
  } else {
    lcd.setCursor(8,1); lcd.print(pof5);    
  }

  lcd.setCursor(contro_dk, hang); 
  lcd.cursor();
  delay(50);        
}

  Serial.print("Đếm tổng: "); Serial.print(demtong); Serial.print("    ");
  Serial.print("+/- tổng: "); Serial.print(congtru_tong); Serial.print("    ");
  Serial.print("CT Điều khiển: "); Serial.print(contro_dk); Serial.print("    ");
  Serial.print("Hàng: "); Serial.print(hang); Serial.print("    ");   
  Serial.print("+/- menu báo thức: "); Serial.print(congtru_menudk); Serial.print("    ");
  Serial.print("Con trỏ: "); Serial.println(contro);

} //KẾT LOOP
