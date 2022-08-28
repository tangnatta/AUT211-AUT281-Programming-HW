#include <TM1637.h>

#define LDR A1
#define DELAY_TIME 1000

// TMP1637 pins
#define CLK 7
#define DIO 8

TM1637 display(CLK, DIO); // connect hardware and software

void setup()
{
    Serial.begin(115200);

    pinMode(LDR, INPUT);

    display.init(); // init display
    display.set(2); // set brightness (0->7)
}

void loop()
{
    int light = analogRead(LDR);
    Serial.println(light);
    // min (not off / not zero) light is approximately 745
    // max val of light dark is approximately 1010
    light = map(light, 745, 1010, 0, 100);
    Serial.println(light);
    display_number(light);
    delay(DELAY_TIME);
}

void display_number(int number)
{
    if (number < 0)
        number = 0;
    else if (number > 9999)
        number = 9999;
    display.display(3, number % 10);
    display.display(2, number / 10 % 10);
    display.display(1, number / 100 % 10);
    display.display(0, number / 1000 % 10);
}