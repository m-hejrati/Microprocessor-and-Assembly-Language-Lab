#include <LiquidCrystal.h>

const int RS = 13;
const int EN = 12;
const int D4 = 8;
const int D5 = 9;
const int D6 = 10;
const int D7 = 11;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

int counter = 0;

void setup() {
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print(" Mahdi Hejrati ");
  lcd.setCursor(0, 1);
  lcd.print("    9723100    ");
  delay(1000);
  lcd.clear();
  
  lcd.setCursor(0, 0);
  lcd.print("Mahdi");
}

void loop() {   

  if (counter == 11){
    lcd.clear();
    lcd.setCursor(0, 1);
    lcd.print("Mahdi");
  
  } else if (counter == 22){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Mahdi");
    counter = 0;
  
  }else{
    lcd.scrollDisplayRight();
  }
  
  counter ++;
  delay(100);
}
