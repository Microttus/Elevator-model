#include"elevator.h"
#include"jmstepper.h"
#include"switch.h"

Elevator::Elevator(int pinIn1, int pinIn2, int pinIn3, int pinIn4, int servoPin, Switch& switchObj)
: stepsPerRevelution(200)
, floorHeight(74)
, heightPerRevelution(8)
, mainMotorSpeed(100)
, mainMotor_(stepsPerRevelution,pinIn1,pinIn2,pinIn3,pinIn4)
, eleDoor_(servoPin)
, currentFloor(1)
, floorStepRatio((floorHeight/heightPerRevelution)*stepsPerRevelution)
{

}

void Elevator::goToFloor(int desiredFloor, Switch& switchObj, LCD& theScreen){
  /*
   * For movement based with floors as input
   * Positive for uppward motion, and negative for downward movement
   */
  eleDoor_.closeDoors();
  if (desiredFloor == 1){
    goToGround(switchObj, theScreen);
  } else {
    int numOfFloors = desiredFloor - currentFloor;
    //int numOfSteps = calcNumStep(numOfFloors);
    mainMotor_.setSpeed(mainMotorSpeed);
    if (numOfFloors != 0){
      for (int i = 1; i <= abs(numOfFloors); i++){
        int floorWithSign = numOfFloors/abs(numOfFloors);
        mainMotor_.step(floorWithSign * floorStepRatio);
        theScreen.updateFloor(currentFloor + (i*floorWithSign));
      }
       
    }
    currentFloor = desiredFloor;
    eleDoor_.openDoors();
  }
  return;
}


void Elevator::goSteps(int numOfSteps){
  /*
   * For movent od the stepper on step per step basis
   * Positive for clockvice and negative for counter clockvice
   */
  mainMotor_.setSpeed(mainMotorSpeed);
  mainMotor_.step(numOfSteps);
  return;
}


int Elevator::calcNumStep(int floors){
  /*
   * For calcualton of steps form floors
   */
  int numOfSteps = ((floors*floorHeight)/heightPerRevelution)*stepsPerRevelution;
  
  return numOfSteps;
}


void Elevator::goToGround(Switch& switchObj, LCD& theScreen){
  /*
   * For moving the elevator to first floor
   * By detecting touching grond floor, stepper are zeroed
   */
  int counter = 0;
  bool presedSwitch = switchObj.whileButtonPressed(8);
  while (presedSwitch == 0){
    goSteps(-1); 
    presedSwitch = switchObj.whileButtonPressed(8);
    counter ++;
    if (counter >= floorStepRatio){
      theScreen.updateFloor(currentFloor--);
      counter = 0;
    }
  }
  int currentFloor = 1;
  theScreen.updateFloor(currentFloor);
  eleDoor_.openDoors();
  return;
}
