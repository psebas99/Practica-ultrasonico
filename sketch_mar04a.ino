#include <HCSR04.h>

#include <LiquidCrystal.h>
#define peligro  47 
#define cuidado 48
#define alejese 49
#define nitido 50

const int Trigger = 6;   //Pin digital 2 para el Trigger del sensor
const int Echo = 7;   //Pin digital 3 para el Echo del sensor
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);//iniciailzamos la comunicación
  pinMode(Trigger, OUTPUT); //pin como salida
  pinMode(Echo, INPUT);  //pin como entrada
  digitalWrite(Trigger, LOW);//Inicializamos el pin con 0
  lcd.begin(16, 2);
  pinMode(peligro, OUTPUT);
  pinMode(cuidado, OUTPUT);
  pinMode(alejese, OUTPUT);
  pinMode(nitido, OUTPUT);
}

void loop()
{
  long t; //timepo que demora en llegar el eco
  long d; //distancia en centimetros

  digitalWrite(Trigger, HIGH);
  delayMicroseconds(10);          //Enviamos un pulso de 10us
  digitalWrite(Trigger, LOW);

  t = pulseIn(Echo, HIGH); //obtenemos el ancho del pulso
  d = t / 59;           //escalamos el tiempo a una distancia en cm

  lcd.setCursor(0, 1);
  lcd.print("Distancia:");
  lcd.print(d);
  lcd.print(" cm");
    digitalWrite(peligro, LOW);
    digitalWrite(cuidado, LOW);
    digitalWrite(alejese, LOW);
    digitalWrite(nitido, LOW);

  if ( 20 <= d && d < 25) {
    digitalWrite(peligro, HIGH);
  }
if ( 15 <= d && d< 20)
{
  digitalWrite(cuidado, HIGH);
}
if ( 10 <= d && d < 15)
{
  digitalWrite(alejese, HIGH);
}
if (d< 10) {
  digitalWrite(nitido, HIGH);
}
delay(100);          //Hacemos una pausa de 100ms
}
