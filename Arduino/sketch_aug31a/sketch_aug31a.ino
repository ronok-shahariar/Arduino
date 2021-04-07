#include <SoftwareSerial.h>
//#define Relay1 D2 
SoftwareSerial mySerial (13,15);

void setup() {
    Serial.begin(9600);
    //mySerial.begin(115200);
    //pinMode(Relay1, OUTPUT);

}

void loop() {
    //int msg =mySerial.readStringUntil('\r').toInt();
   
    //Serial.println(msg);
    //digitalWrite(Relay1,HIGH);
    Serial.println("1");
    delay(1000);
    //digitalWrite(Relay1,LOW);
    Serial.println("0");
    delay(1000);
    
  
}
