void apagaDigital(){
  //funcao para apagar uma digital cadastrada


    Serial.println("Digite um numero de 1 a 127 para deletar o ID da digital");
  
    uint8_t id = readnumber();
    if (id == 0) {// ID #0 not allowed, try again!
      return;
    }

    Serial.print(F("Deletando ID #"));
    Serial.print(id);
    Serial.println(F("..."));
    deleteFingerprint(id);

}

  uint8_t deleteFingerprint(uint8_t id) {
  uint8_t p = -1;
  
  p = finger.deleteModel(id);

  if (p == FINGERPRINT_OK) {
    Serial.println(F("DELETADO!"));
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println(F("Erro de comunicacao"));
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println(F("Nao foi possivel deletar nessa localizacao"));
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println(F("Error writing to flash"));
    return p;
  } else {
    Serial.print(F("Erro desconhecido: 0x")); Serial.println(p, HEX);
    return p;
  }   
}
