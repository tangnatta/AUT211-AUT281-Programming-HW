/*************************************************
 * Public Constants
 *************************************************/

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

class Buzzer
{
private:
    uint8_t _Buzzer_pin;

public:
    Buzzer()
    {
    }
    ~Buzzer()
    {
    }
    /* Create a new instant for Buzzer class.
     * @param pin (uint8_t / unsigned char) : The pin that is connected to the buzzer.
     */
    Buzzer(uint8_t pin)
    {
        this->_Buzzer_pin = pin;
        pinMode(this->_Buzzer_pin, OUTPUT);
    }

    void beep(unsigned int frequency)
    {
        // note durations: 4 = quarter note, 8 = eighth note, etc.:
        tone(this->_Buzzer_pin, frequency);
    }

    /* beep with the Buzzer (without delay included)
     * @param frequency (unsigned int) : The frequency of the beep.
     * @param duration (unsigned long) : (optional) duration of the beep in milliseconds
     */
    void beep(unsigned int frequency, unsigned long duration)
    {
        // note durations: 4 = quarter note, 8 = eighth note, etc.:
        tone(this->_Buzzer_pin, frequency, duration);
    }

    /* stop the Buzzer
     */
    void stop()
    {
        noTone(this->_Buzzer_pin);
    }
};

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

#define BEAT_MODE 0
#define ONE_OVER_MODE 1

class MusicBuzzer : public Buzzer
{
private:
    float _whole_note;
    float _1beat;
    uint8_t _MODE;

    /* Return the duration of note in millisecond (float). corespon to the tempo.
     * @param duration (float) : The duration of the note.
     */
    float get_note_duration(float duration)
    {
        switch (this->_MODE)
        {
        default:
        case ONE_OVER_MODE:
            return (duration > 0.0) ? (this->_whole_note / duration) : ((this->_whole_note / -(duration)) * 1.5);
            break;
        case BEAT_MODE:
            return (duration > 0.0) ? duration * this->_1beat : -duration * this->_1beat * 1.5;
            break;
        }
    }

public:
    MusicBuzzer()
    {
    }
    ~MusicBuzzer()
    {
    }
    MusicBuzzer(uint8_t pin) : Buzzer(pin)
    {

        this->set_tempo(100);
        this->set_mode(ONE_OVER_MODE);
    }
    MusicBuzzer(uint8_t pin, int tempo) : Buzzer(pin)
    {
        this->set_tempo(tempo);
        this->set_mode(ONE_OVER_MODE);
    }
    /* Create a new instant for Buzzer class.
     * @param pin (uint8_t / unsigned char) : The pin that is connected to the buzzer.
     * @param tempo (float) : The tempo of the song (beat per minute).
     * @param mode (uint8_t / unsigned char) : The mode of the Buzzer. [default is ONE_OVER_MODE] 0 for beat mode (BEAT_MODE), 1 for 1/beat mode (ONE_OVER_MODE). EX. BEAT_MODE 1 = quater note, 4 = whole note; ONE_OVER_MODE 1 = whole note, 4 = quater note.
     */
    MusicBuzzer(uint8_t pin, float tempo, uint8_t mode) : Buzzer(pin)
    {
        this->set_tempo(tempo);
        this->set_mode(mode);
    }

    /* play the song in array that have {NOTE, DURATION, NOTE2, DURAION2, ...}
     * @param note_duration_arr (float) : The array that have {NOTE, DURATION, NOTE2, DURAION2, ...}
     * @param note_quantity (int) :  The number of note in array can caculate with sizeof(note_duration_arr) / sizeof(note_duration_arr[0]) / 2.
     */
    void play_array(float note_duration_arr[], int note_quantity)
    {
        // int note_quantity = sizeof(note_duration_arr) / sizeof(note_duration_arr[0]) / 2;
        for (int thisNote = 0; thisNote < note_quantity * 2; thisNote += 2)
        {
            this->play(note_duration_arr[thisNote], note_duration_arr[thisNote + 1]);
        }
    }

    /* play note with the Buzzer (with delay included)
     * @param note (unsigned int) : The note to Play ex. NOTE_A1, NOTE_C1, NOTE_A4, NOTE_C4, etc.
     * @param duration (float) : The duration of the note 4 = quarter note, 8 = eighth note, etc. if (-) mean dotted note ex. -4 is dotted quarter note
     */
    void play(unsigned int note, float duration)
    {
        // Note input as NOTE_** Ex NOTE_C4, NOTE_C5, NOTE_A4 etc.
        // note durations: 4 = quarter note, 8 = eighth note, etc.:
        int noteDuration = this->get_note_duration(duration);
        this->beep(note, noteDuration * 0.95);
        delay(noteDuration * 1); // pause between notes is 100% of note duration
        this->stop();
    }

    /* set new tempo
     * @param tempo (float) : The tempo of the song (beat per minute).
     */
    void set_tempo(float tempo)
    {
        this->_1beat = (60000) / tempo;
        this->_whole_note = this->_1beat * 4;
    }

    /* set new mode
     * @param mode (uint8_t / unsigned char) : The mode of the Buzzer. 0 for beat mode (BEAT_MODE), 1 for 1/beat mode (ONE_OVER_MODE). EX. BEAT_MODE 1 = quater note, 4 = whole note; ONE_OVER_MODE 1 = whole note, 4 = quater note.
     */
    void set_mode(uint8_t mode)
    {
        this->_MODE = mode;
    }
};