#include <Keypad.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

const int RS = 7;
const int EN = 6;
const int D4 = 2;
const int D5 = 3;
const int D6 = 4;
const int D7 = 5;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

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

const int ledGreen =  A0;
const int ledRed =  A1;

SoftwareSerial softSerial(10, 11);

String done[20] = {};
String inputPass = "";
int dones = 0;

void setup(){
  
  Serial.begin(9600);
  softSerial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);

}
  
void loop(){
  
  char key = keypad.getKey();
  lcd.clear();
  
  if (key == '.'){
   
    lcd.setCursor(0, 0);
    lcd.print("Enter your ID:");

    lcd.setCursor(0,1);
    inputPass = "";
    for (int i = 0; i < 4; i++){
      key = keypad.waitForKey();
      lcd.print(key);
      inputPass += key;
    }

    int possible = 1;
    for (int i = 0; i < 20; i++){
      if (inputPass == done[i])
        possible = 0;
    }

    lcd.clear();
    lcd.setCursor(0, 0);

    if (possible){
      done[dones] = inputPass;
      dones++;

      digitalWrite(ledGreen, HIGH);
      
      lcd.print("Enter your vote:");
      key = keypad.waitForKey();
      
      lcd.setCursor(0, 1);
      lcd.print(key);

      Serial.print(inputPass);
      Serial.print(" : ");
      Serial.println(key);
      softSerial.write(key);
    
    }else{
      
      digitalWrite(ledRed, HIGH);
      lcd.print("You voted before");
    }

    delay (500);
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, LOW);
  }
}
