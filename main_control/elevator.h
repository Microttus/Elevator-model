/*
 * Martin Økter
 * 20.10.2021
 * Elevator controll libary
 * For use to controll an elevator built with all in one servo lab
 * Use goToFloor for main control of elevator
 * GoToGround will automaticly be  runned if 1. floor is selected
 * Use goSteps if small adjustements are to be made
 * 
 * This libary requires: Jmstepper, Elevatordoor, LCD, switc, arduino
 */

#ifndef elevator_h
#define elevator_h

#include "Arduino.h"
#include "jmstepper.h"
#include "elevatordoor.h"
#include "switch.h"
#include "lcd.h"

class Elevator{
  public:
    Elevator(int pinIn1, int pinIn2, int pinIn3, int pinIn4, int servoPin, Switch& switchObj);
    void goToFloor(int desiredFloor, Switch& switchObj, LCD& theScreen);
    void goSteps(int numOfSteps);
    void goToGround(Switch& switchObj, LCD& theScreen);
    int currentFloor;

  private:
    int stepsPerRevelution;
    int floorHeight;
    int heightPerRevelution;
    int mainMotorSpeed;
    int floorStepRatio;
    
    int calcNumStep(int floors);

    Jmstepper mainMotor_;
    ElevatorDoor eleDoor_;

};

#endif
