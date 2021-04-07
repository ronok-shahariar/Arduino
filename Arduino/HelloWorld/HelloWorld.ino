#include <LiquidCrystal.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const int rs=7, en=6, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
    float h = dht.readHumidity();
   float t = dht.readTemperature();
    
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("*C ");
  lcd.setCursor(0,1);
  lcd.print("Humdity: ");
  lcd.print(h);
  lcd.print("%");
  
}
