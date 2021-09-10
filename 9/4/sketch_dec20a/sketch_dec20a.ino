#include "pitches.h"
#include "ode.h"

void setup() {

}

void loop() {
   for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++){

    int noteDuration = 1000 / noteDurations[thisNote];
    tone(1, melody[thisNote], noteDuration);

    int pause = noteDuration * 1.3;
    delay(pause);
   }
   
}
