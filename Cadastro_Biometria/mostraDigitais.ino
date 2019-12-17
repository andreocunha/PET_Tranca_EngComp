//funcao que mostra na tela todos as digitais cadastradas

void mostraDigitais(){
  
//funcao para mostrar as digitais ja cadastradas

  uint8_t p;
  uint8_t id = 0;
  
  for(int i = 0; i<128; i++, id++){

    p = finger.loadModel(id);
    
    if (p == FINGERPRINT_OK) {
      Serial.print(F("Digital com ID #"));
      Serial.print(id);
      Serial.println(F(" cadastrado"));
    }
  }
}
