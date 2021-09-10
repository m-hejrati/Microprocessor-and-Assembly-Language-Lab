#include <Keypad.h>
#include <Servo.h>


const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'.','0','=','+'}
};
byte rowPins[ROWS] = {37, 38, 39, 40}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {41, 42, 43, 44}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );


int val;
Servo servo;

String entered = "";

void setup(){
  
  Serial.begin(9600);
  servo.attach(13);
}
  
void loop(){

  char key = keypad.getKey();
  
  if (key){
    if (key == '='){

      val = entered.toInt();
      
      Serial.print(val);
      Serial.write(' ');
      
      servo.write(val);
      delay(20);

    }else if (key == '.') {

      entered = "";
    
    }else {

      entered += key;
      Serial.print(entered);
      Serial.write(' ');
    }

  }
}
