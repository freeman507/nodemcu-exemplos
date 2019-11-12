void setup() {
  Serial.begin(115200); //Inicia a comunicação serial
}
 
void loop() {
  Serial.println(analogRead(A0));
  delay(100);
}
