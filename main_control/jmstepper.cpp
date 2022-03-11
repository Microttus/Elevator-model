#include "Arduino.h"
#include "jmStepper.h"
#include "dac.h"

Jmstepper::Jmstepper(int numberRevolutionStep, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4)
: pin_1(motor_pin_1)
, pin_2(motor_pin_2)
, pin_3(motor_pin_3)
, pin_4(motor_pin_4)
, stepperDirection(0)
, step_per_revelution(numberRevolutionStep)
, step_number(0)
{
  pinMode(motor_pin_1,OUTPUT);
  pinMode(motor_pin_2,OUTPUT);
  pinMode(motor_pin_3,OUTPUT);
  pinMode(motor_pin_4,OUTPUT);

  
  dac_init();
  set_dac(4095 ,4095);
}


void Jmstepper::setSpeed(int whatSpeed){
  step_delay = 1000/((whatSpeed*step_per_revelution)/60);
}


void Jmstepper::step(int steps_to_move){
  int steps_left = abs(steps_to_move);
  
  if (steps_to_move > 0){
    stepperDirection = 0; // Positive
  } else if (steps_to_move < 0){
    stepperDirection = 1; // Negative
  }

  while (steps_left > 0){
    if (stepperDirection == 0){
      step_number++;
      if (step_number > 3){
        step_number = 0;
      }
    } else {
      step_number--;
      if (step_number < 0){
        step_number = 3;
      }
    }
    stepMotor(step_number);
    steps_left--;
    delay(step_delay);
  }
}


void Jmstepper::stepMotor(int step_sequence){
  switch (step_sequence){
    case 0:
      digitalWrite(pin_1, HIGH);
      digitalWrite(pin_2, HIGH);
      digitalWrite(pin_3, LOW);
      digitalWrite(pin_4, LOW);
    break;
    case 1:
      digitalWrite(pin_1, LOW);
      digitalWrite(pin_2, LOW);
      digitalWrite(pin_3, HIGH);
      digitalWrite(pin_4, HIGH);
    break;
    case 2:
      digitalWrite(pin_1, LOW);
      digitalWrite(pin_2, HIGH);
      digitalWrite(pin_3, HIGH);
      digitalWrite(pin_4, LOW);
    break;
    case 3:
      digitalWrite(pin_1, HIGH);
      digitalWrite(pin_2, LOW);
      digitalWrite(pin_3, LOW);
      digitalWrite(pin_4, HIGH);
    break;
  }
}


int Jmstepper::version(){
  return 0;
}
