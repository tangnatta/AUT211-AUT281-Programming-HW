/*
Val. | A B C D  E F G DP.
 0   | 1 1 1 1  1 1 0 0
 1   | 0 1 1 0  0 0 0 0
 2   | 1 1 0 1  1 0 1 0
 3   | 1 1 1 1  0 0 1 0
 4   | 0 1 1 0  0 1 1 0
 5   | 1 0 1 1  0 1 1 0
 6   | 1 0 1 1  1 1 1 0
 7   | 1 1 1 0  0 0 0 0
 8   | 1 1 1 1  1 1 1 0
 9   | 1 1 1 1  0 1 1 0
 .   | 0 0 0 0  0 0 0 1
*/

#define A 11
#define B 10
#define C 7
#define D 8
#define E 9
#define F 12
#define G 13
#define DP 6

#define DELAY_TIME 1000

void setup()
{
    for (int i = 6; i <= 13; i++)
    {
        pinMode(i, OUTPUT);
    }
    Serial.begin(115200);
}

void loop()
{
    for (int i = 0; i <= 9; i++)
    {
        set7seg(i);
        delay(DELAY_TIME);
    }
}

void set7seg(char val)
{
    switch (val)
    {
    case (0):
        zero();
        break;
    case (1):
        one();
        break;
    case (2):
        two();
        break;
    case (3):
        three();
        break;
    case (4):
        four();
        break;
    case (5):
        five();
        break;
    case (6):
        six();
        break;
    case (7):
        seven();
        break;
    case (8):
        eight();
        break;
    case (9):
        nine();
        break;
    default:
        zero();
        break;
    }
}

void zero()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
}

void one()
{
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
}

void two()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, LOW);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void three()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void four()
{
    digitalWrite(A, LOW);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void five()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void six()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, LOW);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void seven()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, LOW);
}

void eight()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void nine()
{
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, LOW);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
    digitalWrite(DP, LOW);
}

void dot()
{
    digitalWrite(A, LOW);
    digitalWrite(B, LOW);
    digitalWrite(C, LOW);
    digitalWrite(D, LOW);
    digitalWrite(E, LOW);
    digitalWrite(F, LOW);
    digitalWrite(G, LOW);
    digitalWrite(DP, HIGH);
}