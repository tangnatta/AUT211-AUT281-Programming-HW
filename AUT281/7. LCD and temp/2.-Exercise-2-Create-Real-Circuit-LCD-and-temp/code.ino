#include <LiquidCrystal.h>

#define TMP A0
#define DELAY_TIME 500
#define RS 8
#define E 9
#define DB4 4
#define DB5 5
#define DB6 6
#define DB7 7

LiquidCrystal LCD(RS, E, DB4, DB5, DB6, DB7);

void setup()
{
    Serial.begin(115200);
    LCD.begin(16, 2);
    pinMode(TMP, INPUT);
}

void loop()
{
    int raw_val = analogRead(TMP);
    Serial.print("raw ");
    Serial.println(raw_val);
    // int temp = (raw_val / 1023.0) * 500;
    int temp = (raw_val * 4.88) / 10;
    Serial.print("temp ");
    Serial.println(temp);

    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("Temp");
    LCD.setCursor(1, 1);
    LCD.print(temp);
    LCD.print(" *C");

    delay(DELAY_TIME);
}