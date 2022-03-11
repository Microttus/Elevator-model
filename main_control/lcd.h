/*
 * Borge, Wad, Økter
 * 
 * Libary for updating an using the LCD screen for indicating the current floor of the elevator 
 * and for the observer which may call the elevator from the outside
 * 
 * Use updateFloor() for vizualization of different floor
 * Use updateFloorChooser for vizulaization of which floor the observer is situated
 * 
 * This libary requires: LiquidCrystal, arduino
 */

#ifndef lcd_h
#define lcd_h
#include "Arduino.h"
#include "LiquidCrystal.h"


class LCD
{
  public:
    LCD(int lcdPins[7]);
    void updateFloor(int Floor);
    void updateFloorChooser(int cFloor);
  private:
    LiquidCrystal screen_;
    int pwmPin;
    int currentFloor;
    int currentCFloor;
};

#endif 
