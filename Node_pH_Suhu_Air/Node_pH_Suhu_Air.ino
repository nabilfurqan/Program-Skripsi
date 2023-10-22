#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(D2);
DallasTemperature sensors(&oneWire);
const int potPin=A0;
float ph;
float Value=10;
 
void setup() {
  // put your setup code here, to run once:
  sensors.begin();
  Serial.begin(115200);
  pinMode(potPin,INPUT);
  delay(1000);
}
 void loop(){
 
    Value= analogRead(potPin);
    Serial.print(Value);
    Serial.print(" | ");
    float voltage=Value*(3.3/4095.0);
    ph=(3.3*voltage);
    Serial.println(ph);
    sensors.requestTemperatures();
    float currentTemp;
    currentTemp = sensors.getTempCByIndex(0);
    Serial.print("Temperature = ");
    Serial.println(currentTemp,2);
    delay(2000);
 }