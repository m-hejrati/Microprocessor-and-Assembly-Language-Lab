#include<Keypad.h>
#include<LiquidCrystal.h>
#include<Servo.h>

// LCD
const int rs = 22, en = 23, d4 = 24, d5 = 25, d6 = 26, d7 = 27;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// Keypad
const byte Rows = 4, Cols = 4;
char keys[Rows][Cols] =
{ 
  {'7', '8', '9', '/'},
  {'4', '5', '6', 'x'},
  {'1', '2', '3', '-'},
  {'*', '0', '=', '+'}
};
const byte rowPins[Rows] = {46, 47, 48, 49};
const byte colPins[Cols] = {50, 51, 52, 53};
Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, Rows, Cols);

//Servo
Servo servo;
const int servoPin = 7;

// Buzzer
const int buzzerPin = 13;

// LEDs
const int led1Pin = 14; // close led (red)
const int led2Pin = 21; // open led (green)

// password
String pass = "0000"; 
String inputPass;

//closing timer
int timer = 5;
bool isOpen = false;
bool autoClose = false;
char key;
unsigned long startTime = 0;


// get 4 digit as password
void getpass(){
  lcd.setCursor(0,1);
  inputPass = "";
  for (int i = 0; i < 4; i++){
    key = keypad.waitForKey();
    lcd.print(key);
    inputPass += key;
  }
}


// open gav sandohgh
void open(){
  servo.write(180);
  tone(buzzerPin, 1000, 200);
  isOpen = true;   
  autoClose = true;
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, HIGH);
  startTime = millis();
  wait();
}


// wait when gav sandogh is open
void wait(){
  while(isOpen){
    lcd.clear();
    lcd.print(timer-(millis()-startTime)/1000.0);
    delay(10);
    char key = keypad.getKey();
    if (key)
      if (key == '*') 
        close();
    if (millis()- startTime > timer*1000 && autoClose)
      close();
  }
}


// close gav sandogh
void close(){
  tone(buzzerPin, 1000, 200);
  servo.write(0);
  isOpen = false;
  autoClose = false; 
  digitalWrite(led1Pin, HIGH);
  digitalWrite(led2Pin, LOW);
}


void setup() {
  
  servo.attach(servoPin);
  servo.write(0);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led1Pin, HIGH);
  lcd.begin(16,2);
  pinMode(servoPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
}


void loop() {
  
  lcd.clear();
  lcd.print("Main Menu");
  
  key = keypad.getKey();
  if(key)
    
    // change timer time
    if(key == '-'){
        lcd.clear();
        lcd.print("Enter new time:");
        lcd.setCursor(0,1);
        key = keypad.waitForKey();
        timer = key - 48;
        lcd.print(key);
        delay(500);
        lcd.clear();
        lcd.print("Timer changed to");
        lcd.setCursor(0,1);
        lcd.print(key);
        delay(500);

    // change password
    }else if(key == '+'){
      lcd.clear();
      lcd.print("Enter new pass:");
      getpass();
      pass = inputPass;
      lcd.clear();
      lcd.print("Pass changed to");
      lcd.setCursor(0,1);
      lcd.print(pass);
      delay(500);
    
    // open gav sandogh     
    }else if(key == '='){
      lcd.clear();
      lcd.print("Enter pass:");
      getpass();
      lcd.clear();
      if( pass == inputPass ){
        open();
      }else{
        lcd.print("Wrong pass");
        delay(500);
      }
    }
    
  delay(200);
}
