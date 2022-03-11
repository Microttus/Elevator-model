#include "Arduino.h"
#include "floorchooser.h"



FloorChooser::FloorChooser(int pin, int index1, int index2)
: pot_(pin)
, indDown(index1)
, indUp(index2)

{
    
}

int FloorChooser::updatePot(LCD& screenObj_, Switch& switchObj_){
    int potFloor = map(pot_.potRead(), 0, 1020, 1, 6);
    screenObj_.updateFloorChooser(potFloor);
    int down = switchObj_.switchButtonPressed(indDown);
    int up = switchObj_.switchButtonPressed(indUp);
    if(down == 1){
      return (-potFloor);
    }
    else if(up == 1){
      return (potFloor);
    }
    else{
      return (0);
    }
}
