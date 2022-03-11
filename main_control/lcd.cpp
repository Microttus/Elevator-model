#include "Arduino.h"
#include "lcd.h"

LCD::LCD(int lcdPins[])
: screen_(lcdPins[0], lcdPins[1], lcdPins[2], lcdPins[3], lcdPins[4], lcdPins[5])
, pwmPin(lcdPins[6])
, currentFloor(0)
, currentCFloor(0)
{
    screen_.begin(16, 2);
    analogWrite(pwmPin, 255);
}

void LCD::updateFloor(int Floor){
    currentFloor = Floor;
    screen_.setCursor(0, 0);
    screen_.print("Observer at:");
    screen_.setCursor(0, 1);
    screen_.print("Elevator at:");
    screen_.setCursor(15, 0);
    screen_.print(currentCFloor);
    screen_.setCursor(15, 1);
    screen_.print(currentFloor);
}

void LCD::updateFloorChooser(int cFloor){
    currentCFloor = cFloor;
    screen_.setCursor(0, 0);
    screen_.print("Observer at:");
    screen_.setCursor(0, 1);
    screen_.print("Elevator at:");
    screen_.setCursor(15, 0);
    screen_.print(currentCFloor);
    screen_.setCursor(15, 1);
    screen_.print(currentFloor);
}
