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

  if (strID.indexOf("32:80:CD:F2") >= 0){ //Andre
    permitido();
  }
  else if(strID.indexOf("01:02:03:04") >= 0 ){//Andre
    permitido(); 
  }


  else if (strID.indexOf("04:1B:3D:33") >= 0){//Caio
      permitido();
  }

  
  else if (strID.indexOf("86:4A:DC:B0") >= 0){ //Otto
      permitido();
  }

  else if (strID.indexOf("36:84:CC:3B") >= 0){ //Rodrigo Laiola
    permitido();
  }
  
  else if (strID.indexOf("BE:9A:32:61") >= 0){ //Cartao 1
    permitido();
  }

  else if (strID.indexOf("1E:1B:2A:61") >= 0){ //Cartao 2
    permitido();
  }

  else if (strID.indexOf("6E:C3:37:61") >= 0){ //Cartao 3
    permitido();
  }

  else if (strID.indexOf("DE:11:39:61") >= 0){ //Cartao 4
    permitido();
  }

  else if (strID.indexOf("2E:16:3D:61") >= 0){ //Cartao 5
    permitido();
  }

  else if (strID.indexOf("1E:62:3C:61") >= 0){ //Cartao 6
    permitido();
  }

  else if (strID.indexOf("7E:04:34:61") >= 0){ //Cartao 7
    permitido();
  }

  else if (strID.indexOf("6E:43:3D:61") >= 0){ //Cartao 8
    permitido();
  }

  else if (strID.indexOf("5E:5E:3C:61") >= 0){ //Cartao 9
    permitido();
  }

  else if (strID.indexOf("8E:1D:3D:61") >= 0){ //Cartao 10
    permitido();
  }

  else if (strID.indexOf("CE:E8:3A:61") >= 0){ //Cartao 11
    permitido();
  }

  else if (strID.indexOf("AE:D4:34:61") >= 0){ //Cartao 12
    permitido();
  }

  else if (strID.indexOf("1E:67:2E:61") >= 0){ //Cartao 13
    permitido();
  }

  else if (strID.indexOf("FE:E1:32:61") >= 0){ //Cartao 14
    permitido();
  }

  else if (strID.indexOf("8E:C2:3B:61") >= 0){ //Cartao 15
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
