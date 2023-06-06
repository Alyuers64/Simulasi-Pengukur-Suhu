#include "LiquidCrystal.h"
LiquidCrystal lcd(8,7,6,5,4,3);
int sensorPin = 0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
}

void loop()
{
  int hasil = analogRead(sensorPin);
  
  //kalkulasi voltage dan suhu
  float voltage = hasil * 4.68;
  voltage /= 1024.0;
  
  //cetak hasil
  float suhu = (voltage - 0.5) * 100;
  Serial.print(suhu);
  
  	lcd.setCursor(0,0);
  	lcd.print("Suhu saat ini : ");
    lcd.setCursor(0,1);
    lcd.print(suhu);
  	lcd.print(" ");
    lcd.write(223); 
    lcd.print("C");
  
  delay(100);
}
    