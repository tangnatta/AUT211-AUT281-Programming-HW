//! FOR UNO | Tinkercad
// Port Manipulation / Registor
/*
Val. | A B C D  E F G DP.
 0   | 1 1 1 1  1 1 0 0
 1   | 0 1 1 0  0 0 0 0
 2   | 1 1 0 1  1 0 1 0
 3   | 1 1 1 1  0 0 1 0
 4   | 0 1 1 0  0 1 1 0
 5   | 1 0 1 1  0 1 1 0
 6   | 1 0 1 1  1 1 1 0
 7   | 1 1 1 0  0 0 0 0
 8   | 1 1 1 1  1 1 1 0
 9   | 1 1 1 1  0 1 1 0
 .   | 0 0 0 0  0 0 0 1

Val. | DP. G F E  D C B A
 0   |  0  0 1 1  1 1 1 1
 1   |  0  0 0 0  0 1 1 0
 2   |  0  1 0 1  1 0 1 1
 3   |  0  1 0 0  1 1 1 1
 4   |  0  1 1 0  0 1 1 0
 5   |  0  1 1 0  1 1 0 1
 6   |  0  1 1 1  1 1 0 1
 7   |  0  0 0 0  0 1 1 1
 8   |  0  1 1 1  1 1 1 1
 9   |  0  1 1 0  1 1 1 1
 .   |  1  0 0 0  0 0 0 0

 val   = 1
 DDRD  = 0b11111111  // similar to pinMode
 PORTD = 0b00111111  // similar to digitalWrite
   PIN     76543210
 7-seg   DP.GFEDCBA
*/

#define PHOTO_D A0
#define DELAY_TIME 500

void setup()
{
    DDRD = 0b11111111;
    pinMode(PHOTO_D, INPUT);
    // Serial.begin(115200);
}

void loop()
{
    // int light = analogRead(PHOTO_D);
    // // Serial.println(light);
    // // min (not off / not zero) is approximately 70
    // // max val of light is approximately 85
    // light = map(light, 70, 85, 0, 9);
    // setnum(light);

    for (int i = 0; i <= 9; i++){
        setnum(i);
        delay(DELAY_TIME);
    }
}

void setnum(int num)
{
    int bin[] = {
        0b00111111,
        0b00000110,
        0b01011011,
        0b01001111,
        0b01100110,
        0b01101101,
        0b01111101,
        0b00000111,
        0b01111111,
        0b01101111,
    };
    if (num > 9)
        num = 9;
    else if (num < 0)
        num = 0;
    PORTD = bin[num];
}