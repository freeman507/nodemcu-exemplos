#include <SPI.h>      //biblioteca necessaria para usar o sensor de RFID
#include <MFRC522.h>  //biblioteca necessaria para usar o sensor de RFID

constexpr uint8_t RST_PIN = D1;     // pino RST usado para leitura do cartao
constexpr uint8_t SS_PIN = D2;      // pino SDA usado para leitura do cartao
 
MFRC522 rfid(SS_PIN, RST_PIN); // Objeto para usar o sensor de RFID

MFRC522::MIFARE_Key key; 

// Init array that will store new NUID 
byte nuidPICC[4];

void setup() { 
  Serial.begin(115200);
  SPI.begin();     // Init SPI bus
  rfid.PCD_Init(); // Init MFRC522 
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {
  Serial.println(lerRFID(true));
  delay(1000);
}
 
String lerRFID(boolean hex) {
  
  // Vefifica cartao novo
  if ( ! rfid.PICC_IsNewCardPresent()) {
    return "";
  }

  // Verifica se o NUID foi lido
  if ( ! rfid.PICC_ReadCardSerial()) {
    return "";
  }

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  Serial.println(rfid.PICC_GetTypeName(piccType));

  // verifica se o PICC é do tipo classico MIFARE
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println("ERRO: Formato invalido do cartao");
    return "";
  }

  String retorno;

  if (rfid.uid.uidByte[0] != nuidPICC[0] || 
    rfid.uid.uidByte[1] != nuidPICC[1] || 
    rfid.uid.uidByte[2] != nuidPICC[2] || 
    rfid.uid.uidByte[3] != nuidPICC[3] ) {
    Serial.println("Novo cartao detectado");

    // Guarda o NUID dentro do nuidPICC array
    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
   
    if (hex) {
      retorno = converteHexadecimal(rfid.uid.uidByte, rfid.uid.size);
    } else {
      retorno = converteDecimal(rfid.uid.uidByte, rfid.uid.size); 
    }
  }
  else {
    Serial.println("Cartao repetido");
    retorno = "";
  }

  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();

  return retorno;
}


//retorna o RFID em hexadecimal
String converteHexadecimal(byte *buffer, byte bufferSize) {
  String content;
  for (byte i = 0; i < bufferSize; i++) {
    content = content + String(buffer[i] < 0x10 ? " 0" : " ");
    content = content + String(buffer[i], DEC);
  }
  return content;
}

//retorna o RFID em decimal
String converteDecimal(byte *buffer, byte bufferSize) {
  String content;
  for (byte i = 0; i < bufferSize; i++) {
    content = content + String(buffer[i] < 0x10 ? " 0" : " ");
    content = content + String(buffer[i], DEC);
  }
  return content;
}
