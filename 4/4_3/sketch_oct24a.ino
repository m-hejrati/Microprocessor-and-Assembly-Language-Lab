#include <Keypad.h>
#include <Servo.h>

int val;
Servo servo;

String entered = "";

void setup(){
  
  Serial.begin(9600);
  servo.attach(13);
}
  
void loop(){

 
  if (Serial.available() > 0) {
    
    int key = Serial.read() - 48;

    // saci code of = is 61
    if (key == 13){

      val = entered.toInt();

      Serial.write(' ');
      Serial.print(val);
      Serial.write(' ');
      
      servo.write(val);
      delay(20);

    // asci code of . is 50
    }else if (key == -2) {

      entered = "";
      Serial.write(' ');
      Serial.print("clear");
      Serial.write(' ');
    
    }else {

      entered += key;
      Serial.write(' ');
      Serial.print(entered);
      Serial.write(' ');
    }

  }
}
