# Exercise 2: Ultrasonic sensor (2)

1. Create the circuit on the bread board in real
2. Draw the flowchart of the following table conditions
   and actions as follows. (only the table part is ok)

|        State         |        Validation         |               Description               |
| :------------------: | :-----------------------: | :-------------------------------------: |
|     No obstacles     |     distance > 200cm      |            Turn off the LED             |
|   Distant obstacle   | 200cm >= distance > 100cm | Blink the LED at 0.5 seconds intervals  |
|   Nearby obstacle    | 100cm >= distance > 50cm  | Blink the LED at 0.25 seconds intervals |
| Super close obstacle |     distance <= 50cm      |         Turn on the LED always          |

3. Create the Code so that is works as above.
4. Run the program and watch the behavior.
   • Use ruler to measure the distance in real.
5. Submit a flowchart, picture of the circuit, and code to
   report.

# Flowchart

```mermaid
flowchart TB

START --> SETUP_1

SETUP_1[SETUP] --> LOOP_getDistance

LOOP_getDistance[/Distance = getDistance form Ultrasonic sensor/] --> LOOP_Dec1-1{Distance <= 50}
LOOP_Dec1-1 -->|True| LOOP_Dec1-1_Res[Turn on the LED always]
LOOP_Dec1-1 -->|False| LOOP_Dec1-2{Distance <= 100}
LOOP_Dec1-2 -->|True| LOOP_Dec1-2_Res[Blink the LED at 0.5 seconds]
LOOP_Dec1-2 -->|False| LOOP_Dec1-3{Distance <= 200}
LOOP_Dec1-3 -->|True| LOOP_Dec1-3_ResT[Blink the LED at 0.25 seconds]
LOOP_Dec1-3 -->|False| LOOP_Dec1-3_ResF[Turn off the LED]

subgraph SETUP
direction TB
SETUP_1
end

subgraph LOOP
direction TB
LOOP_getDistance
LOOP_Dec1-1
LOOP_Dec1-1_Res
LOOP_Dec1-2
LOOP_Dec1-2_Res
LOOP_Dec1-3
LOOP_Dec1-3_ResT
LOOP_Dec1-3_ResF
end
```

# Circuit Image

![Circuit Image](./Circuit.jpg)

# [Jump to Code Section](./sketch.ino)
