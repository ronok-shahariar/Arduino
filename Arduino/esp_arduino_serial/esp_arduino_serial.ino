#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#define FIREBASE_HOST "led-on-off-8b6af.firebaseio.com"
#define FIREBASE_AUTH "dhJ9q6pP5qAQZ0fRJdInSmlCzews5IIZks16uGhP"
#define WIFI_SSID "Death Note"
#define WIFI_PASSWORD "lightyagami37"
#include <SoftwareSerial.h>
SoftwareSerial mySerial (13,15);

#define Relay1 D1 
#define Relay2 D2 

void setup() {
Serial.begin(115200);

pinMode(Relay1, OUTPUT);
pinMode(Relay2, OUTPUT);

// connect to wifi.
WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("connecting");
while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(500);
    }
      Serial.println();
      Serial.print("connected: ");
      Serial.println(WiFi.localIP());
      Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

      Firebase.set("S1", 0);
      Firebase.set("S2", 0);
}
int n;
int m;
void loop() {
  
// get value for D1
n = Firebase.getString("S1").toInt();
if(n == 1){
  Serial.println(n);
}else{
  Serial.println(n);
}
  
//delay(5000);

//m = Firebase.getString("S2").toInt();
//Serial.println(m);
//delay(5000);

   
}
