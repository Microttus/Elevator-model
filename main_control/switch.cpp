#include "switch.h"
#include "Arduino.h"

Switch::Switch(int pinIn1, int pinIn2, int pinIn3, int pinIn4, int pinIn5, int pinIn6, int pinIn7, int pinIn8, int pinIn9, int pinIn10)
: pinList {pinIn1, pinIn2, pinIn3, pinIn4, pinIn5, pinIn6, pinIn7, pinIn8, pinIn9, pinIn10}
, previousValue {0,0,0,0,0,0,0,0,0,0}
, switchPressed(0)
{

}

bool Switch::switchButtonPressed(int index){
  int switchValue = digitalRead(pinList[index]);
  if (switchValue == 0 & previousValue[index] == 1){
    previousValue[index] = switchValue;
    return 1;
  } 
  else {
    previousValue[index] = switchValue;
    return 0;
  }
}

bool Switch::whileButtonPressed(int index) {
  int switchValue = digitalRead(pinList[index]);
  return(switchValue);
}

bool Switch::switchCase(int index){
  bool bottonState = switchButtonPressed(index);
  if(bottonState == 1) {
    switchPressed = !switchPressed;
    return switchPressed;
  } 
  else {
    return switchPressed;
  }
}
