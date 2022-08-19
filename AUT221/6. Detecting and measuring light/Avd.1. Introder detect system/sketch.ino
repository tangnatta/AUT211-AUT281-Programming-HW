#define PIR 13
#define PHOTO_D A0
#define LED 2
#define DELAY_TIME 500

void setup()
{
    pinMode(PIR, INPUT);
    pinMode(PHOTO_D, INPUT);
    pinMode(LED, OUTPUT);
}

void loop()
{
    int light = analogRead(PHOTO_D);
    // min (not off / not zero) is approximately 70
    // max val of light is approximately 85
    if (light > 80)
        return;
    bool pir = digitalRead(PIR);
    if (pir)
        digitalWrite(LED, HIGH);
    else
        digitalWrite(LED, LOW);
    delay(DELAY_TIME);
}