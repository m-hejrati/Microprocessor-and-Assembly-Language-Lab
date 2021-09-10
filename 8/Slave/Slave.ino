#include <SPI.h>

#define input 51

byte buffer1[5];
byte index = 0;
boolean complete = false;
int number;
int mode = 1;

void setup(){
  Serial3.begin (9600);
  pinMode(input, INPUT_PULLUP);
  SPCR |= _BV(SPE);
  SPCR |= _BV(SPIE);
  SPI.attachInterrupt();
}


void loop(){
  if(mode == 1){
    if (complete){
      complete = false;
      number = buffer1[0] + (buffer1[1] << 8);
      Serial3.println(number);
      index = 0;
    }
  }else if(mode == 2){
    if(complete){
      complete = false;
      for(int i = 0 ; i < 5 ; i++){
        char c = buffer1[i];
        Serial3.print(c);
      }
      Serial3.println("");
      index = 0;
    }
  }
  
}


ISR(SPI_STC_vect){
  byte b = SPDR;
  if(mode == 1){
    if(index < 2){
      buffer1[index++] = b;
      if (index == 2)
        complete = true;
    }
  }else if(mode == 2){
    buffer1[index] = b;
    index++;
    if(index == 5)
      complete = true;
  }
}
