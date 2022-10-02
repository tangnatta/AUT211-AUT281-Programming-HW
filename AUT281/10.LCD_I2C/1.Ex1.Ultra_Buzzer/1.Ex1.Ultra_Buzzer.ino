#include "Ultrasonic.hpp"
#include "Buzzer_aio.hpp"

MusicBuzzer BUZZER(15);

Ultrasonic ULTRASONIC(4, 5);

void setup()
{
}

void loop()
{
    BUZZER.beep(map(ULTRASONIC.getDistance(), 0, 100, 1000, 200));
}