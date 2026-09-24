void imprimeLCD(){
   /*MiLCD.clear();
  MiLCD.print(String("La lectura es: "));
  MiLCD.setCursor(1,8);
  MiLCD.print(voltajecompleto + String(" V"));
*/
MiLCD.setCursor(0,0);
  MiLCD.createChar(2, Pacman1);
  MiLCD.write(byte(2));
}