/*
 * Borge, Wad, Økter
 * 
 * A short libary for reading the potetiometer 
 * 
 * Use potRead() for returning the value of the potenitometer
 * 
 * This liabry requires: arduino
 */

#ifndef Potensiometer_h
#define Potensiometer_h

#include "Arduino.h"

class Potensiometer
{
  public:
    Potensiometer(int pin);
    int potRead();
  private:
    int potPin;
};

#endif 
