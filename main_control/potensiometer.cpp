#include "Arduino.h"
#include "potensiometer.h"

Potensiometer::Potensiometer(int pin)
: potPin(pin)
{
  pinMode(potPin, INPUT);
}

int Potensiometer::potRead(){
  int readValue = analogRead(potPin);
  return(readValue);
}
