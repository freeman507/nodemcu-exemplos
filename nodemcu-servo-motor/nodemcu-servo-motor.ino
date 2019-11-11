#include <Servo.h>  //biblioteca necessaria para usar o servo motor
 
Servo meuservo;  // objeto necessario que faz o controle do servo motor
 
int pos = 0;    // variável que armazena a posição do servo motor
 
void setup() {
  meuservo.attach(D4);  // passa o pino do servo motor para o objeto que controla o servo motor
}
 
void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // movimento de 0 a 180º
    meuservo.write(pos);                // escreve posicao em meuservo
    delay(35);                          // aguarda 35ms
  }
  for (pos = 180; pos >= 0; pos -= 1) { // movimento de 180º a 0
    meuservo.write(pos);                // escreve posicao em meuservo
    delay(35);                          // aguarda 35ms
  }
}
