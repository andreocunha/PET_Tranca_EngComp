void nomeDoUsuario(int ID){
     digitalWrite(pinoLedVerde, HIGH);
     Serial.print(F("ID encontrado #")); Serial.println(ID); 

      oled.clear();
      oled.println("");
      oled.set2X();
   

     if(ID == 0 || ID == 1){
      Serial.println(F("Andre"));
      oled.println("Andre Cunha");
     }

     else if(ID == 2 || ID == 3){
      Serial.println(F("Marco"));
      oled.println("Marco");
     }

     else if(ID == 4 || ID == 5){
      Serial.println(F("Victor"));
      oled.println("Victor");
     }

     else if(ID == 6 || ID == 7){
      Serial.println(F("Caio"));
      oled.println("Caio");
     }

     else if(ID == 8 || ID == 9){
      Serial.println(F("Mirelly"));
      oled.println("Mirelly");
     }

  else if(ID == 10 || ID == 11){
      Serial.println(F("Henrique"));
      oled.println("Henrique");
     }

     else if(ID == 12 || ID == 13){
      Serial.println(F("Elias"));
      oled.println("Elias");
     }

     else if(ID == 14 || ID == 15){
      Serial.println(F("Joao"));
      oled.println("Joao");
     }

     else if(ID == 16 || ID == 17){
      Serial.println(F("Luiz"));
      oled.println("Luiz");
     }

     else if(ID == 18 || ID == 19){
      Serial.println(F("Heitor"));
      oled.println("Heitor");
     }

     else if(ID == 20){
      Serial.println(F("Jorge"));
      oled.println("Jorge");
     }

     else if(ID == 21 || ID == 22){
      Serial.println(F("Lucca"));
      oled.println("Lucca");
     }

     else if(ID == 23 || ID == 24){
      Serial.println(F("MJ"));
      oled.println("MJ");
     }

     else if(ID == 25 || ID == 26){
      Serial.println(F("Otto"));
      oled.println("Otto");
     }

     else if(ID == 27 || ID == 28){
      Serial.println(F("Patricia"));
      oled.println("Patricia");
     }

     else if(ID == 29 || ID == 30){
      Serial.println(F("Joana"));
      oled.println("Joana");
     }

/*
 * Esses IDs estao vazios, podem ser usados para cadastro
 * 
     else if(ID == 31 || ID == 32){
      Serial.println(F("Quem eh?"));
      oled.println("Quem eh?");
     }
*/

     else if(ID == 33 || ID == 34){
      Serial.println(F("JM"));
      oled.println("JM");
     }

     else if(ID == 35 || ID == 36){
      Serial.println(F("Roberta"));
      oled.println("Roberta");
     }

      digitalWrite(trancaRele, HIGH);
      delay(250);
      digitalWrite(trancaRele, LOW);
      delay(750);  
      oled.clear();
      oled.println("");
      oled.println("Bem vindo!");
      delay(1000); //INTERVALO DE 2 SEGUNDOS    
      oled.clear();
      digitalWrite(pinoLedVerde, LOW);
}
