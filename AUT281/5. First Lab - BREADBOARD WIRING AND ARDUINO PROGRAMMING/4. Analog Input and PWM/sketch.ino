#define LED 13
#define POTENTIOMETER A0
#define DELAY_TIME 100

void setup()
{
    pinMode(LED, OUTPUT);
    pinMode(POTENTIOMETER, INPUT);
}

void loop()
{
    int val = analogRead(POTENTIOMETER);
    val = map(val, 0, 1023, 0, 255);
    analogWrite(LED, val);
}