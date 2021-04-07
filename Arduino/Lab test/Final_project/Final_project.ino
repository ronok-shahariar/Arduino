#include <LiquidCrystal.h>
#include <SimpleDHT.h>

#define fan     11
#define tempMin 30
#define tempMax 40
#define humMin  70
#define humMax  80

int fanLCD;
int fanSpeed;
int pinDHT22 = 8;
SimpleDHT22 dht22(pinDHT22);

const int rs=7, en=6, d4=5, d5=4, d6=3, d7=2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16,2);
  Serial.begin(9600);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() { 
  // start working...
  Serial.println("=================================");
  Serial.println("Ronok(T,H,F,L)...");
  
  float temperature = 0;
  float humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht22.read2(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT22 failed, err="); Serial.println(err);delay(2000);
    return;
  }
  
  Serial.print("Data: ");
  Serial.print((float)temperature); Serial.print(" *C, ");
  Serial.print((float)humidity); Serial.println(" RH%");
  
  //delay(1000);

  lcd.setCursor(0,0);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print("*C ");
  lcd.setCursor(0,1);
  lcd.print("Humi:");
  lcd.print(humidity);
  lcd.print("%");
  
 if(temperature>=tempMin && temperature<=tempMax)
 {
  fanSpeed = map(temperature,tempMin,tempMax,32,255);
  fanLCD = map(temperature,tempMin,tempMax,0,100);
  analogWrite(fan,fanSpeed);
  lcd.setCursor(12,1);
  lcd.print("F:");
  lcd.print(fanLCD);
  Serial.print("Fan: ");
  Serial.print(fanLCD);
  Serial.print("%, ");
 }
  if(temperature<tempMin)
    {
    digitalWrite(11,LOW);
    lcd.setCursor(12,1);
    lcd.print("F_OF");
    Serial.print("Fan: F_OFF, ");
   }
  if(temperature>tempMax)
   { digitalWrite(11,HIGH);
    lcd.setCursor(12,1);
    lcd.print("F_FL");
    Serial.print("Fan: Full speed, ");
  }
  
    int sensorValue = analogRead(A0);
    Serial.print("LDR: ");Serial.println(sensorValue);
    
    if(sensorValue<15)
    {
      digitalWrite(12,HIGH);
      lcd.setCursor(13,0);
      lcd.print("Ni8");
    }else{
      digitalWrite(12,LOW);
      lcd.setCursor(13,0);
      lcd.print("Day");
    }
    delay(1000);
  }
