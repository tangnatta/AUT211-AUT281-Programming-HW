#include <Servo.h>

#define Servo1_pin 9
#define Servo2_pin 10

// delay in milliseconds
const unsigned int Servo1_delay = 100;
const unsigned int Servo2_delay = 200;

int Servo1_increse_step = 1;
int Servo2_increse_step = 1;

unsigned long prevServo1Time = 0;
unsigned long prevServo2Time = 0;

Servo Servo1;
Servo Servo2;

void setup()
{
    Servo1.attach(Servo1_pin);
    Servo2.attach(Servo2_pin);
}

void loop()
{
    unsigned long currentTime = millis();

    if (currentTime - prevServo1Time >= Servo1_delay)
    {
        prevServo1Time = currentTime;
        unsigned char to_angle = Servo1.read() + Servo1_increse_step;
        to_angle = (to_angle > 180) ? 180 : (to_angle < 0) ? 0
                                                           : to_angle;
        Servo1_increse_step = (to_angle <= 0 || to_angle >= 180) ? -Servo1_increse_step : Servo1_increse_step;
        Servo1.write(to_angle);
    }
    if (currentTime - prevServo2Time >= Servo2_delay)
    {
        prevServo2Time = currentTime;
        unsigned char to_angle = Servo2.read() + Servo2_increse_step;
        to_angle = (to_angle > 180) ? 180 : (to_angle < 0) ? 0
                                                           : to_angle;
        Servo2_increse_step = (to_angle <= 0 || to_angle >= 180) ? -Servo2_increse_step : Servo2_increse_step;
        Servo2.write(to_angle);
    }
}