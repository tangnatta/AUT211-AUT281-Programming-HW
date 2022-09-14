#define LED_RED 13
#define LED_GREEN 11
int ledRedState = LOW;
// last time LED was updated
unsigned long prevRedTime = 0;
// interval at which to turn on (milliseconds)
const unsigned int redOnTime = 1000;
// interval at which to turn off (milliseconds)
const unsigned int redOffTime = 200;
int ledGreenState = LOW;
// will store last time LED was updated
unsigned long prevGreenTime = 0;
// interval at which to turn on (milliseconds)
const unsigned int greenOnTime = 1200;
// interval at which to turn off (milliseconds)
const unsigned int greenOffTime = 300;
void setup()
{
    pinMode(LED_RED, OUTPUT);
    pinMode(LED_GREEN, OUTPUT);
    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, LOW);
}

void loop()
{
    unsigned long currentTime = millis();
    
    /* Red LED */
    if ((ledRedState == LOW) && (currentTime - prevRedTime >= redOffTime))
    {
        prevRedTime = currentTime;
        ledRedState = HIGH;
        digitalWrite(LED_RED, ledRedState);
    }
    else if ((ledRedState == HIGH) && (currentTime - prevRedTime >= redOnTime))
    {
        prevRedTime = currentTime;
        ledRedState = LOW;
        digitalWrite(LED_RED, ledRedState);
    }

    /* Green LED */
    if ((ledGreenState == LOW) && (currentTime - prevGreenTime >= greenOffTime))
    {
        prevGreenTime = currentTime;
        ledGreenState = HIGH;
        digitalWrite(LED_GREEN, ledGreenState);
    }
    else if ((ledGreenState == HIGH) && (currentTime - prevGreenTime >= greenOnTime))
    {
        prevGreenTime = currentTime;
        ledGreenState = LOW;
        digitalWrite(LED_GREEN, ledGreenState);
    }
}