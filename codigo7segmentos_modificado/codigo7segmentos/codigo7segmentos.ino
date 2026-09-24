#include <EEPROM.h>
#include <MatrizLed.h>
#include <LiquidCrystal.h>


LiquidCrystal MiLCD (A1,A2,6,5,4,3);     //rs,enable,D4,D5,D6,D7

#define PIN_A 13
#define PIN_B 12
#define PIN_C 11
#define PIN_D 10
#define lectura A0

int a1;
int b1;
int c1;
int d1;

float valor = 0;      // valor obtenido de la lectura
int voltaje = 0;
float voltajecompleto;

int direccionInicial = 0;

MatrizLed Mipantalla;
#include "lecturabitxbit.h"
#include "escribeenMemoria.h"
#include "mensajesImpresos.h"
#include "datosAlDecoder.h"
#include "usandoLCD.h"

void setup() {
  Serial.begin(9600);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(lectura, INPUT);

  Mipantalla.begin(9, 7, 8, 1); // dataPin, clkPin, csPin, numero de matrices de 8x8
  Mipantalla.rotar(false);
  MiLCD.begin(16,2);
  
}

void espera() {
  delay(500);
}

void loop() {
  espera();
  lecturabitxbit();
  escribeEeprom();
  Serial.println(voltaje, BIN);
  imprimeLecturas();
  espera();
  decoder();
  leeEEPROM();
  espera();
  char convertir [8];
  itoa(voltaje,convertir,10);   
  Mipantalla.borrar();
  Mipantalla.escribirFraseScroll(convertir,250);
  imprimeLCD();
}
