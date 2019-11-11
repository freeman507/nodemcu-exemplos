#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h> 

const char* ssid     = "TERTULIA"; // nome da conexao WiFi
const char* password = "giovana4"; // senha do WiFi

void connectaWifi() {
  Serial.println("Conectando no WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi conectado com sucesso!");  
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());  
}

String httpGetRequest(String url) {
  String retorno = "";
  if (WiFi.status() == WL_CONNECTED) {     //Verifica a conexao do WiFi
    HTTPClient http;                       //Declara um objeto do tipo HTTP para fazer o request 
    http.begin(url);                       //Especifica o endereco para fazer o request
    int httpCode = http.GET();             //Envia o request para API
    if (httpCode > 0) {                    //Checa o retorno da API, se maior que 0 o request teve sucesso!
      retorno = http.getString();          //Pega a resposta da API      
    } else {
      Serial.println("sem retorno");       //Imprime mensagem de request sem sucesso
    }
    http.end();                            //Fecha conexao
  }  
  return retorno;
}

void setup() {
  Serial.begin(115200);  //Inicializa a porta serial para exibir mensagens no computador
  connectaWifi();  // Conecta o Wifi
}

void loop() {
  String resposta = httpGetRequest("http://10.0.0.109:8080/"); //Faz a requisição para a API e retorna a resposta
  Serial.println(resposta);
}
