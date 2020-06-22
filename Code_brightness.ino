const float A = 1000;     //Darkness resistance in KΩ
const float B = 5;        //Light resistance (10 Lux) in KΩ
const float Rc = 0.22;       //Calibration resistance in KΩ
const int LDRPin = A0;   //LDR's pin
 
float V;
float ilum;
 
void setup() 
{
   Serial.begin(9600);
}
 
void loop()
{
   V = analogRead(LDRPin);         
 
   ilum = ((long)(1024-V)*A*10)/((long)B*Rc*V);  //Use in case LDR is between GND and A0 (lower part of the divider)
  // ilum = (V*A*10)/(B*Rc*(1023-V));    //Use if LDR is between A0 and Vcc (upper part of the divider)
  
   Serial.println(ilum);   
   delay(1000);
}

/*double Light (int RawADC0)
{
  double Vout=RawADC0*0.0048875855;
  //int lux=500/(10*((5-Vout)/Vout));//use this equation if the LDR is in the upper part of the divider
  int lux=(2500/Vout-500)/10;
  //double ldr = (Vout*10000)/(5-Vout);
  //double lux = (-ldr*1000010)/(99.991);
  return lux;
}
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  Serial.print("Light Intensity:");
  Serial.print(double(Light(analogRead(0))));
  Serial.println(" Lux");
  delay(1000);
}*/
