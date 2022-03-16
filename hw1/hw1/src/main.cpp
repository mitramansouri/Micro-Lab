#include <Arduino.h>

int adc_val = 0;

bool led1_state = false;
bool led2_state = false;
bool led3_state = false;
bool led4_state = false;

void setup() {
  pinMode(A0, INPUT);//ADC INPUT
  pinMode(A1, OUTPUT);//ADC OUTPUT
  pinMode(A2, OUTPUT);//ADC OUTPUT
  pinMode(A3, OUTPUT);//ADC OUTPUT
  pinMode(A4, OUTPUT);//ADC OUTPUT
}

void loop() {
  // put your main code here, to run repeatedly:
  adc_val = analogRead(A0);//Read from analog 
  int val = map(adc_val, 0, 1023, 0, 100);//2^10-1 = 1023
  if (val>= 0 && val< 25){ // 0-25 --> no LED 
    led1_state = false;
    led2_state = false;
    led3_state = false;
    led4_state = false;
  }
  else if(val>= 25 && val< 50){ // 25-50 --> one LED
    led1_state = true;
    led2_state = false;
    led3_state = false;
    led4_state = false;
  }
  else if(val>= 50 && val< 75){ // 50-75 --> two LEDs
    led1_state = true;
    led2_state = true;
    led3_state = false;
    led4_state = false;
  }
  else if(val>= 75 && val< 90){ // 75-90 --> three LEDs
    led1_state = true;
    led2_state = true;
    led3_state = true;
    led4_state = false;
  }
  else if(val>= 90){ // 90-100 --> All LEDs
    led1_state = true;
    led2_state = true;
    led3_state = true;
    led4_state = true;
  }
  digitalWrite(A1, led1_state);
  digitalWrite(A2, led2_state);
  digitalWrite(A3, led3_state);
  digitalWrite(A4, led4_state);
}