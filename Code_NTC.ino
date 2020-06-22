void getTemp(float * t){

    // Converts input from a thermistor voltage divider to a temperature value.
    // The voltage divider consists of thermistor Rt and series resistor R0.
    // The value of R0 is equal to the thermistor resistance at T0.
    // You must set the following constants:
    //                  adcMax  ( ADC full range value )
    //                  analogPin (Arduino analog input pin)
    //                  invBeta  (inverse of the thermistor Beta value supplied by manufacturer).
    // Use Arduino's default reference voltage (5V or 3.3V) with this module.
    //

  const int analogPin = A2; 
  const float invBeta = 1.00 / 3997.00;  

  const  float adcMax = 1023.00;
  const float invT0 = 1.00 / 298.15;   // room temp in Kelvin

  int i, numSamples = 5;
  float  K, C, F,  adcVal;

  adcVal = 0;
  for (i = 0; i < numSamples; i++)
   {
     adcVal = adcVal + analogRead(analogPin);
     delay(100);
   }
  adcVal = adcVal/5;
  K = 1.00 / (invT0 + invBeta*(log ( adcMax / (float) adcVal - 1.00)));
  C = K - 273.15;                      // convert to Celsius
  F = ((9.0*C)/5.00) + 32.00;   // convert to Fahrenheit
  t[0] = K; t[1] = C; t[2] = F; 
    //adcVal = adcVal*5/1023;
  //t[2] =   adcVal;
  return;
}

void setup()
{
  analogReference(DEFAULT);
  Serial.begin(9600);
}

void loop()
{
  float temp[3];
  getTemp(temp);    
 int   adcVal;
 
  Serial.print("Temperature is     ");
  Serial.print(temp[1]); 
  Serial.print(" deg. C      ");
  Serial.print("Voltage      "); 
  Serial.print(temp[2]);
  Serial.println();
  delay(1000);
  return;
}
