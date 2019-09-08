#include <SoftwareSerial.h>
#include <ESP8266WiFi.h>;
#include <WiFiClient.h>;
#include <ThingSpeak.h>;

const char* ssid = "Sampath"; //Your Network SSID
const char* password = "Sanchkhoushikh"; //Your Network Password

WiFiClient client;
 
unsigned long myChannelNumber = 860038; //Your Channel Number (Without Brackets)
const char * myWriteAPIKey = "9WXRVT8VOSJFJS2D";
 
SoftwareSerial s(D6,D5);
int data;
String Message;
String input="";
float firstVal, secondVal;


void setup() {
s.begin(9600);
Serial.begin(9600);
delay(10);

WiFi.begin(ssid, password);

ThingSpeak.begin(client);

}
 
void loop() {
  
s.write("s");
//int incomingByte; 

//while(s.available() > 0){
//    Message = s.readString();
//  }
//  Serial.println(Message);
//  Message="";


if (s.available())
{
 while (s.available()) {
    delay(2);  //delay to allow byte to arrive in input buffer
    char c = s.read();
    input += c;
  }
Serial.println(input);

for (int i = 0; i < input.length(); i++) {
  if (input.substring(i, i+1) == ",") {
    firstVal = input.substring(0, i).toFloat();
    secondVal = input.substring(i+1).toFloat();
    break;
  }
}
Serial.println(firstVal);
Serial.println(secondVal);
input="";

delay(1000);
ThingSpeak.setField(1,firstVal);
ThingSpeak.setField(2,secondVal);
//ThingSpeak.setField(3,val3);

ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
delay(100);

}

}
