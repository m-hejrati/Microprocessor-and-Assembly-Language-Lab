// the number of the LED pin
const int ledPin1 =  A0;
const int ledPin2 =  A1;
const int ledPin3 =  A2;
const int ledPin4 =  A3;
const int ledPin5 =  A7;
const int ledPin6 =  A6;
const int ledPin7 =  A5; 
const int ledPin8 =  A4;
const int ledPin9 =  A8;

// for incoming serial data
int incomingByte = 0;

void setup(){
  Serial.begin(9600);

  // initialize the LEDs pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
}

  
void loop(){
  
  if (Serial.available() > 0) {
    
    // read the incoming byte:
    incomingByte = Serial.read();

    int key = incomingByte - 48;
  
    if (key == 1)
      digitalWrite(ledPin1, HIGH);
    else if (key == 2)
      digitalWrite(ledPin2, HIGH);
    else if (key == 3)
      digitalWrite(ledPin3, HIGH);
    else if (key == 4)
      digitalWrite(ledPin4, HIGH);
    else if (key == 5)
      digitalWrite(ledPin5, HIGH);
    else if (key == 6)
      digitalWrite(ledPin6, HIGH);
    else if (key == 7)
      digitalWrite(ledPin7, HIGH);
    else if (key == 8)
      digitalWrite(ledPin8, HIGH);
    else if (key == 9)
      digitalWrite(ledPin9, HIGH);
    else if (key == 0){
      digitalWrite(ledPin1, LOW);
      digitalWrite(ledPin2, LOW);
      digitalWrite(ledPin3, LOW);
      digitalWrite(ledPin4, LOW);
      digitalWrite(ledPin5, LOW);
      digitalWrite(ledPin6, LOW);
      digitalWrite(ledPin7, LOW);
      digitalWrite(ledPin8, LOW);
      digitalWrite(ledPin9, LOW);
    }
  }
}
