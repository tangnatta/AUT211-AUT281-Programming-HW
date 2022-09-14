#define LED_RED 13
#define LED_GREEN 11
int ledRedState = LOW;
int ledGreenState = LOW;
// last time LED was updated
unsigned long prevRedTime = 0;
// will store last time LED was updated
unsigned long prevGreenTime = 0;
// interval at which to turn on (milliseconds)
const unsigned int redDelayTime = 1000;
const unsigned int greenDelayTime = 300;
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
    if (currentTime - prevRedTime >= redDelayTime)
    {
        prevRedTime = currentTime;
        ledRedState = !ledRedState;
        digitalWrite(LED_RED, ledRedState);
    }
    /* Green LED */
    if (currentTime - prevGreenTime >= greenDelayTime)
    {
        prevGreenTime = currentTime;
        ledGreenState = !ledGreenState;
        digitalWrite(LED_GREEN, ledGreenState);
    }
}