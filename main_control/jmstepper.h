/*
 * jmstepper.h - Stepper library for Arduino - Version 0.0.1
 *
 * Original library        (0.1)   by Jorgen Borge, Martin Suar Wad and Martin Økter 
 *
 * Minimal libary for controlling a stepper, with basic controll for a four wire setup for the all in one servo lab
 * 
 * Use setSpeed('RPM') to afdjust the rpm of the stepper 
 * Use step() to rotate a number for steps clockvize and nagtive steps for conterclockvize
 * 
 * This lubary requires: dac, arduino
 */

// ensure this library description is only included once
#ifndef jmstepper_h
#define jmstepper_h

// library interface description
class Jmstepper {
  public:
    Jmstepper(int numberRevelutionStep, int motor_pin_1, int motor_pin_2, int motor_pin_3, int motor_pin_4);

    // Speed setter method in RPM
    void setSpeed(int whatSpeed);

    // Move single or multiple step:
    void step(int number_of_step);

    // For version controll
    int version();
    
  private:
    void stepMotor(int step_sequence);

    int pin_1;
    int pin_2;
    int pin_3;
    int pin_4;
    
    int stepperDirection;
    int step_per_revelution;
    int step_delay;
    int step_number;
    
};

#endif
