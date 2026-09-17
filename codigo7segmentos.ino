#include <EEPROM.h>
#include "lecturabitxbit.h"
#include "escribeenMemoria.h"
#include "mensajesimpresos.h"
#include "datosAlDecoder.h"

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
    lecturabitxbit();        
    escribeenMemoria();     
    Serial.println(voltaje,BIN); 
    imprimeLecturas();
    espera();
    decoder();
    leeEEPROM();
    espera();
}
