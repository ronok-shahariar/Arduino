#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
// Set these to run example.
#define FIREBASE_HOST "led-on-off-8b6af.firebaseio.com"
#define FIREBASE_AUTH "dhJ9q6pP5qAQZ0fRJdInSmlCzews5IIZks16uGhP"
#define WIFI_SSID "Death Note"
#define WIFI_PASSWORD "lightyagami37"
void setup() {
Serial.begin(115200);
pinMode(D1, OUTPUT);
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
Firebase.set("LED_STATUS", 0);
}
String n;
void loop() {
// get value
n = Firebase.getString("LED_STATUS");
Serial.println(n);
// handle error
if (n=="1") {
Serial.println("LED ON");
digitalWrite(D1,HIGH);  
return;
delay(10);
}
else {
Serial.println("LED OFF");
digitalWrite(D1,LOW);  
return;
}
}
