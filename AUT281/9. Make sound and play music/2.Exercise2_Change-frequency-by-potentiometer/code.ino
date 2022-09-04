#define BUZZER 3
#define POTEN A0

void setup()
{
    pinMode(BUZZER, OUTPUT);
    pinMode(POTEN, INPUT);
}

void loop()
{
    int val = analogRead(POTEN);
    val = map(val, 0, 1023, 31, 20000);
    tone(BUZZER, val);
}