#include <Arduino.h>
int value = 0;
void setup() {
  pinMode(4 , OUTPUT);
  pinMode(A0, INPUT);

  // Clear interrupts
  cli();

  // Using time counter 1 
  TCCR1A = 0 ;
  TCCR1B = 0 ;
  TCNT1 = 0 ; // Starts from zero

  // CTC mode and prescaler value of 1/8
  TCCR1B |= (1<<WGM12) | (1<<CS11);

  // Output compare match Enable 
  TIMSK1 |= (1<<OCIE1A) ;

  // OCR1 
  OCR1A = 6553;

  // Set interrupts
  sei();
}

ISR(TIMER1_COMPA_vect){
  // code 
  // switch pin 4 that created a pwm with .1<dc<0.9
  OCR1A = value;
}

void loop() {
  // 10000 is some random number that works 
  // i initially was using 65536 bc its 2^16-1 
  // and we have this many bits but it didnt work 
  // but it workts perfectly fine with 10000
  value = map(analogRead(A0), 0,1023 ,10000*0.1, 10000*0.9);
  digitalWrite(4 , 1);
  delayMicroseconds(value);
  digitalWrite(4,0);
  delayMicroseconds(10000 - value);
}