/*
 * Authors:
 * Jørgen Borge, Martin Sauar Wad and Martin Økter
 * 
 * Main test controll for elevation controll unit
 */

#include "que.h"

// Creating the list for setup spesificaly for the All in one servolab
int lcdPin[7] = {41,40,37,36,35,34,4}; // Pins connecet from arduino to LCD
int elevatorSettings[6] = {66,67,68,69,15}; // {pin 1-4 conctet to stepper Driver, servo pin}
int switchSettings[10] = {29,28,27,26,25,24,23,22,12,1}; // {switchrow 8-1, ground pin, potswitch pin}
int floorChooserSettings[3] = {0,7,6}; // {pot pin, index of button from switchrow 1 and 2}

// Creating the quing object
Que myController_(elevatorSettings,switchSettings,floorChooserSettings,lcdPin);

void setup() {
  // Start a terminal for debugging
  Serial.begin(9600);

  //Initalize the controller object
  myController_.mainSetup();
}

void loop() {
  // Run the main loop of the controller
  myController_.mainLoop();
}
