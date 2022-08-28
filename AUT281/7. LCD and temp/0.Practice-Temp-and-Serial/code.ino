#define TMP A0
#define DELAY_TIME 500

void setup()
{
    Serial.begin(115200);
    pinMode(TMP, INPUT);
}

void loop()
{
    int raw_val = analogRead(TMP);
    // Serial.print("raw ");
    // Serial.println(raw_val);
    // int temp = (raw_val / 1023.0) * 500;
    int temp = (raw_val * 4.88) / 10 - 50;
    Serial.print("temp ");
    Serial.println(temp);

    delay(DELAY_TIME);
}