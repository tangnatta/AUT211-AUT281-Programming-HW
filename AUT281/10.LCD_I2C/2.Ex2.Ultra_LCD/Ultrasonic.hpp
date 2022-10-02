class Ultrasonic
{
public:
    /* Cretaes a new instance of the Ultrasonic class.
     * @param triggerPin The pin that is connected to the trigger pin of the ultrasonic sensor.
     * @param echoPin The pin that is connected to the echo pin of the ultrasonic sensor.
     */
    Ultrasonic(uint8_t trigPin, uint8_t echoPin)
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
    uint8_t trigPin;
    uint8_t echoPin;
};