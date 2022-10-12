// Code for SlaveMC
#include <SoftwareSerial.h>
#define RX_PIN 10
#define TX_PIN 11
#define LED_PIN 13
#define ON '1'  // ASCII code ‘1’
#define OFF '0' // ASCII code ‘0’
// Communication with MasterMC
SoftwareSerial MasterMC(RX_PIN,
                        TX_PIN); // name master microcontroller MasterMC
int menu;
void setup()
{
    Serial.begin(115200); // PC
    MasterMC.begin(9600); // MC
    pinMode(LED_PIN, OUTPUT);
    Serial.println("Slave Ready.");
}

void loop()
{
    if (MasterMC.available())
    {
        // Reveive data from MasterMC
        menu = MasterMC.read();
        // Check the received data
        Serial.println(menu);
        digitalWrite(LED_PIN, (menu == ON)? HIGH: LOW);
        // if (menu == ON)
        // {
        //     digitalWrite(LED_PIN, HIGH);
        // }
        // else if (menu == OFF)
        // {
        //     digitalWrite(LED_PIN, LOW);
        // }
    }
}