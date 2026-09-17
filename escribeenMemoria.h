    void escribeEeprom() {
      EEPROM.write(direccionInicial,a1);
      EEPROM.write(direccionInicial+1,b1);
      EEPROM.write(direccionInicial+1,c1);
      EEPROM.write(direccionInicial+1,d1);
    }

    void leeEEPROM(){
      Serial.println("---------------------------------------------------");
      for(int x=0;x<4;x++){
          Serial.println(String("El valor en la direccion ")+ x + String("es igual a-> ")+EEPROM.read(x));
        }
        Serial.println("---------------------------------------------------");
    }