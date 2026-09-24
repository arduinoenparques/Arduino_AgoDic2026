void escribeEeprom() {
  EEPROM.update(direccionInicial,     a1);
  EEPROM.update(direccionInicial + 1, b1);
  EEPROM.update(direccionInicial + 2, c1);
  EEPROM.update(direccionInicial + 3, d1);
}

void leeEEPROM() {
  Serial.println("---------------------------------------------------");
  for (int x = 0; x < 4; x++) {
    Serial.println(String("El valor en la direccion ") + x + String(" es igual a -> ") + EEPROM.read(direccionInicial + x));
  }
  Serial.println("---------------------------------------------------");
}
