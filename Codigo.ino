#include <SPI.h>

byte addresspot1 = B00010000;
byte addresspot0 = B00000000;
int CS= 10;
int aux = 0;
const int analogPin = A5;
float value;

void setup()
{
Serial.begin(9600);
pinMode (CS, OUTPUT);
Serial.println("CLEARSHEET");
Serial.println("LABEL,Fecha,Hora,Cronometro,ValorPin");
SPI.begin();
}

void loop()
{
for (int i = 0; i <= 256; i++)
{
  int j=256-i;
  digitalPot1(i);
  digitalPot0(j);
  aux++;
  if (aux%10 != 0){delay(10);}
  if (aux%10 == 0){
    delay(2000);
    int val = analogRead(analogPin);
    value =conversion(val);
    Serial.println( (String) "DATA,DATE,TIME,TIMER," + value + ",AUTOSCROLL_20" );
    }
  if (aux >= 256){
    aux = 0;}
}
delay(2000);
for (int i = 256; i >= 0; i--)
{
  int j= 256-i;
  digitalPot1(i);
  digitalPot0(j);
  aux++;
  if (aux%10 != 0){delay(10);}
  if (aux%10 == 0){
    delay(2000);
    int val = analogRead(analogPin);
    value =conversion(val);
    Serial.println( (String) "DATA,DATE,TIME,TIMER," + value + ",AUTOSCROLL_20" );
    }
  if (aux >= 256){
    aux = 0;}
}
}

int digitalPot1(int valuepot1)
{
  digitalWrite(CS, LOW);
  SPI.transfer(addresspot1);
  SPI.transfer(valuepot1);
  digitalWrite(CS, HIGH);
}

int digitalPot0(int valuepot0)
{
  digitalWrite(CS, LOW);
  SPI.transfer(addresspot0);
  SPI.transfer(valuepot0);
  digitalWrite(CS, HIGH);
}

float conversion(float x){
  return (5*x/1023);
}
