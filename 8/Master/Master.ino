#include <SPI.h>

#define Sensor A1
#define Resistor A0

const int SS1 = 45, SS2 = 46;
byte resistorBytes[2], sensorBytes[2];
int sensorInput, resistorInput;
int mode = 1;

void setup(){
  Serial3.begin(9600);
  pinMode(SS1, OUTPUT);
  pinMode(SS2, OUTPUT);
  digitalWrite(SS1, HIGH);
  digitalWrite(SS2, HIGH);
  SPI.begin();
  SPI.setClockDivider(SPI_CLOCK_DIV8);
}

void loop(){
  if(mode == 1){
    
    resistorInput = analogRead(Resistor);
    sensorInput = analogRead(Sensor);
    sensorInput = map(sensorInput, 0, 308, 0, 150);
    //resistorInput = map(resistorInput, 0, 1023, 0, 5);
    //resistorInput = ((500 / resistorInput) - 100);
    Serial3.print("Sensor = ");
    Serial3.println(sensorInput);
    Serial3.print("Resistor = ");
    Serial3.println(resistorInput);
    resistorBytes[0] = resistorInput;
    resistorBytes[1] = resistorInput >> 8;
    sensorBytes[0] = sensorInput;
    sensorBytes[1] = sensorInput >> 8;
    
    digitalWrite(SS1, LOW);
    delay(10);
    for (int i = 0 ; i < 2 ; i++){
      SPI.transfer(resistorBytes[i]);
    }
    delay(10);
    digitalWrite(SS1, HIGH);
    
    delay(500);
    
    digitalWrite(SS2, LOW);
    delay(10);
    for (int i = 0 ; i < 2 ; i++){
      SPI.transfer(sensorBytes[i]);
    }
    delay(10);
    digitalWrite(SS2, HIGH);
    
    delay(200);
    
   }else if(mode == 2){
    
    digitalWrite(SS1, LOW);
    delay(10);
    byte b[] = {'H', 'e', 'l', 'l', 'o'};
    for(int i = 0 ; i < 5 ; i++){
      SPI.transfer(b[i]);
    }
    delay(10);
    digitalWrite(SS1, HIGH);

    delay(500);

    digitalWrite(SS2, LOW);
    delay(10);
    byte d[] = {'H', 'e', 'l', 'l', 'o'};
    for(int i = 0 ; i < 5 ; i++){
      SPI.transfer(d[i]);
    }
    delay(10);
    digitalWrite(SS2, HIGH);
    
    delay(500);
   }
  
}
