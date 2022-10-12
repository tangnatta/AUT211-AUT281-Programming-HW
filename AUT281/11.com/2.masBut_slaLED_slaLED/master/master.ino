// Code for MasterMC
#include <SoftwareSerial.h>
#define SLA1_RX_PIN 2
#define SLA1_TX_PIN 3
#define SLA2_RX_PIN 4
#define SLA2_TX_PIN 5
#define ON 1
#define OFF 0
#define SW 6
// Communication with SlaveMC
SoftwareSerial Slave1MC(SLA1_RX_PIN, SLA1_TX_PIN); // name slave microcontroller SlaveMC
SoftwareSerial Slave2MC(SLA2_RX_PIN, SLA2_TX_PIN); // name slave microcontroller SlaveMC

bool menu;
bool last_sw;

void setup()
{
    // Serial.begin(115200); // PC
    Slave1MC.begin(9600); // MC
    // Make SlaveMC listen

    // Serial.begin(115200); // PC
    Slave2MC.begin(9600); // MC
    // Make SlaveMC listen

    Serial.println("Ready.");

    pinMode(SW, INPUT_PULLUP);
}

void loop()
{
    
    bool sw = !digitalRead(SW);
    Serial.println(sw);


    if (sw != last_sw)
    {
        Slave1MC.listen();
        Slave1MC.print(sw);
        Slave2MC.listen();
        Slave2MC.print(sw);
        last_sw = sw;
    }
}