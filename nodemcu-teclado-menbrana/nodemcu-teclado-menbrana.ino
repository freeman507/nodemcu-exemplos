#include "Keypad.h" //biblioteca necessaria para fazer leitura do teclado

const byte linhas = 4;   //numero de linhas do teclado
const byte colunas = 4;  //numero de colunas do teclado

// mapeamento das teclas do teclado de acordo com linha e coluna
char Teclas [linhas][colunas] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte pinosLinhas[linhas] = {D0,D1,D2,D3};   //pinos usados para leitura de linha
byte pinosColunas[colunas] = {D4,D5,D6,D7}; //pinos usados para leitura de colunas

Keypad teclado = Keypad(makeKeymap(Teclas),pinosLinhas, pinosColunas, linhas,colunas);  //inicia o objeto responsavel pela leitura do teclado

void setup() {
  Serial.begin(115200);  // inicia a porta serial para mostrar mensagens no computador
}

//Funcao que retorna a tecla que esta precionada
char verificaTeclaPressionada() {
  return teclado.getKey();
}

void loop() {
  char teclaClicada = verificaTeclaPressionada(); // pega a tecla pressionada
  if(teclaClicada) {                              // verifica se alguma tecla esta pressionada
    Serial.println(teclaClicada);                 // mostra no computador a tecla pressionada
  }
}
