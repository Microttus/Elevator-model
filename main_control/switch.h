/*
 * Borge, Wad, Økter
 * 
 * A libary for managing a series of switches used to controll several aspect of the elevator.
 * 
 * Need the 10 pins to conect to as input on the constructor
 * 
 * All buttons are refered to as the index of the inputed list
 * Use SwitchButtonPressed for a TRUE when the button has been pressed and are released
 * Use whileButtonPressed for a TRUE as long as the button are pressed down
 * Use switchCase for a swtich between True/False is th button are presed and released again
 * 
 * This libay requires: arduino
 */

#ifndef switch_h
#define switch_h

#include "Arduino.h"

class Switch{
  public:
    Switch(int pinIn1, int pinIn2, int pinIn3, int pinIn4, int pinIn5, int pinIn6, int pinIn7, int pinIn8, int pinIn9, int pinIn10);
    bool switchButtonPressed(int index);
    bool whileButtonPressed(int index);
    bool switchCase(int index);

  private:
    int pinList[10];
    int previousValue[10];
    bool switchPressed; 

};

#endif
