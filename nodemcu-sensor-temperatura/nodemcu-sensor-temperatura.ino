#include <OneWire.h> //biblioteca necessaria para usar a biblioteca DallasTemeperature
#include <DallasTemperature.h> // biblioteca para ler os dados do sensor

OneWire ourWire(D6); // Cria um objeto OneWire e passa a porta D6 que está conectada no sensor
DallasTemperature sensors(&ourWire); // passa o objeto OneWire como parametro para criar o objeto DallasTemperature

//procedimento que inicializa o sensor de temperatura
void iniciarSensorTemperatura() {
  sensors.begin(); // inicializa o sensor de temperatura atraves do objeto DallasTemperature
}

//função que retorna a temperatura em celcius do sensor
double capturaTemperatura() {
  sensors.requestTemperatures(); //captura a temperatura
  return sensors.getTempCByIndex(0); //retorna a temperatura
}

void setup() {
  Serial.begin(115200); //inicializa a porta serial para poder exibir mensagens no computador
  iniciarSensorTemperatura(); //inicializa o sensor
}

void loop() {
  Serial.println(capturaTemperatura()); // chama a função que captura a temperatura e mostra a temperatura no computador
}
