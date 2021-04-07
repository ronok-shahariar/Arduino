#define Relay1 7 

void setup() {
    Serial.begin(115200);
   
    pinMode(Relay1, OUTPUT);
    while(!Serial);
    Serial.println("1 to ON 0 to OFF");

}

void loop() {
  if (Serial.available()){
    int state = Serial.parseInt();
    if (state == 1){
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
