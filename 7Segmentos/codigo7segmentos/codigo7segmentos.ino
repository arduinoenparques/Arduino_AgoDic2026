#define a 13
#define b 12
#define c 11
#define d 10
#define e 9
#define f 8
#define g 7

#define lectura A0

int valor=0;      //valor obtenido de la lectura

void setup() {

  Serial.begin(9600);

  pinMode(a,OUTPUT);
  pinMode(b,OUTPUT);
  pinMode(c,OUTPUT);
  pinMode(d,OUTPUT);
  pinMode(e,OUTPUT);
  pinMode(f,OUTPUT);
  pinMode(g,OUTPUT);

  pinMode(lectura,INPUT);
}

void espera()
{
  delay(1000);
}

void loop() {

  digitalWrite(a,HIGH);
  digitalWrite(b,LOW);
  digitalWrite(c,LOW);
  digitalWrite(d,HIGH);
  digitalWrite(e,HIGH);
  digitalWrite(f,HIGH);
  digitalWrite(g,HIGH);

  espera();

  valor=analogRead(lectura);
 
  Serial.println(valor)

}
