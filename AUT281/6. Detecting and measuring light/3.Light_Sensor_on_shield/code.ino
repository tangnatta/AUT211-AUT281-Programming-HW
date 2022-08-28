#define LDR A1
#define DELAY_TIME 1000

#define BLUE 2
#define GREEN 3
#define RED_1 4
#define RED_2 5

void setup()
{
    pinMode(BLUE, OUTPUT);
    pinMode(GREEN, OUTPUT);
    pinMode(RED_1, OUTPUT);
    pinMode(RED_2, OUTPUT);
    pinMode(LDR, INPUT);
    Serial.begin(115200);
}

void loop()
{
    int light = analogRead(LDR);
    Serial.println(light);
    // min (not off / not zero) light is approximately 745
    // max val of light dark is approximately 1010
    light = map(light, 745, 1010, 0, 9);
    Serial.println(light);
    // Serial.println(light);
    if (light == 0)
    {
        digitalWrite(BLUE, LOW);
        digitalWrite(GREEN, LOW);
        digitalWrite(RED_1, LOW);
        digitalWrite(RED_2, LOW);
    }
    else if (light <= 2)
    {
        digitalWrite(BLUE, HIGH);
        digitalWrite(GREEN, LOW);
        digitalWrite(RED_1, LOW);
        digitalWrite(RED_2, LOW);
    }
    else if (light <= 5)
    {
        digitalWrite(BLUE, HIGH);
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED_1, LOW);
        digitalWrite(RED_2, LOW);
    }
    else if (light <= 8)
    {
        digitalWrite(BLUE, HIGH);
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED_1, HIGH);
        digitalWrite(RED_2, LOW);
    }
    else if (light > 8)
    {
        digitalWrite(BLUE, HIGH);
        digitalWrite(GREEN, HIGH);
        digitalWrite(RED_1, HIGH);
        digitalWrite(RED_2, HIGH);
    }
    delay(DELAY_TIME);
}