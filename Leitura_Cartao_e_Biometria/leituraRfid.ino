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

  if (strID.indexOf("32:80:CD:F2") >= 0){
    permitido();
  }
  else if(strID.indexOf("01:02:03:04") >= 0 ){//Andre
    permitido(); 
  }

  else if (strID.indexOf("09:7D:81:98") >= 0){
      permitido();
  }

  else if (strID.indexOf("37:C0:D1:4B") >= 0){
      permitido();
  }

  else if (strID.indexOf("04:1B:3D:33") >= 0){//Caio
      permitido();
  }

  else if (strID.indexOf("E1:E8:FF:6A") >= 0){ //Marco
      permitido();
  }

  else if (strID.indexOf("15:EA:24:AC") >= 0){ //Humberto
      permitido();
  }

  else if (strID.indexOf("41:E3:08:43") >= 0){ //Victor
      permitido();
  }

  else if (strID.indexOf("25:B4:FC:07") >= 0){ //Victor
      permitido();
  }

  else if (strID.indexOf("11:E2:70:E0") >= 0){ //Elias
      permitido();
  }

  else if (strID.indexOf("08:2C:58:3A") >= 0){ //Joao
      permitido();
  }

  else if (strID.indexOf("75:92:D5:4B") >= 0){ //Luiz
      permitido();
  }

  else if (strID.indexOf("86:4A:DC:B0") >= 0){ //Otto
      permitido();
  }

  else if (strID.indexOf("29:18:D1:B1") >= 0){ //Lucca
      permitido();
  }

  else if (strID.indexOf("36:84:CC:3B") >= 0){ //Rodrigo Laiola
    permitido();
  }

  else if (strID.indexOf("31:0D:41:2E") >= 0){ //Joana
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
  /*  oled.clear();
    oled.println("");
    oled.set2X();
    oled.println("AUTORIZADO!"); */
    digitalWrite(trancaRele, HIGH);
    delay(250); //INTERVALO DE 2 SEGUNDOS
    digitalWrite(trancaRele, LOW);
    delay(750);
    digitalWrite(pinoLedVerde, LOW); //DESLIGA O LED VERDE
    //oled.clear();
  }

  void negado(){
    digitalWrite(pinoLedVermelho, HIGH); //LIGA O LED VERMELHO
 /*   oled.clear();
    oled.println("");
    oled.set2X();
    oled.println("NEGADO!"); */
    delay(2000); //INTERVALO DE 2 SEGUNDOS
  //  oled.clear();
    digitalWrite(pinoLedVermelho, LOW); //DESLIGA O LED VERMELHO
  }
