#define LED 13
#define DELAY_TIME 100
void setup()
{
    pinMode(LED, OUTPUT);
}

void loop()
{
    analogWrite(LED, 0);    delay(DELAY_TIME);
    analogWrite(LED, 20);   delay(DELAY_TIME);
    analogWrite(LED, 40);   delay(DELAY_TIME);
    analogWrite(LED, 60);   delay(DELAY_TIME);
    analogWrite(LED, 80);   delay(DELAY_TIME);
    analogWrite(LED, 100);  delay(DELAY_TIME);
    analogWrite(LED, 120);  delay(DELAY_TIME);
    analogWrite(LED, 140);  delay(DELAY_TIME);
    analogWrite(LED, 160);  delay(DELAY_TIME);
    analogWrite(LED, 180);  delay(DELAY_TIME);
    analogWrite(LED, 200);  delay(DELAY_TIME);
    analogWrite(LED, 220);  delay(DELAY_TIME);
    analogWrite(LED, 240);  delay(DELAY_TIME);
    analogWrite(LED, 255);  delay(DELAY_TIME);
}