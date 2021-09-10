#define DEV_ADDRESS 0b1010000

#include <SoftwareSerial.h>
#include <Wire.h>
SoftwareSerial softSerial(10, 11);

char c;
int point;
int totalA = 0;
int totalB = 0;
int totalC = 0;
int totalD = 0;

const int buzzerPin = 8;

void setup(){
  
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  softSerial.begin(9600);
  pinMode(buzzerPin, OUTPUT);
  Wire.begin();
  save();

}


void loop(){
  
  if (Serial.available()){
    load();

    tone(buzzerPin, 1000, 200);
    c = Serial.read();
    softSerial.print("A: ");
    softSerial.println(c);
    totalA += (c - 48);
    char buffer[60];
    sprintf(buffer, "Total: A: %d, B: %d, C: %d, D: %d", totalA, totalB, totalC, totalD);
    softSerial.println(buffer);
    save();
  }

  if (Serial1.available()){
    load();

    tone(buzzerPin, 1000, 200);
    c = Serial1.read();
    softSerial.print("B: ");
    softSerial.println(c);
    totalB += (c - 48);
    char buffer[60];
    sprintf(buffer, "Total: A: %d, B: %d, C: %d, D: %d", totalA, totalB, totalC, totalD);  
    softSerial.println(buffer);
    save();
}
  
  if (Serial2.available()){
    load();
   
    tone(buzzerPin, 1000, 200);   
    c = Serial2.read();
    softSerial.print("C: ");
    softSerial.println(c);
    totalC += (c - 48);
    char buffer[60];
    sprintf(buffer, "Total: A: %d, B: %d, C: %d, D: %d", totalA, totalB, totalC, totalD);
    softSerial.println(buffer); 
    save();
  }
  
  if (Serial3.available()){
    load();
    
    tone(buzzerPin, 1000, 200);
    c = Serial3.read();
    softSerial.print("D: ");
    softSerial.println(c);
    totalD += (c - 48);
    char buffer[60];
    sprintf(buffer, "Total: A: %d, B: %d, C: %d, D: %d", totalA, totalB, totalC, totalD);  
    softSerial.println(buffer);  
    save();
  }  
}


void save() {
  Wire.beginTransmission(DEV_ADDRESS);
  Wire.write(0x00);
  Wire.write(0xAA);
  Wire.write(totalA);
  Wire.write(totalB);
  Wire.write(totalC);
  Wire.write(totalD);
  Wire.endTransmission();
}

void load() {
  uint8_t point;
  Wire.beginTransmission(DEV_ADDRESS);
  Wire.write(0x00);
  Wire.write(0xAA);
  Wire.endTransmission();
  Wire.requestFrom(DEV_ADDRESS, 4);
  point = Wire.read();
  totalA = point;
  point = Wire.read();
  totalB = point;
  point = Wire.read();
  totalC = point;
  point = Wire.read();
  totalD = point;
}
