#include "Arduino.h"
#include "elevatordoor.h"


ElevatorDoor::ElevatorDoor(int servoPin)
: servoOpen(160.0)
, servoClosed(20.0)
, currentAngle(0.0)
, doorServoPin(servoPin)
, servoFlag(0)
{
  
}


float ElevatorDoor::angleCompfilter(float targetAngle, float lastAngle, float alpha){
  float calcAngle = (((1-alpha)*lastAngle)+(alpha*targetAngle));
  return calcAngle;  
}


void ElevatorDoor::servoBegin(){
  servoObj_.attach(doorServoPin);
  return;
}


void ElevatorDoor::openDoors(){
  if(servoFlag == 0){
    servoBegin();
  }
  while (currentAngle < (servoOpen - 0.5)){
    float servoAngle = angleCompfilter(servoOpen,currentAngle);
    servoObj_.write(servoAngle);
    currentAngle = servoAngle;
  }
  servoFlag = 1;
  return;
}


void ElevatorDoor::closeDoors(){
    while (currentAngle > (servoClosed + 0.5)){
    float servoAngle = angleCompfilter(servoClosed, currentAngle);
    servoObj_.write(servoAngle);
    currentAngle = servoAngle;
  }
  return;
}
