#include <ESP8266WiFi.h>

const char* ssid = "WiFi saya";       // Nama SSID AP/Hotspot
const char* password = "Qwerty123";       // Password Wifi

void setup() {
  Serial.begin(115200);
  delay(10);

// Connect to WiFi network ------------------------------------------------
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

// Mengatur WiFi ----------------------------------------------------------
  WiFi.mode(WIFI_STA);                      // Mode Station
  WiFi.begin(ssid, password);               // Mencocokan SSID dan Password
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

// Print status Connect ---------------------------------------------------
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
 
}