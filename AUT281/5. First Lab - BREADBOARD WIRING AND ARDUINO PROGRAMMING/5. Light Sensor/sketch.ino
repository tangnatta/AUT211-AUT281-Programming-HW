#define LED 13
#define LDR A1
#define DELAY_TIME 100

void setup()
{
    Serial.begin(115200);
    pinMode(LED, OUTPUT);
    pinMode(LDR, INPUT);
}

void loop()
{
    int val = analogRead(LDR);
    Serial.println(val);
    if (val >= 925) digitalWrite(LED, HIGH);
    else digitalWrite(LED, LOW);
}