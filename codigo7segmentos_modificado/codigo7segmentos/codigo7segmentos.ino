#include <EEPROM.h>
#include <MatrizLed.h>

#define PIN_A 13
#define PIN_B 12
#define PIN_C 11
#define PIN_D 10
#define lectura A0

int a1;
int b1;
int c1;
int d1;

int valor = 0;      // valor obtenido de la lectura
int voltaje = 0;

int direccionInicial = 0;

MatrizLed Mipantalla;
#include "lecturabitxbit.h"
#include "escribeenMemoria.h"
#include "mensajesImpresos.h"
#include "datosAlDecoder.h"

void setup() {
  Serial.begin(9600);
  pinMode(PIN_A, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_C, OUTPUT);
  pinMode(PIN_D, OUTPUT);
  pinMode(lectura, INPUT);

  Mipantalla.begin(9, 7, 8, 1); // dataPin, clkPin, csPin, numero de matrices de 8x8
  Mipantalla.rotar(false);
}

void espera() {
  delay(1000);
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
}
