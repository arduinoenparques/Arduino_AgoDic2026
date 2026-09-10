#define a 13
#define b 12
#define c 11
#define d 10
//#define e 9
//#define f 8
//#define g 7

#define lectura A0


int a1=1;
int b1=2;
int c1=3;
int d1=8;

int valor=0;      //valor obtenido de la lectura
int voltaje=0;

void setup() {

  Serial.begin(9600);

  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  //pinMode(e,OUTPUT);
  //pinMode(f,OUTPUT);
  //pinMode(g,OUTPUT);

  pinMode(lectura,INPUT);
}

void espera()
{
  delay(1000);
}

void loop() {

  /*digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);*/

  espera();

  valor=analogRead(lectura);// valor del ADC
   //Serial.println(valor);
   voltaje=valor*5/1024;

   Serial.println(voltaje,BIN);
  a1=(voltaje >>0)  ;
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input A del decoder= ") + a1);
  b1=(voltaje >>1)  ;
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input B del decoder= ") + b1);
  c1=(voltaje >>2)  ;
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input C del decoder= ") + c1);
  d1=(voltaje >>3)  ;
  Serial.println(String("valor en voltimetro ") + voltaje + String(" Input D del decoder= ") + d1);
  //Serial.println(voltaje);
  Serial.println("---------------------------------------------------");
  espera();
  digitalWrite(a,a1);
  digitalWrite(b,b1);
  digitalWrite(c,c1);
  digitalWrite(d,d1);

}
