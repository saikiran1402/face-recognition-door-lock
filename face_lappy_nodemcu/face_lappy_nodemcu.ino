#define BLYNK_TEMPLATE_ID "TMPL3ce0CBeFQ"
#define BLYNK_TEMPLATE_NAME "Face recognition based Door Lock IOT"


#include <Wire.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define BLYNK_AUTH_TOKEN "d7snkIGr3jDzWJVOhE4_9PzUIAyE0u-U"
char auth[] = "d7snkIGr3jDzWJVOhE4_9PzUIAyE0u-U";

char ssid[] = "FACE";  // Enter your wifi name
char pass[] = "123456789";  // Enter your wifi password

int datafromUser=0;
int lock = D4;
int green = D5;
int red = D6;
int buzz = D7;
int ir = A0;


void setup() {

  pinMode(red,OUTPUT);
  pinMode(lock,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(ir,INPUT);
  
  pinMode(buzz,OUTPUT);
  // put your setup code here, to run once:
  Serial.begin(9600);
Blynk.begin(auth, ssid, pass);

  
}

void loop() {

  int ir = analogRead(A0);
  if(ir < 500)
  {
     Serial.println(" lock OFF");
      analogWrite(lock,255);
         analogWrite(buzz,0);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
      Blynk.email("veshalanarendar870@gmail.com", "Alert", "Unknown Person is Detected! Lock is locked!!");
    Blynk.logEvent("uk_alert","Unknown Person is Detected! Lock is locked!!!");
   delay(5000);
       analogWrite(lock,255);
         analogWrite(buzz,0);
     digitalWrite(red,HIGH);
       digitalWrite(green,LOW); 
   

  }
  else {
    Serial.println("Lock OFF");
    analogWrite(lock,0);
         analogWrite(buzz,0);
     digitalWrite(red,HIGH);
       digitalWrite(green,LOW); 

  }

  
  
  Blynk.run();
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0)
  {
    datafromUser=Serial.read();
  }
  
  if(datafromUser == '2')
  {
    
    Serial.print("unknown person"); // You can make spaces using well... spaces
      analogWrite(lock,0);
     analogWrite(buzz,255);
      digitalWrite(red,HIGH);
       digitalWrite(green,LOW); 
       Blynk.email("veshalanarendar870@gmail.com", "Alert", "Unknown Person is Detected! Lock is locked!!");
    Blynk.logEvent("uk_alert","Unknown Person is Detected! Lock is locked!!!");
   
        delay(3000);
    analogWrite(lock,0);
         analogWrite(buzz,0);
     digitalWrite(red,LOW);
       digitalWrite(green,HIGH); 
    
  }
  else if(datafromUser == '1')
  {
   
    Serial.print("Known Person"); // You can make spaces using well... spaces
     analogWrite(lock,255);
     analogWrite(buzz,200);
      digitalWrite(red,0);
       digitalWrite(green,HIGH); 
    Blynk.email("veshalanarendar870@gmail.com", "Alert", "Known Person is Detected! Lock is Unlocked!!");
    Blynk.logEvent("k_alert","Known Person is Detected! Lock is Unlocked!!");
   
    delay(10000);
    analogWrite(lock,0);
         analogWrite(buzz,0);
     digitalWrite(red,HIGH);
       digitalWrite(green,LOW); 
    
  }

  else
  {
  
    analogWrite(lock,0);
         analogWrite(buzz,0);
     digitalWrite(red,HIGH);
       digitalWrite(green,LOW); 
    
  }
 
  }


  

BLYNK_WRITE(V0) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println(" lock ON");
      analogWrite(lock,255);
         analogWrite(buzz,200);
    digitalWrite(red,LOW);
    digitalWrite(green,HIGH);
   

  }
  else {
    Serial.println("Lock OFF");
    analogWrite(lock,0);
         analogWrite(buzz,0);
     digitalWrite(red,HIGH);
       digitalWrite(green,LOW); 

  }
}
  
