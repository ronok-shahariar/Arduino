#include "FirebaseESP8266.h"  // Install Firebase ESP8266 library
#include <ESP8266WiFi.h>

#define FIREBASE_HOST "https://dht-22-2e219-default-rtdb.firebaseio.com/"                          // the project name address from firebase id
#define FIREBASE_AUTH "Wd33rcag6dGaZnSHK32dQ3nSW3dgnai46cjTCdXQ"            // the secret key generated from firebase
#define WIFI_SSID "Death Note"
#define WIFI_PASSWORD "lightyagami37"
#define led D0
  
FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void loop() {
  int t = analogRead(A0);
  Serial.println(t);

}
