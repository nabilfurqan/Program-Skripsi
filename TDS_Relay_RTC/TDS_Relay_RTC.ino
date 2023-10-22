#include <RTClib.h>
#include <Wire.h>
#include <EEPROM.h>
#include "GravityTDS.h"

#define TdsSensorPin A0
GravityTDS gravityTds;
float temperature = 25,tdsValue = 0;

RTC_DS3231 rtc;
int Relay = D1;

char t[32];

void setup() 
{
  Serial.begin(115200);
  Wire.begin(D3, D2);   //Setting wire (5 untuk SDA dan 4 untuk SCL)

  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));  //Setting Time
  
  // Kalian dapat menambahkan bagian dibawah ini untuk set manual jam
  // rtc.adjust(DateTime(2014, 1, 21, 3, 0, 0));

  pinMode(Relay, OUTPUT);

  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(1023);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();  //initialization
}

void loop()
{
  DateTime now = rtc.now();       //Menampilkan RTC pada variable now

  if(now.hour() == 17 && now.minute() == 11 ){
    digitalWrite(Relay,LOW);
    Serial.println("LIGHT ON");
  }

  else if(now.hour() == 17 && now.minute() == 19 ){
    digitalWrite(Relay,LOW);
    Serial.println("LIGHT ON");
  }

  else if(now.hour() == 18 && now.minute() == 00 ){
    digitalWrite(Relay,LOW);
    Serial.println("LIGHT ON");
  }
    
  else{
    digitalWrite(Relay,HIGH);
    Serial.println("LIGHT OFF");
  }

  Serial.print("Tanggal : ");
  Serial.print(now.day());        //Menampilkan Tanggal
  Serial.print("/");
  Serial.print(now.month());      //Menampilkan Bulan
  Serial.print("/");
  Serial.print(now.year());       //Menampilkan Tahun
  Serial.print(" ");
  
  Serial.print("Jam : ");
  Serial.print(now.hour());       //Menampilkan Jam
  Serial.print(":");
  Serial.print(now.minute());     //Menampilkan Menit
  Serial.print(":");
  Serial.print(now.second());     //Menampilkan Detik
  Serial.println();

  gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
  gravityTds.update();  //sample and calculate
  tdsValue = gravityTds.getTdsValue();  // then get the value cal:108
  Serial.print(tdsValue,0);
  Serial.println("ppm");  
  delay(1000);
}


void RTC (){

}