// the number of the pushbutton pin
const int buttonPin1 = 10;
const int buttonPin2 = 11;
const int buttonPin3 = 12;

// the number of the LED pin
const int ledPin1 =  0;
const int ledPin2 =  1;
const int ledPin3 =  2;
const int ledPin4 =  3;
const int ledPin5 =  4;
const int ledPin6 =  5;
const int ledPin7 =  6; 

// variable for reading the pushbutton status
int button1State = 0;
int button2State = 0;
int button3State = 0;

void setup() {

  // initialize the LEDs pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);

  // initialize the pushbuttons pin as input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  button1State = digitalRead(buttonPin1);
  button2State = digitalRead(buttonPin2);
  button3State = digitalRead(buttonPin3);

  // check which pushbutton is pressed.
  if (button1State == LOW) {
    
    // turn LEDs on from left side:
    digitalWrite(ledPin7, HIGH);
    delay(250);
    digitalWrite(ledPin6, HIGH);
    delay(250);
    digitalWrite(ledPin5, HIGH);
    delay(250);
    digitalWrite(ledPin4, HIGH);
    delay(250);
    digitalWrite(ledPin3, HIGH);
    delay(250);
    digitalWrite(ledPin2, HIGH);
    delay(250);
    digitalWrite(ledPin1, HIGH);
    delay(250);
    
  } else if (button2State == LOW) {
    
    // turn LEDs off from right side:
    digitalWrite(ledPin1, HIGH);
    delay(250);
    digitalWrite(ledPin2, HIGH);
    delay(250);
    digitalWrite(ledPin3, HIGH);
    delay(250);
    digitalWrite(ledPin4, HIGH);
    delay(250);
    digitalWrite(ledPin5, HIGH);
    delay(250);
    digitalWrite(ledPin6, HIGH);
    delay(250);
    digitalWrite(ledPin7, HIGH);
    delay(250);
    
  }else if (button3State == LOW) {
    // turn LEDs off:
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, LOW);
    
  }
}
