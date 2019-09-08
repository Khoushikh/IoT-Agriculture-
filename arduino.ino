#include <DHT.h>
#include<SoftwareSerial.h>
void writeString(String stringData);

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht ( DHTPIN,DHTTYPE );
SoftwareSerial s(5,6); 


const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;
String h;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication

s.begin(9600);
dht.begin ( ) ;
}


void loop() {

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");

float humidity = dht.readHumidity ();
float temp = dht.readTemperature ();
//  Serial.print("temperature=");
Serial.print(distance);
Serial.print(" \t");
Serial.println(temp);
String a = String(temp);
String b = String(distance);
String c=String(",");
//String d= String("\0");

String h = a+c+b;
Serial.println(h);
writeString(h);
delay(10000);
}

void writeString(String stringData) { // Used to serially push out a String with Serial.write()

  for (int i = 0; i < stringData.length(); i++)
  {
//    Serial.println(stringData[i]);
    s.write(stringData[i]);   // Push each char 1 by 1 on each loop pass
  }

}// end writeString
