void setup() {
  pinMode(D3, OUTPUT); //Deixa o pino do led verde em modo de saida
  pinMode(D4, OUTPUT); //Deixa o pino do led amarelo em modo de saida
  pinMode(D5, OUTPUT); //Deixa o pino do led vermelho em modo de saida
}

void loop() {
  digitalWrite(D3, HIGH); // liga o led verde
  delay(1000);            // espera 1 segundo
  digitalWrite(D4, HIGH); // liga o led amarelo
  delay(1000);            // espera 1 segundo
  digitalWrite(D5, HIGH); // liga o led vermelho
  delay(1000);            // espera 1 segundo
  digitalWrite(D3, LOW);  // desliga o led verde
  digitalWrite(D4, LOW);  // desliga o led amarelo
  digitalWrite(D5, LOW);  // desliga o led vermelho
  delay(1000);
}
