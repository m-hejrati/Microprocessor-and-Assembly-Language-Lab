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

String num1 = "";
String num2 = "";
char operand = "";
bool flag = true;
int answer = "";


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
    lcd.print(key);
    
    if (key=='1' || key=='2' || key=='3' || key=='4' || key=='5' || key=='6' || key=='7' || key=='8' || key=='9' || key=='0'){
      if (flag)
        num1 += key;
      else
        num2 += key;
    
    } else if (key == '/' || key == '*' || key == '-' || key == '+'){
        operand = key;
        flag = false;

    } else if(key == '='){

        if (operand == '+'){
          answer = num1.toInt() + num2.toInt();
        }
        else if (operand == '-'){
          answer = num1.toInt() - num2.toInt();
        }
        else if (operand == '*'){
          answer = num1.toInt() * num2.toInt();
        }
        else if (operand == '/'){
          answer = num1.toInt() / num2.toInt();
        }  

        lcd.setCursor(0, 1);
        lcd.print(answer);
          
        num1 = "";
        num2 = "";
        operand = "";
        flag = true;
        answer = 0;
    }else if(key == '.'){
      lcd.clear();
      lcd.setCursor(0, 0);
    }
  }
}
