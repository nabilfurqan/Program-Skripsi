int ph;
float Value;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}
 void loop(){
 
    ph = analogRead(A0);

    Value=ph*(3.3/1023.0);

    Serial.println(Value);

    delay(3000);
 }