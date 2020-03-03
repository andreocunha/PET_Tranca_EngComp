//-------------------------------------------------------------------------------------------------------------------------
//Biblioteca e parametros do sensor biometrico

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //pinos de leitura do sensor biometrico

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

//-------------------------------------------------------------------------------------------------------------------------
//RFID (Leitor de cartao)

#include <Wire.h> //INCLUSÃO DA BIBLIOTECA NECESSÁRIA
#include <SPI.h> //INCLUSÃO DE BIBLIOTECA
#include <MFRC522.h> //INCLUSÃO DE BIBLIOTECA

#define SS_PIN 10 //PINO SDA
#define RST_PIN 9 //PINO DE RESET

MFRC522 rfid(SS_PIN, RST_PIN); //PASSAGEM DE PARÂMETROS REFERENTE AOS PINOS

//-------------------------------------------------------------------------------------------------------------------------
//bibliotecas e definicoes para o display OLED


#include "SSD1306Ascii.h"
#include "SSD1306AsciiAvrI2c.h"

// 0X3C+SA0 - 0x3C or 0x3D
#define I2C_ADDRESS 0x3C

// Define proper RST_PIN2 if required.
#define RST_PIN2 -1

SSD1306AsciiAvrI2c oled;


//-------------------------------------------------------------------------------------------------------------------------
//variaveis

const int pinoLedVerde = 6; //PINO DIGITAL REFERENTE AO LED VERDE
const int pinoLedVermelho = 5; //PINO DIGITAL REFERENTE AO LED VERMELHO
#define trancaRele 7 //pino utilizado para acionar o rele
int ID; //para saber o ID do usuario cadastrado


//-------------------------------------------------------------------------------------------------------------------------
// setup do programa
void setup() {
  Serial.begin(9600); //inicia o monitor serial do arduino, com taxa de 9600


  finger.begin(57600); // defina a taxa de dados para a porta serial do sensor biometrico
  
  if (finger.verifyPassword()) {
    Serial.println(F("Sensor biometrico encontrado!"));
  } else {
    Serial.println(F("NAO foi possivel encontrar o sensor biometrico."));
    while (1) { delay(1); }
  }


  Wire.begin(); //INICIALIZA A BIBLIOTECA WIRE
  SPI.begin(); //INICIALIZA O BARRAMENTO SPI
  rfid.PCD_Init(); //INICIALIZA MFRC522
  
  pinMode(pinoLedVerde, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(pinoLedVermelho, OUTPUT); //DEFINE O PINO COMO SAÍDA
  pinMode(trancaRele, OUTPUT); //DEFINE O PINO COMO SAÍDA
  
  digitalWrite(pinoLedVerde, LOW); //LED INICIA DESLIGADO
  digitalWrite(pinoLedVermelho, LOW); //LED INICIA DESLIGADO
  

  //-------------------------------------------------------------------------------------------------------------------------
//definicoes inciais para o display OLED


#if RST_PIN2 >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS, RST_PIN2);
#else // RST_PIN2 >= 0
  oled.begin(&Adafruit128x32, I2C_ADDRESS);
#endif // RST_PIN2 >= 0
  // Call oled.setI2cClock(frequency) to change from the default frequency.

  oled.setFont(Adafruit5x7);
  
  oled.clear();

//-------------------------------------------------------------------------------------------------------------------------

  
}

void loop(){
  
  ID = leituraBiometrica(); //funcao para ler a biometria e retornar o ID da pessoa
  if(ID != -1){
    nomeDoUsuario(ID);
  }
  leituraRfid(); //CHAMA A FUNÇÃO RESPONSÁVEL PELA VALIDAÇÃO DA TAG RFID
}
