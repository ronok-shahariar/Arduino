#include <ESP8266WiFi.h>
#include <PubSubClient.h>

const char* ssid = "Death Note";
const char* password = "lightyagami37";
const char* mqtt_server="192.168.1.11";

WiFiClient espClient;
PubSubClient client(espClient);


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid,password);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Device IP: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server,1883);
}

void loop() {
  if(!client.connected()){
    reconnect();
  }
}

void reconnect()
{
  while(!client.connected()){
    Serial.println("Server connecting....");
    if(client.connect("ESP8266Client")){
      Serial.println("Server connected");
    }else{
      Serial.println("Failed to connect");
      delay(500);
    }
  }
}
