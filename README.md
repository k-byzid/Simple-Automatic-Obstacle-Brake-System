# ATMEGA32 for Obstacle Detection and DC Motor Retardation :traffic_light::oncoming_automobile:<br><br>


## Overview
Our project aims to utilize the computational power of the ATMEGA32 chip to create a system with the help of sensors 
to ensure the safety of the passengers. We use LED string lines to indicate how close an object is to the car from the 
LEFT, RIGHT, and FRONT directions. If a response is not found, then the ATMEGA32 would instruct the car on the best possible
outcome through directional movement and braking.<br><br>

## Proteus System Configuration
<img src="Documents/Circuit_Diagram.PNG" alt="Circuit Diagram" width="600" height="500"><br><br>

## System Flowchart
<img src="Documents/Flowchart.PNG" alt="Circuit Diagram" width="800" height="400"><br><br>

### Functionality of the Left & Right Proximity Sensors (GP2D120)
- At 8 units distance, 2 LEDs light up.
- At 6 units distance, 2 LEDs light up, and the car takes a 45-degree clockwise/anticlockwise turn if the driver does not respond.
- At 4 units distance, 4 LEDs light up, and the car takes a 90-degree clockwise/anticlockwise turn until the driver responds.

### Functionality of the Front Proximity Sensor (GP2D120)
- At 10 units distance, 2 LEDs light up, and the car slowly brakes ensuring a pseudo-constant speed given that the driver does not respond.
- At 8 units distance, 4 LEDs light up, and the car slowly brakes ensuring a pseudo-constant speed given that the driver does not respond.
- At 6 units to 4 units distance, 4 LEDs light up, and the car brakes to a halt until the driver responds.<br><br>


## Requirements
To run the ATMEGA32 for Obstacle Detection and DC Motor Retardation project, you will need the following:

1. ATMEGA32 chip;
2. GP2D120 (proximity sensor)
3. L293D DC Motor Driver
4. ULN2003A Stepper Motor Driver
5. DC Motor
6. Stepper Motor
7. LED (Red, Green, Yellow)
8. Wire
9. Power Supply and Ground
10. Proteus 8 Professional (S.W)
11. Code Vision AVR (S.W)



