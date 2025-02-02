#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "webpages.h"

/* Put your SSID & Password */
const char* ssid = "NodeMCU";  // Enter SSID here
const char* password = "12345678";  //Enter Password here

/* Put IP Address details */
IPAddress local_ip(192,168,1,1);
IPAddress gateway(192,168,1,1);
IPAddress subnet(255,255,255,0);

ESP8266WebServer server(80);

uint8_t LED0pin = D0;
bool LED0status = LOW;

uint8_t LED1pin = D1;
bool LED1status = LOW;


uint8_t LED2pin = D2;
bool LED2status = LOW;

uint8_t LED3pin = D3;
bool LED3status = LOW;


uint8_t LED4pin = D4;
bool LED4status = LOW;

uint8_t OPT1pin = D5;
bool OPT1status = LOW;
bool OPT1statuspv = LOW;

uint8_t OPT2pin = D6;
bool OPT2status = LOW;
bool OPT2statuspv = LOW;

uint8_t OPT3pin = D7;
bool OPT3status = LOW;
bool OPT3statuspv = LOW;

uint8_t OPT4pin = D8;
bool OPT4status = LOW;
bool OPT4statuspv = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED0pin, OUTPUT);
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);
  pinMode(OPT1pin, INPUT);
  pinMode(OPT2pin, INPUT);
  pinMode(OPT3pin, INPUT);
  pinMode(OPT4pin, INPUT);



  WiFi.softAP(ssid, password);
  WiFi.softAPConfig(local_ip, gateway, subnet);
  delay(100);
  
  server.on("/", handle_OnConnect);
  server.on("/led0on", handle_led0on);
  server.on("/led0off", handle_led0off);
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);
  server.on("/led2on", handle_led2on);
  server.on("/led2off", handle_led2off);
  server.on("/led3on", handle_led3on);
  server.on("/led3off", handle_led3off);
  server.on("/led4on", handle_led4on);
  server.on("/led4off", handle_led4off);
  server.on("/help",handle_help);
  server.onNotFound(handle_NotFound);
  
  server.begin();
  Serial.println("HTTP server started");
}
void loop() {
  server.handleClient();
  if(LED0status)
  {digitalWrite(LED0pin, HIGH);}
  else
  {digitalWrite(LED0pin, LOW);}
  
  if(LED1status)
  {digitalWrite(LED1pin, HIGH);}
  else
  {digitalWrite(LED1pin, LOW);}
  
  if(LED2status)
  {digitalWrite(LED2pin, HIGH);}
  else
  {digitalWrite(LED2pin, LOW);}

  if(LED3status)
  {digitalWrite(LED3pin, HIGH);}
  else
  {digitalWrite(LED3pin, LOW);}

  if(LED4status)
  {digitalWrite(LED4pin, HIGH);}
  else
  {digitalWrite(LED4pin, LOW);}

// Inputs
   OPT1_Handler();
   OPT2_Handler();
   OPT3_Handler();
   OPT4_Handler();
}

void handle_OnConnect() {
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}
void handle_help() {
  server.send(200, "text/html", SendHTML2()); 
}

void handle_led0on() {
  LED0status = HIGH;
  Serial.println("D0 Status: ON");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led0off() {
  LED0status = LOW;
  Serial.println("D0 Status: OFF");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led1on() {
  LED1status = HIGH;
  Serial.println("D1 Status: ON");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led1off() {
  LED1status = LOW;
  Serial.println("D1 Status: OFF");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led2on() {
  LED2status = HIGH;
  Serial.println("D2 Status: ON");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led2off() {
  LED2status = LOW;
  Serial.println("D2 Status: OFF");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led3on() {
  LED3status = HIGH;
  Serial.println("D3 Status: ON");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led3off() {
  LED3status = LOW;
  Serial.println("D3 Status: OFF");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led4on() {
  LED4status = HIGH;
  Serial.println("D4 Status(ON BOARD LED): OFF");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void handle_led4off() {
  LED4status = LOW;
  Serial.println("D4 Status(ON BOARD LED): ON");
  server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status)); 
}

void OPT1_Handler()
{
 OPT1status = digitalRead(OPT1pin);
 if(OPT1status != OPT1statuspv)
 {
    OPT1statuspv = OPT1status;
    Serial.print("OPT1 Status Changed to: ");
    Serial.print(OPT1status);
    server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status));
 }
 
}

void OPT2_Handler()
{
 OPT2status = digitalRead(OPT2pin);
 if(OPT2status != OPT2statuspv)
 {
    OPT2statuspv = OPT2status;
    Serial.print("OPT2 Status Changed to: ");
    Serial.print(OPT2status);
    server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status));
 }
}

void OPT3_Handler()
{
 OPT3status = digitalRead(OPT3pin);
 if(OPT3status != OPT3statuspv)
 {
    OPT3statuspv = OPT3status;
    Serial.print("OPT3 Status Changed to: ");
    Serial.print(OPT3status);
    server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status));
 }
 
}

void OPT4_Handler()
{
 OPT4status = digitalRead(OPT4pin);
 if(OPT4status != OPT4statuspv)
 {
    OPT4statuspv = OPT4status;
    Serial.print("OPT4 Status Changed to: ");
    Serial.print(OPT4status);
    server.send(200, "text/html", SendHTML(LED0status,LED1status,LED2status,LED3status,LED4status,OPT1status,OPT2status,OPT3status,OPT4status));
 }
 
}

void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}
