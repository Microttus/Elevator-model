#include "que.h"

Que::Que(int elevatorList[], int switchList[], int floorChooserList[], int lcdList[])
: Switchrow_(switchList[0],switchList[1],switchList[2],switchList[3],switchList[4],switchList[5],switchList[6],switchList[7],switchList[8],switchList[9])
, JmSkylift_(elevatorList[0],elevatorList[1],elevatorList[2],elevatorList[3],elevatorList[4],Switchrow_)
, Floorcaller_(floorChooserList[0],floorChooserList[1],floorChooserList[2])
, Mainscreen_(lcdList)
, floorQue {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
, floorDir {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
, queIndex(20)
{
  
}

void Que::mainSetup(){
  JmSkylift_.goToGround(Switchrow_, Mainscreen_);
}


void Que::mainLoop(){
  updateInputs();  
  nextFloor();
  return;
}


void Que::updateInputs(){
  for (int i = 0; i < 6; i++){
    bool isItPressed = Switchrow_.switchButtonPressed(i);
    if (isItPressed != 0){
      int currentFloor = JmSkylift_.currentFloor;
      int floorTravel = currentFloor - i++;
      if (i>currentFloor){
        addToQue(i++,0,1);
      } else if (i<currentFloor){
        addToQue(i++,1,1);
      }
    }
  }
  int buttonOutside = Floorcaller_.updatePot(Mainscreen_,Switchrow_);
  if (buttonOutside>0){
    addToQue(buttonOutside,1,0);
  } else if (buttonOutside<0){
    addToQue(abs(buttonOutside),0,0);
  }
  return;
}


void Que::addToQue(int thefloor, int direct, int importance){
  if (importance == 1){
    floorQue[queIndex] = thefloor;
    floorDir[queIndex] = direct;
  } else {
     for (int i = queIndex; i > 0; i--){
      floorQue[i] = floorQue[i - 1];
      floorDir[i] = floorDir[i - 1];
     }
     floorQue[0] = thefloor;
     floorDir[0] = direct;
  }
  queIndex++;
  return;
}


void Que::nextFloor(){
  if (queIndex > 0){
    int theNextFloor = floorQue[queIndex - 1];
    int theNextDirec = floorDir[queIndex - 1];
    if (queIndex > 1) {
      for (int i = queIndex - 1; i >= 0; i--) {
        if (floorDir[i] == theNextDirec) {
          if (((floorQue[i] > theNextFloor) && (floorQue[i] < JmSkylift_.currentFloor)) || ((floorQue[i] < theNextFloor) && (floorQue[i] < JmSkylift_.currentFloor))) {
            int theNextFloor = floorQue[i];
            int theNextDir = floorDir[i];
            for (int j = i; j < queIndex; j++) {
              floorQue[j] = floorQue[j + 1];
              floorDir[j] = floorDir[j + 1];
            }
            floorQue[queIndex - 1] = theNextFloor;
            floorDir[queIndex - 1] = theNextDirec;
          }
        }
      }
    }
    floorQue[queIndex - 1] = 0;
    floorDir[queIndex - 1] = 0;
    JmSkylift_.goToFloor(theNextFloor, Switchrow_, Mainscreen_);
    queIndex--;
  }
  return;
}
