#include "Buzzer.hpp"

#define BUZZER_PIN 15

Buzzer buzzer(BUZZER_PIN);

void setup()
{
    // Play Never gonna give you up song with Buzzer
    buzzer.play(NOTE_C5, 4);
    buzzer.play(NOTE_C5, 2);
    buzzer.play(NOTE_D5, 4);
    buzzer.play(NOTE_D5, 2);

    buzzer.play(NOTE_G4, 2);
    buzzer.play(NOTE_D5, 4);
    buzzer.play(NOTE_D5, 2);
    buzzer.play(NOTE_E5, 4);

    buzzer.play(NOTE_E5, 2);
    buzzer.play(NOTE_G5, 8);
    buzzer.play(NOTE_F5, 8);
    buzzer.play(NOTE_E5, 8);

    buzzer.play(NOTE_D5, 8);
    buzzer.play(NOTE_C5, 4);
    buzzer.play(NOTE_C5, 2);
    buzzer.play(NOTE_D5, 4);

    buzzer.play(NOTE_D5, 2);
    buzzer.play(NOTE_G4, 4);
    buzzer.play(NOTE_G4, 2);
}

void loop()
{
}
