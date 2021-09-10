#include "pitches.h"
#include "jingle.h"

float scale = 0;

void setup() {
 pinMode (A0, INPUT); 
}

void loop() {

    for(int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++){
      
      int noteDuration = 1000 / noteDurations[thisNote];
      scale = analogRead(A0)/512.0;
      tone(1,(int)(melody[thisNote] * scale) , noteDuration);
  
      int pause = noteDuration * 1.30;
      delay(pause);
    }
}
