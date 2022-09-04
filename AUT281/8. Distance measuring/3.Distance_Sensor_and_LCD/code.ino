class Ultrasonic
{
public:
    /* Cretaes a new instance of the Ultrasonic class.
     * @param triggerPin The pin that is connected to the trigger pin of the ultrasonic sensor.
     * @param echoPin The pin that is connected to the echo pin of the ultrasonic sensor.
     */
    Ultrasonic(int trigPin, int echoPin)
    {
        this->trigPin = trigPin;
        this->echoPin = echoPin;
        pinMode(this->trigPin, OUTPUT);
        pinMode(this->echoPin, INPUT);
    }

    /* Measure the distance of object in front of the sensor
     * return in centimeter.
     */
    float getDistance()
    {
        unsigned long duration = this->getDuration();
        float distance_cm = float(duration) / 2.0 * 0.034;
        return distance_cm;
    }

    /* Measure the length of the ultrasonic from the sensor to the object and object to sensor back.
     * Returns the duration in microseconds.
     */
    unsigned long getDuration()
    {
        digitalWrite(this->trigPin, LOW);
        delayMicroseconds(2);
        digitalWrite(this->trigPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(this->trigPin, LOW);
        unsigned long duration = pulseIn(this->echoPin, HIGH);
        return duration;
    }

private:
    int trigPin;
    int echoPin;
};

#include <LiquidCrystal.h>

#define DELAY_TIME 500
#define RS 8
#define E 9
#define DB4 4
#define DB5 5
#define DB6 6
#define DB7 7

LiquidCrystal LCD(RS, E, DB4, DB5,
                  DB6, DB7);

Ultrasonic ultra = Ultrasonic(2, 3);

void setup()
{
    Serial.begin(115200);
    LCD.begin(16, 2);
}

void loop()
{
    LCD.clear();
    LCD.setCursor(0, 0);
    LCD.print("Distance: ");
    Serial.print("Distance : ");

    LCD.setCursor(1, 1);
    LCD.print(ultra.getDistance());
    LCD.print(" cm.");
    Serial.print(ultra.getDistance());
    Serial.println(" cm.");

    delay(DELAY_TIME);
}