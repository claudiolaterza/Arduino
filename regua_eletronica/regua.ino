#include <HCSR04.h>

// DEFINIÇÕES DE PINOS
#define pinTrig 8
#define pinEcho 9
#define pinLed  2
#define button 7
#define bip 10
#define DEBUG 

HCSR04 sensorHCSR04(pinTrig,pinEcho);

void setup() {

  pinMode(button, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);
  pinMode(bip, OUTPUT);
  
  #ifdef DEBUG 
    Serial.begin(9600);
    Serial.println(F("| ============================================= |"));
    Serial.println(F("| ==============Régua do Claudão=============== |"));
    Serial.println(F("| ============================================= |"));
  #endif
  
}

void loop() {
  float dist;

   if(digitalRead(button) == LOW){
    
      digitalWrite(pinLed, HIGH);
      digitalWrite(bip, HIGH);
      delay(100);
      digitalWrite(pinLed, LOW);
      digitalWrite(bip, LOW);
      dist = sensorHCSR04.dist();
      Serial.println(dist);
      delay(1000);
   } 
     

}
