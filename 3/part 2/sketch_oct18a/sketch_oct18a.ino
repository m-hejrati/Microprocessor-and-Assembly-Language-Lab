#include <LiquidCrystal.h>
#include <Keypad.h>

const int RS = 13;
const int EN = 12;
const int D4 = 8;
const int D5 = 9;
const int D6 = 10;
const int D7 = 11;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'7','8','9','/'},
  {'4','5','6','*'},
  {'1','2','3','-'},
  {'.','0','=','+'}
};
byte rowPins[ROWS] = {31, 33, 35, 37}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {23, 25, 27, 29}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

String savedPass = "1234";
String enteredPass = "";

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Mahdi Hejrati ");
  lcd.setCursor(0, 1);
  lcd.print("    9723100    ");
  delay(1000);
  lcd.clear();
}

void loop() {
  
  char key = keypad.getKey();
  
  if (key){
    if (key == '*'){
      
      if (savedPass == enteredPass){
          lcd.setCursor(0, 1);
          lcd.print("Correct Password");
          enteredPass = "";
      } else{
          lcd.setCursor(0, 1);
          lcd.print("Wrong Password");
          enteredPass = "";
      }

    }else if (key == '='){
      enteredPass = "";
      lcd.clear();
      
    }else{
      lcd.print(key);
      enteredPass += key;
    
    } 
  }
}
