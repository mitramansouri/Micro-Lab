#include <Arduino.h>

int dac_value = 0 ;
void setup() {
  // put your setup code here, to run once:
  // pin mode 
  // A0 to potentiometer
  pinMode(A1, INPUT);
  // Pin ~3 to DAC /MOSFET
  pinMode(3, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // adc_value = analogRead(A0); // reads value in 10 bit from potentiometer
  // adc_value >>= 2 ; //stores in 8 bit 
  // digitalWrite(3, adc_value); // writes to MOSFET
  // dac_value = map(analogRead(A1), 0 , 1023, 0, 8000 );
  // digitalWrite(3, 1);
  // delayMicroseconds(dac_value);
  // digitalWrite(3, 0);
  // delayMicroseconds((8000 - dac_value));
  dac_value = analogRead(A1); //10 bit thing 
  dac_value >>=2 ; //stores in 8 bit 
  digitalWrite(3, 1);
  delayMicroseconds(dac_value*100);
  digitalWrite(3,0);
  delayMicroseconds((255-dac_value)*100);
}