/*
 * Borge, Wad, Økter
 * 
 * A main libary for handling of the quing of the floors, optemized path 
 * planing and activating the elevator
 * 
 * Take in four list int he constructor with setup numbers for the system
 * - elevatroList --> [setpperPin 1, stepperPin 2, stepperPin3, stepperPin4, servoPin]
 * - switchlist --> [buttonPin 8-1, groundSwitchPin, alarm Pin] 
 * - floorChooserList --> [potmeter pin, index of arrowbutton from switchrow 1, index of arrowbutton from switchrow 2]
 * - lcdList --> [rs, rw, enable, d4, d5, d6, d7]
 * 
 * Use mainSetup() in the setup to start the controll unit correct
 * Use mainLoop() in loop for runing the compleat code and self controll of the unit
 * 
 * Use updateInput to look for updating the que with input
 * Use naxtFloor() to make the elevator move to the optimized next floor
 * 
 * This liabry require: arduino, elevator, switch, floorchooser, lcd
 */

#ifndef que_h
#define que_h

#include "Arduino.h"
#include "elevator.h"
#include "Switch.h"
#include "floorchooser.h"
#include "lcd.h"

class Que{
  public:
    Que(int elevatorList[], int switchList[], int floorChooserList[], int lcdList[]);
    void mainSetup();
    void mainLoop();
    void updateInputs();
    void nextFloor();
    
  private:
    int floorQue[20];
    int floorDir[20];
    int queIndex;
    void addToQue(int thefloor, int direct, int importance);

    Switch Switchrow_;
    Elevator JmSkylift_;
    FloorChooser Floorcaller_;
    LCD Mainscreen_;
};

#endif
