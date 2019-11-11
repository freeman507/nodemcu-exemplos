#include <Ultrasonic.h>  //biblioteca para usar o ultrasson

Ultrasonic ultrassom(D0, D1); //inicializa o sensor usando as portas digitais 1 e 2 (D0 = trig, D1 = echo)

long distanciaUltrasson() {
  return ultrassom.Ranging(CM); //captura a distancia em centimetros
}

void setup() {
  Serial.begin(115200); //Inicializa porta serial para mostrar mensagens no computador
}

void loop() {
  Serial.println(distanciaUltrasson()); //imprime a distancia
}
