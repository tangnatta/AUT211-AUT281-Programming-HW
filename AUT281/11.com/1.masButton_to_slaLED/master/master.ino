// Code for MasterMC
#include <SoftwareSerial.h>
#define RX_PIN 2
#define TX_PIN 3
#define ON 1
#define OFF 0
#define SW 4
// Communication with SlaveMC
SoftwareSerial SlaveMC(RX_PIN,
                       TX_PIN); // name slave microcontroller SlaveMC

bool menu;
bool last_sw;

void setup()
{
    // Serial.begin(115200); // PC
    SlaveMC.begin(9600); // MC
    // Make SlaveMC listen
    SlaveMC.listen();
    Serial.println("Ready.");

    pinMode(SW, INPUT);
}

void loop()
{
    bool sw = digitalRead(SW);

    if (sw != last_sw)
    {
        SlaveMC.print(sw);
        last_sw = sw;
    }
}