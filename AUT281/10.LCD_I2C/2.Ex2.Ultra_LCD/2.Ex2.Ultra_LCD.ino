#include "Ultrasonic.hpp"

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C LCD(0x27, 16, 2);

Ultrasonic ULTRASONIC(4, 5);

void setup()
{
    LCD.init();
    LCD.backlight();
}

void loop()
{
    LCD.clear();

    float distance = ULTRASONIC.getDistance();

    LCD.setCursor(0, 1);

    if (distance > 200) LCD.print(' ');
    else if (distance > 100) LCD.print("Far");
    else if (distance > 50) LCD.print("Near");
    else if (distance <= 50) LCD.print("Super close");

    LCD.setCursor(0, 0);
    LCD.print("Dis: ");
    LCD.print(distance);
    LCD.print(" cm");

    delay(500);
}