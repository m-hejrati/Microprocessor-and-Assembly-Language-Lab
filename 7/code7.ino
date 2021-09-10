#include <LiquidCrystal.h>
#include <Keypad.h>
#include <Wire.h>

#define DEV_ADDRESS 0b1010000
#define LED1 29
#define LED2 30
#define LED3 31
#define LED4 32

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

int currentMode = 1;
int defaultMode = 1;

int pishTime = 50;
int shooyandeTime = 50;
int abTime = 50;
int khoskTime = 50;

char key;

void setup(){
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.clear();
  Wire.begin();
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(LED3,OUTPUT);
  pinMode(LED4,OUTPUT);
  
  currentMode = loadData();
  if((currentMode != 1) || (currentMode != 2) || (currentMode != 3) || (currentMode != 4))
    currentMode = 1;
  defaultMode = currentMode;
}
 
void loop(){
  int timer = 0;
  int stageTime = 0;
  int ledON = 0;
  
  if(currentMode == 1){
    stageTime = pishTime;
    ledON = LED1;
  }else if(currentMode == 2){
    stageTime = shooyandeTime;
    ledON = LED2;
  }else if(currentMode == 3){
    stageTime = abTime;
    ledON = LED3;
  }else if(currentMode == 4){
    stageTime = khoskTime;
    ledON = LED4;
  }
  digitalWrite(ledON, HIGH);
 
  // working
  while(timer < stageTime){
    key = keypad.getKey();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("default Mode: ");
    lcd.print(defaultMode);
    lcd.setCursor(0,1);
    lcd.print("time: ");
    lcd.print(stageTime - timer);
  
    //pause
    if(key == '*'){
      key = keypad.waitForKey();
      while(key != '*')
      key = keypad.waitForKey();
        
     // change time
    }else if(key == '-'){
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Change Time...");
      
      key = keypad.waitForKey();
    
      lcd.setCursor(0,1);
      lcd.print(key);
      delay(100);
    
      if(key == '1'){
        key = keypad.waitForKey();
        pishTime = key - 48;
        key = keypad.waitForKey();
        pishTime = pishTime*10 + key - 48;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(pishTime);
        delay(250);
        
      }else if(key == '2'){
        key = keypad.waitForKey();
        shooyandeTime = key - 48;
        key = keypad.waitForKey();
        shooyandeTime = shooyandeTime*10 + key - 48;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(shooyandeTime);
        delay(250);
        
      }else if(key == '3'){
        key = keypad.waitForKey();
        abTime = key - 48;
        key = keypad.waitForKey();
        abTime = abTime*10 + key - 48;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(abTime);
        delay(250);

      }else if(key == '4'){
        key = keypad.waitForKey();
        khoskTime = key - 48;
        key = keypad.waitForKey();
        khoskTime = khoskTime*10 + key - 48;
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print(khoskTime);
        delay(250);
        
      }
      
    //change mode 
    }else if (key == '+'){
      
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Change Mode...");
      key = keypad.waitForKey();
      lcd.setCursor(0,1);
      lcd.print(key);
      delay(100);
      if ((key == '1') || (key == '2') || (key == '3') || (key == '4')){
        saveData(key - 48);
        defaultMode = key - 48;
      }
    }
    
    delay(10);
    timer++;
  }

  digitalWrite(ledON, LOW);
  currentMode++;
  // not working
  if(currentMode > 4){
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("FINISH");
    
    key = keypad.waitForKey();
    while(key != '*')
    key = keypad.waitForKey();

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    
    currentMode = loadData();
    if((currentMode != 1) || (currentMode != 2) || (currentMode != 3) || (currentMode != 4))
      currentMode = 1;
    defaultMode = currentMode;
  }
}


// save data in memory
void saveData(int data){
  Wire.beginTransmission(DEV_ADDRESS);
  Wire.write(0x00);
  Wire.write(0xAA);
  Wire.write(data);
  Wire.endTransmission();
}


// load data from memory
int loadData(){
  Wire.beginTransmission(DEV_ADDRESS);
  Wire.write(0x00);
  Wire.write(0xAA);
  Wire.endTransmission();
  Wire.requestFrom(DEV_ADDRESS, 1);
  int data = Wire.read();
  return data;
}
