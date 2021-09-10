#include "pitches.h"
#include "jingle.h"

void setup() {
  
}

void loop() {
  int buttonState = digitalRead(8);

  if (buttonState == HIGH) {
    for(int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++){
      
      int noteDuration = 1000 / noteDurations [thisNote];
      tone(1, melody[thisNote], noteDuration);
      
      int pause = noteDuration * 1.30;
      delay(pause);
    }
    
  }
  
}
