#include <OneWire.h>

#include <DallasTemperature.h>

OneWire oneWire(D2);
DallasTemperature sensors(&oneWire);

void setup() {
  // put your setup code here, to run once:
sensors.begin();
Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  sensors.requestTemperatures();
  float currentTemp;
  currentTemp = sensors.getTempCByIndex(0);
  Serial.print("Temperature = ");
  Serial.println(currentTemp,2);
  
  delay(1000);
}