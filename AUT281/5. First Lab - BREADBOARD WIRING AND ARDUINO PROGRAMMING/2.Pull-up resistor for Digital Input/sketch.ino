#define BUTTON 7 // the input pin
#define LED 13   // pin for LED
int val = 0;
// used to store the state of the input pin

void setup()
{
    pinMode(BUTTON, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    val = digitalRead(BUTTON);
    if (val == LOW)
    {
        digitalWrite(LED, HIGH);
    }
    else
    {
        digitalWrite(LED, LOW);
    }
}