/*
 * Borge, Wad, Økter
 * 
 * A libary whitch handles the selection of the outher buttons by reading a potmeter and the two buttons to the left
 * and return the value nad the selected direction, it wil also update the LCD screen for vizualization
 * 
 * Use update pot to retrive data, need the object for the switches and for the LCD as paramenters
 * 
 * This libary requires: switch, LCD and pot, arduino
 * 
 */

#ifndef floorchooser_h
#define floorchooser_h
#include "Arduino.h"
#include "switch.h"
#include "lcd.h"
#include "potensiometer.h"



class FloorChooser
{
  public:
    FloorChooser(int pin, int index1, int index2);
    int updatePot(LCD& screenObj_, Switch& switchObj_); 
  private:
    Potensiometer pot_;
    int indDown;
    int indUp;

};

#endif 
