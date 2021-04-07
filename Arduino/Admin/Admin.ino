#include<ArduinoJson.h>
#include "DHT.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <SPI.h>
//ESP8266WiFiMulti WiFiMulti;

#define DHTPIN D2

#define DHTTYPE DHT11

DHT dht(DHTPIN,DHTTYPE);


float humidityData;
float temperatureData;


const char* ssid = "Death Note";// 
const char* password = "lightyagami37";
const char* deviceId = "iot31654";
//WiFiClient client;
char server[] = "192.168.0.1";   //eg: 192.168.0.222


WiFiClient client;    


void setup()
{
 Serial.begin(115200);
  delay(10);
  dht.begin();
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
//  server.begin();
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
 }
void loop()
{ 
  humidityData = dht.readHumidity();
  temperatureData = dht.readTemperature(); 
    Serial.print("humidity= ");
    Serial.print(humidityData);
    Serial.print(" & temperature= ");
    Serial.println(temperatureData);
    Serial.println("========================");
    Serial.println();  
  httpPOSTRequest();
  delay(15000); // interval
 }

 void httpGETRequest(){
  HTTPClient http;
  String url="http://localhost/testcode/dht.php?temperature="+temperatureData+"&humidity="+humidityData+"";
  http.begin(url);
  int requestCode=http.GET();
  if(requestCode>0){
    Serial.print("Request Code: ");
    Serial.println(requestCode);
    String response=http.getString();
    Serial.println(response);
    jsonGETDecoder(response);
  }
  yield();
 }

 void httpPOSTRequest(){
  HTTPClient http;
  String url="http://localhost/testcode/dht.php?temperature="+temperatureData+"&humidity="+humidityData+"";

  StaticJsonDocument<300> requestDoc;
  requestDoc["temperature"]=temperatureData;
  requestDoc["humidity"]=humidityData;
  requestDoc["deviceId"]=deviceId;

  char JSONmessagerBuffer[300];
  serializeJson(requestDoc,JSONmessagerBuffer);
  Serial.print("Request Body: ");
  Serial.println(JSONmessagerBuffer);
  
  http.begin(url);
  http.addHeader("Content-Type","application/json");
  int requestCode=http.POST(JSONmessagerBuffer);
  if(requestCode>0){
    Serial.print("Request Code: ");
    Serial.println(requestCode);
    String response=http.getString();
    Serial.println(response);
    jsonPOSTDecoder(response);
  }
yield();
}

void jsonGETDecoder(String response){
  const size_t bufferSize=JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(5)+200;
  DynamicJsonDocument resDoc(bufferSize);
  DeserializationError error=deserializeJson(resDoc,response);
  
  if(error){
    Serial.println("Error at JSON decode!");
    return;
  }
  const char* value1=resDoc["iotba30"];
  
    Serial.println(value1);
 const char* value2=resDoc["iotba18"];
 
    Serial.println(value2);
  }
 }

 void jsonPOSTDecoder(String response){
  const size_t bufferSize=JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(3)+JSON_OBJECT_SIZE(5)+200;
  DynamicJsonDocument resDoc(bufferSize);
  DeserializationError error=deserializeJson(resDoc,response);
  
  if(error){
    Serial.println("Error at JSON decode!");
    return;
  }
  const char* value1=resDoc["iotc31654"];
 
    Serial.println(value1);
    
 const char* value2=resDoc["iot31654"];
 
    Serial.println(value2);
  }
 }
