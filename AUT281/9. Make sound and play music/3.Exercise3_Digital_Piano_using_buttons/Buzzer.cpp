#include <Arduino.h>

// Melody from Tom Igoe (Public Constants)
// Note in C major
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978

// DEFINE DEFAULT FREQUENCY
#define NOTE_c NOTE_C3
#define NOTE_d NOTE_D3
#define NOTE_e NOTE_E3
#define NOTE_f NOTE_F3
#define NOTE_g NOTE_G3
#define NOTE_a NOTE_A3
#define NOTE_b NOTE_B3
#define NOTE_C NOTE_C4
#define NOTE_D NOTE_D4
#define NOTE_E NOTE_E4
#define NOTE_F NOTE_F4
#define NOTE_G NOTE_G4
#define NOTE_A NOTE_A4
#define NOTE_B NOTE_B4
#define REST 0

class Buzzer
{
private:
    int _Buzzer_pin;
    int _whole_note;

public:
    Buzzer() {}
    Buzzer(int pin)
    {
        this->_Buzzer_pin = pin;
        pinMode(this->_Buzzer_pin, OUTPUT);
        this->_whole_note = 1000;
    }
    /* Create a new instant for Buzzer class.
     * @param pin The pin that is connected to the buzzer.
     * @param tempo The tempo of the song (beat per minute).
     */
    Buzzer(int pin, int tempo)
    {
        this->_Buzzer_pin = pin;
        pinMode(this->_Buzzer_pin, OUTPUT);
        this->set_tempo(tempo);
    }

    /* play the song in array that have {NOTE, DURATION, NOTE2, DURAION2, ...}
     * @param note_duration_arr The array that have {NOTE, DURATION, NOTE2, DURAION2, ...}
     */
    void play_array(int note_duration_arr[])
    {
        int arr_size = sizeof(note_duration_arr) / sizeof(note_duration_arr[0]) / 2;
        for (int thisNote = 0; thisNote < arr_size * 2; thisNote += 2)
        {
            this->play_note(note_duration_arr[thisNote], note_duration_arr[thisNote + 1]);
        }
    }

    /* play note with the Buzzer (with delay included)
     * @param note The note to Play ex. NOTE_A1, NOTE_C1, NOTE_A4, NOTE_C4, etc.
     * @param duration The duration of the note 4 = quarter note, 8 = eighth note, etc. if (-) mean dotted note ex. -4 is dotted quarter note
     */
    void play(unsigned int note, unsigned int duration)
    {
        // Note input as NOTE_** Ex NOTE_C4, NOTE_C5, NOTE_A4 etc.
        // note durations: 4 = quarter note, 8 = eighth note, etc.:
        int noteDuration = (duration > 0) ? (_whole_note / duration) : ((_whole_note / abs(duration)) * 1.5);
        this->play_note(note, noteDuration * 0.95);
        delay(noteDuration * 1.05); // pause between notes is 105% of note duration
        this->stop();
    }

    /* play note with the Buzzer (without delay included) Please use play instread of play_notes instead
     * @param note The note to Play ex. NOTE_A1, NOTE_C1
     * @param duration of the tone in milliseconds
     */
    void play_note(unsigned int note, unsigned int duration = NULL)
    {
        // note durations: 4 = quarter note, 8 = eighth note, etc.:
        (!note) ? this->stop() : tone(this->_Buzzer_pin, note, duration);
    }

    /* set new tempo
     * @param tempo The tempo of the song (beat per minute).
     */
    void set_tempo(int tempo)
    {
        this->_whole_note = round((60000 * 4) / tempo);
    }

    /* stop the Buzzer
     */
    void stop()
    {
        noTone(this->_Buzzer_pin);
    }
};