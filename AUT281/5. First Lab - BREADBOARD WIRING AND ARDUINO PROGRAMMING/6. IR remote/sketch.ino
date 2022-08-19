/*
remote value that come with kit
CHANNEL
45 46 47
44 40 43
07 15  9
16 19  D
 C 18 5E
 8 1C 5A
42 52 4A
LOGO
*/

#include <IRremote.h>
#define IR_PIN 10
#define LED 13
#define DELAY_TIME 500

#define POWER 0x45
#define STOP 0x46

IRrecv IR; // Declare the name to use IR receiver
void setup()
{
    Serial.begin(115200);
    IR.begin(IR_PIN); // Begin to use IR receiver
    pinMode(LED, OUTPUT);
}
void loop()
{
    if (IR.decode())
    { // check if the button of IR remote pushed or not
        unsigned int val = IR.decodedIRData.command;
        Serial.println(val, HEX); // check the value when you push each button.
                                  // LED control code is here later.
        switch (val)
        {
        case POWER:
            digitalWrite(LED, HIGH);
            break;

        case STOP:
            digitalWrite(LED, LOW);
            break;

        default:
            break;
        }

        IR.resume(); // Prepare to receive the next command. Use this with decode.
    }
    delay(DELAY_TIME);
}