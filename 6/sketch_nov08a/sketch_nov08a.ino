#define servoPin 22
#define buzzerPin 23
#define ledPin 26
#define relePin 53

#include <Servo.h>

Servo servo;
String entered = "";
int val;


void setup(){
  
  Serial.begin(9600);
  servo.attach(servoPin);

  pinMode(servoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(relePin, OUTPUT);
}


void loop(){

 
  if (Serial.available() > 0) {

    int key = Serial.read() - 48;


    // BUZZER
    // ASCII code of 'b' is 98 
    if( key == 50){
      Serial.println("Buzzer ");
      digitalWrite(buzzerPin, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);


    // LED
    // ASCII code of 'l' is 108 
    }else if (key == 60){
    Serial.println("LED ");
    digitalWrite(ledPin, HIGH);
    delay(500);
    digitalWrite(ledPin, LOW);


    // RELE
    // ASCII code of 'r' is 101 
    }else if (key == 66){
    Serial.println("Rear ON ");
    digitalWrite(relePin, HIGH);


    // RELE
    // ASCII code of 't' is 116 
    }else if (key == 68){
    Serial.println("Rear OFF ");
    digitalWrite(relePin, LOW);


    // ASCII code of "ENTER" is 13
    }else if (key == -35){
      val = entered.toInt();

      Serial.write(' ');
      Serial.print(val);
      Serial.write(' ');
      
      servo.write(val);
      delay(20);


    // CLEAR
    // ASCII code of . is 50
    }else if (key == -2) {
      entered = "";
      Serial.write(' ');
      Serial.println("clear");


    // OTHER KEY
    }else {
      entered += key;
      Serial.print(entered);
      Serial.write(' ');
    }

  }
}
