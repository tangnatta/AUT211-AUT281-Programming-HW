// Code for MasterMC
#include <BluetoothSerial.h>
#define SLA1_RX_PIN 2
#define SLA1_TX_PIN 3
// #define SLA2_RX_PIN 4
// #define SLA2_TX_PIN 5
#define ON 1
#define OFF 0
#define SW 9
// Communication with SlaveMC
// SoftwareSerial Slave2MC(SLA2_RX_PIN, SLA2_TX_PIN); // name slave microcontroller SlaveMC

BluetoothSerial SerialBT;

bool menu;
bool last_sw;

void setup()
{
    SerialBT.begin("HC-05");
    // // Serial.begin(115200); // PC
    // Slave1MC.begin(38400); // MC
    // // Make SlaveMC listen

    // // Serial.begin(115200); // PC
    // Slave2MC.begin(9600); // MC
    // Make SlaveMC listen

    Serial.println("Ready.");

    pinMode(SW, INPUT_PULLUP);
}

void loop()
{

    // bool sw = !digitalRead(SW);
    // Serial.println(sw);

    // if (sw != last_sw)
    // {
    //     SerialBT.print(sw);
    //     // Slave2MC.listen();
    //     // Slave2MC.print(sw);
    //     last_sw = sw;
    // }
    SerialBT.print('1');
    delay(10000);
    SerialBT.print('0');
    delay(1000);
}