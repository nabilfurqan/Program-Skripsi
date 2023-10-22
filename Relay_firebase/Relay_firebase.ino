#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <EEPROM.h>
#include "GravityTDS.h"

// Set these to run example.
#define FIREBASE_HOST "hidroponik-b9c78-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "ZEw1nDnI6RfvDa6YRs0TK2CZS4kKiM5B22DQ2cUC"
#define WIFI_SSID "WiFi saya"
#define WIFI_PASSWORD "Qwerty123"

#define TdsSensorPin A0
GravityTDS gravityTds;
float temperature = 25,tdsValue = 0;


void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Serial.begin(115200);
  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(3.3);  //reference voltage on ADC, default 5.0V on Arduino UNO
  gravityTds.setAdcRange(1023);  //1024 for 10bit ADC;4096 for 12bit ADC
  gravityTds.begin();  //initialization
  pinMode (D1, OUTPUT);
}

int n = 0;

void loop() {
  int val = Firebase.getInt("relay");
  Serial.print("Relay: ");
  Serial.println(val);
  digitalWrite(D1, val);

  gravityTds.setTemperature(temperature);  // set the temperature and execute temperature compensation
  gravityTds.update();  //sample and calculate
  tdsValue = gravityTds.getTdsValue();  // then get the value cal:108
  Serial.print(tdsValue,0);
  Serial.println("ppm");
  Firebase.setInt("ppm", tdsValue);
  delay(1000);
}