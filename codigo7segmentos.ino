#include <EEPROM.h>

#define a 13
#define b 12
#define c 11
#define d 10

#define lectura A0


int a1;
int b1;
int c1;
int d1;

int valor=0;      //valor obtenido de la lectura
int voltaje=0;

int direccionInicial=0;

void setup() {

  Serial.begin(9600);
  EEPROM.begin();
  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
 
  pinMode(lectura,INPUT);
}

void espera()
{
  delay(1000);
}

void loop() {

  
  espera();

  valor=analogRead(lectura);// valor del ADC
  voltaje=valor*5/1023;
  a1=bitRead(voltaje,0);
  b1=bitRead(voltaje,1);
  c1=bitRead(voltaje,2);
  d1=bitRead(voltaje,3);

  
    EEPROM.write(direccionInicial,a1);
    EEPROM.write(direccionInicial+1,b1);
    EEPROM.write(direccionInicial+1,c1);
    EEPROM.write(direccionInicial+1,d1);
  
  
   Serial.println(voltaje,BIN);
 
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input A del decoder= ") + a1);  
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input B del decoder= ") + b1);  
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input C del decoder= ") + c1);  
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input D del decoder= ") + d1);
  
  Serial.println("---------------------------------------------------");
  espera();
  digitalWrite(a,a1);
  digitalWrite(b,b1);
  digitalWrite(c,c1);
  digitalWrite(d,d1);

Serial.println("---------------------------------------------------");
  for(int x=0;x<4;x++){
    Serial.println(String("El valor en la direccion ")+ x + String("es igual a-> ")+EEPROM.read(x));
    }
  Serial.println("---------------------------------------------------");
  espera();
}
