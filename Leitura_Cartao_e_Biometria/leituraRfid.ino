//FUNÇÃO DE VALIDAÇÃO DA TAG RFID
void leituraRfid(){
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) //VERIFICA SE O CARTÃO PRESENTE NO LEITOR É DIFERENTE DO ÚLTIMO CARTÃO LIDO. CASO NÃO SEJA, FAZ
    return; //RETORNA PARA LER NOVAMENTE

  /***INICIO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/
  String strID = ""; 
  for (byte i = 0; i < 4; i++) {
    strID +=
    (rfid.uid.uidByte[i] < 0x10 ? "0" : "") +
    String(rfid.uid.uidByte[i], HEX) +
    (i!=3 ? ":" : "");
  }
  strID.toUpperCase();
/***FIM DO BLOCO DE CÓDIGO RESPONSÁVEL POR GERAR A TAG RFID LIDA***/

//-----------------------------------------------------------------------------------------------------------------------------
//Codigos dos cartões RFID
  if (strID.indexOf("00:00:00:00") >= 0){ 
    permitido();
  }
  else if(strID.indexOf("00:00:00:00") >= 0 ){
    permitido(); 
  }


  else if (strID.indexOf("00:00:00:00") >= 0){
      permitido();
  }

  
  else if (strID.indexOf("00:00:00:00") >= 0){ 
      permitido();
  }

  else if (strID.indexOf("00:00:00:00") >= 0){
    permitido();
  }
  else{ //SENÃO, FAZ (CASO A TAG LIDA NÃO SEJÁ VÁLIDA)
    negado();
  }

//-----------------------------------------------------------------------------------------------------------------------------


  rfid.PICC_HaltA(); //PARADA DA LEITURA DO CARTÃO
  rfid.PCD_StopCrypto1(); //PARADA DA CRIPTOGRAFIA NO PCD
  }

  void permitido(){
    digitalWrite(pinoLedVerde, HIGH); //LIGA O LED VERDE
    oled.clear();
    oled.println("");
    oled.set2X();
    oled.println("AUTORIZADO!"); 
    digitalWrite(trancaRele, HIGH);
    delay(250); //INTERVALO DE 2 SEGUNDOS
    digitalWrite(trancaRele, LOW);
    delay(750);
    digitalWrite(pinoLedVerde, LOW); //DESLIGA O LED VERDE
    oled.clear();
  }

  void negado(){
    digitalWrite(pinoLedVermelho, HIGH); //LIGA O LED VERMELHO
    oled.clear();
    oled.println("");
    oled.set2X();
    oled.println("NEGADO!"); 
    delay(2000); //INTERVALO DE 2 SEGUNDOS
    oled.clear();
    digitalWrite(pinoLedVermelho, LOW); //DESLIGA O LED VERMELHO
  }
