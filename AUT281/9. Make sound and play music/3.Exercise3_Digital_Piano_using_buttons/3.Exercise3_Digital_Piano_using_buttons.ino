#include "Buzzer.hpp"

Buzzer buzzer(3);

int NOTE[] = {NOTE_C5, NOTE_B4, NOTE_A4, NOTE_G5, NOTE_F4, NOTE_E4, NOTE_D5, NOTE_C4};

void setup()
{
    // Serial.begin(115200);
    DDRA = 0b00000000;
    PORTA = 0b11111111;
}

void loop()
{
    // Serial.println(~PINA, BIN);
    for (int i = 0; i <= 7; i++)
    {
        int bit_val_at_i = _BV(i) & ~PINA;
        // Serial.println(bit_val_at_i, BIN);
        if (bit_val_at_i)
            buzzer.play_note(NOTE[i]);
    }

    if (PINA == 0b11111111)
        buzzer.stop();
}