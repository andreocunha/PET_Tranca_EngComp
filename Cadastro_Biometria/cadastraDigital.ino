//funcao para cadastrar uma digital

void cadastraDigital(){
  
    Serial.println(F("Digite um numero de 1 a 127 para salvar o ID da digital"));
    uint8_t IDgravar = readnumber();

    
  int p = -1;
  Serial.print(F("Esperando uma leitura válida para gravar #")); Serial.println(IDgravar);
  delay(2000);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println(F("Leitura concluída"));
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(F("."));
      delay(200);
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println(F("Erro comunicação"));
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println(F("Erro de leitura"));
      break;
    default:
      Serial.println(F("Erro desconhecido"));
      break;
    }
  }

  // OK successo!

  p = finger.image2Tz(1);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println(F("Leitura convertida"));
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println(F("Leitura suja"));
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println(F("Erro de comunicação"));
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println(F("Não foi possível encontrar propriedade da digital"));
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println(F("Não foi possível encontrar propriedade da digital"));
      return p;
    default:
      Serial.println(F("Erro desconhecido"));
      return p;
  }
  
  Serial.println(F("Remova o dedo"));
  delay(2000);
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print(F("ID ")); Serial.println(IDgravar);
  p = -1;
  Serial.println(F("Coloque o Mesmo dedo novamente"));
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println(F("Leitura concluída"));
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      delay(200);
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println(F("Erro de comunicação"));
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println(F("Erro de Leitura"));
      break;
    default:
      Serial.println(F("Erro desconhecido"));
      break;
    }
  }

  // OK successo!

  p = finger.image2Tz(2);
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println(F("Leitura convertida"));
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println(F("Leitura suja"));
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println(F("Erro de comunicação"));
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println(F("Não foi possível encontrar as propriedades da digital"));
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println(F("Não foi possível encontrar as propriedades da digital"));
      return p;
    default:
      Serial.println(F("Erro desconhecido"));
      return p;
  }
  
  // OK convertido!
  Serial.print(F("Criando modelo para #"));  Serial.println(IDgravar);
  
  p = finger.createModel();
  if (p == FINGERPRINT_OK) {
    Serial.println(F("As digitais batem!"));
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println(F("Erro de comunicação"));
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println(F("As digitais não batem"));
    return p;
  } else {
    Serial.println(F("Erro desconhecido"));
    return p;
  }   
  
  Serial.print(F("ID ")); Serial.println(IDgravar);
  p = finger.storeModel(IDgravar);
  if (p == FINGERPRINT_OK) {
    Serial.println(F("Armazenado!"));
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println(F("Erro de comunicação"));
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println(F("Não foi possível gravar neste local da memória"));
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println(F("Erro durante escrita na memória flash"));
    return p;
  } else {
    Serial.println(F("Erro desconhecido"));
    return p;
  }  


}
