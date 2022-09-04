#include "Ultrasonic.cpp"

Ultrasonic ultra = Ultrasonic(2, 3);

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.print("Distance : ");
    Serial.print(ultra.getDistance());
    Serial.println(" cm.");
}