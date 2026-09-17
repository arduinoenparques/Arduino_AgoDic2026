#define led 13

void setup() {
  pinMode(led,OUTPUT);  //Declaracion de salida para la variable 13
}

void espera()
{
  delay (1000);
}
void loop() {
  espera();
  digitalWirte(led,LOW);
  espera();
  digitalWirte(led,HIGH);
}
