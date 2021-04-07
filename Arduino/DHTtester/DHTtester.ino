#include <LiquidCrystal.h>
#include "DHT.h"

#define DHTPIN 8     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);
const int rs=7, en=6, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHTxx test!"));
  lcd.begin(16, 2);
  dht.begin();
}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  float h = dht.readHumidity();
 
  float t = dht.readTemperature();
  
  float f = dht.readTemperature(true);

 //  if (isnan(h) || isnan(t) || isnan(f)) {
   //   Serial.println(F("Failed to read from DHT sensor!"));
  //    return;
   // }

  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F("%  Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F  Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print("*C ");
  lcd.setCursor(0,1);
  lcd.print("Humdity: ");
  lcd.print(h);
  lcd.print("%");
}
