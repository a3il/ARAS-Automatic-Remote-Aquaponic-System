/*
  DS3231: Real-Time Clock. Simple example
  Read more: www.jarzebski.pl/arduino/komponenty/zegar-czasu-rzeczywistego-rtc-ds3231.html
  GIT: https://github.com/jarzebski/Arduino-DS3231
  Web: http://www.jarzebski.pl
  (c) 2014 by Korneliusz Jarzebski
*/

#include <Wire.h>
#include <DS3231.h>
int t;
DS3231 clock;
RTCDateTime dt;

void setup()
{
  Serial.begin(9600);
pinMode(8,OUTPUT);
pinMode(9,OUTPUT);
digitalWrite(8,LOW);
digitalWrite(9,HIGH);
  // Initialize DS3231
  Serial.println("Initialize DS3231");;
  clock.begin();

  
  clock.setDateTime(__DATE__, __TIME__);
}

void loop()
{
  dt = clock.getDateTime();

  // For leading zero look to DS3231_dateformat example

  //Serial.print("Raw data: ");
  //Serial.print(dt.year);   Serial.print("-");
  //Serial.print(dt.month);  Serial.print("-");
 // Serial.print(dt.day);    Serial.print(" ");
 // Serial.print(dt.hour);   Serial.print(":");
  Serial.print(dt.minute); Serial.print(":");
  //Serial.print(dt.second); Serial.println("");

  delay(1000);
// t=dt.hour;
  if(dt.hour>=6 && dt.hour<=19){
  digitalWrite(8,LOW);}
  else
  {
    digitalWrite(8,HIGH);
  }
 
 
}
