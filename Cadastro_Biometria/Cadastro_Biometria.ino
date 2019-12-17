//-------------------------------------------------------------------------------------------------------------------------
//Biblioteca e parametros do sensor biometrico

#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); //pinos de leitura do sensor biometrico

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);


//-------------------------------------------------------------------------------------------------------------------------
//variaveis

int numMenu;

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

}

void loop(){
    Serial.println();
    Serial.println(F("MENU:"));
    Serial.println();
    Serial.println(F("Digite 1 para cadastrar nova digital"));
    Serial.println(F("Digite 2 para remover uma digital"));
    Serial.println(F("Digite 3 para ver as digitais cadastradas"));

    numMenu = readnumber(); // Armazena caractere lido
    Serial.println();

  
    if(numMenu == 1){
      cadastraDigital();
    }

    else if(numMenu == 2){
      apagaDigital();
    }

    else if(numMenu == 3){
      mostraDigitais();
    }

}
