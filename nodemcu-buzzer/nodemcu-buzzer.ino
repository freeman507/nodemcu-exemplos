void setup() {
  pinMode(D2, OUTPUT); //deixa a porta D2 como saida, essa porta é usada para o buzzer
}

void loop() {
  digitalWrite(D2, HIGH);  //faz o buzzer tocar
  delay(200);              //espera 200 milisegundos
  digitalWrite(D2, LOW);   //faz o buzzer parar de tocar
  delay(1000);             //espera 1 segundo
}
