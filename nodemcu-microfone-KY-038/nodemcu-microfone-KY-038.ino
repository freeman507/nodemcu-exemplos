void setup(){
  Serial.begin(115200);
  pinMode(D0, INPUT); //DEFINE O PINO COMO ENTRADA
}

void loop(){
  if (digitalRead(D0) == HIGH){ //SE A LEITURA DO PINO FOR IGUAL A HIGH, FAZ
    Serial.println("teste");  
    delay(1000);
  }
}
