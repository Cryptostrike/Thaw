Freezer transmitter
===

Read sensor 1 and 2 every 30 seconds, collect data in mySQL db and average over 5 minutes.

If sensorRead < sensorTarget display red LED [and buzz every 30 seconds.]

Transmit data every 5 minutes in format [SigByte [F1 : TEMP1] [F2 : TEMP2]]


Freezer reciever
===

Recieve data every 5 minutes.

|Freezer 1 |  Feed status   |
| O O O    |  O    O    O   |
| G Y R    |  G    A    R   |
|          | <15  <30   >60 | 
|Freezer 2 |                |
| O O O    |      [O]       |    
| G Y R    |  Buzzer off    |


Freezer module:

if TEMP < -15 status LED green ON

if  -15 > TEMP > -8 LED yellow ON

if TEMP > -8 LED red ON, buzzer on (30 second interval)


System status module:

if recieved transmission within 15 minutes LED green ON

if not recieved in last 15 minutes but less that 30 minutes LED yellow ON

if not recieved for 60 minutes LED red ON, buzzer every 5 minutes (if button pressed then buzzer off)


Ethernet module:

Push [F1 : TEMP1, STATUS] [F2 : TEMP2, STATUS] [FEED : TIME, STATUS]
