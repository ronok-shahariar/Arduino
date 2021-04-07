#define Relay1 7 

void setup() {
    Serial.begin(115200);
   
    pinMode(Relay1, OUTPUT);
    while(!Serial);
    Serial.println("1 to ON 0 to OFF");

}

void loop() {
  if (Serial.available()){
    String state = Serial.readString();
    if (state == "On-Off button1: ON"){
      digitalWrite(7,HIGH);
      Serial.println("1 to ON");
    }else{
      digitalWrite(7,LOW);
      Serial.println("0 to OFF");
    }
  }else{
    Serial.println("Not connected...");
  }
  
}
