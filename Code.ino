#include <SPI.h>

byte addresspot1 = B00010000;   
byte addresspot0 = B00000000;
int CS= 10;
int aux = 0;
const int analogPin = A5;
const int analogPin1 = A4;
float voltage;
float current;

void setup()
{
Serial.begin(9600);
pinMode (CS, OUTPUT);
Serial.println("CLEARSHEET");
Serial.println("LABEL,Date,Time,Timer,Voltage,Current");
SPI.begin();

}

void loop()
{
  delay(6500);
  Serial.println("BEEP");
for (int i = 0; i <= 256; i++)
{
  int j=256-i;
  digitalPot1(i);
  digitalPot0(j);
  aux++;
  if (aux%10 != 0){delay(10);}
  if (aux%10 == 0){
    for (int i = 0; i <= 5; i++){
      int cur = analogRead(analogPin1);
      int vol = analogRead(analogPin);
      voltage =conversionvoltage(vol);
      current = conversioncurrent(cur);
      Serial.print( (String) "DATA,DATE,TIME,TIMER," );
      Serial.print(voltage);
      Serial.print(",");
      Serial.println(current);
      delay(1000);}
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
    for (int i = 0; i <= 5; i++){
      int cur = analogRead(analogPin1);
      int vol = analogRead(analogPin);
      voltage =conversionvoltage(vol);
      current = conversioncurrent(cur);
      Serial.print( (String) "DATA,DATE,TIME,TIMER," );
      Serial.print(voltage);
      Serial.print(",");
      Serial.println(current);
      delay(1000);}
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

float conversionvoltage(float x){
  return (5*x/1023);
}

float conversioncurrent(float x){
  int volts = (5*x/1023);
  int currentmA = (10*volts/0.265);
  return (currentmA);
}
