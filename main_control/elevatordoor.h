/*
 * Borge, Wad, Økter
 * 
 * A libary for controlling the doors of the elevator with a servo
 * 
 * This will use servoBegin autamaticly when first retiruved
 * 
 * Use openDoors() to open the doors, and closeDoorst to close
 * The limit angles are set in initializer list and mey be changeched if needet to adjust the design
 * Uses an compfliter to make the doors smootly close and makes is possible to interrupt the closing of the door if the same floor buttom is pressed.
 * 
 * This libary requires: Servo libary, arduino
 * 
 */

#ifndef elevatordoor_h
#define elevatordoor_h

#include "Arduino.h"
#include "Servo.h"


class ElevatorDoor{
  public:
    ElevatorDoor(int servoPin);
    void openDoors();
    void closeDoors();
 
  private:
    float servoOpen;
    float servoClosed;
    float currentAngle;
    bool servoFlag;
    int doorServoPin;

    float angleCompfilter(float targetAngle, float lastAngle, float alpha = 0.002);
    void servoBegin();

    Servo servoObj_;    
};

#endif
