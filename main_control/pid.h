/*
 * Author:
 * Borge, Wad, Økter
 * 
 * A short libary for impolimenting a PID controller into the system 
 * 
 * Initialize the PID with the wanted Kp, Ki and Kd values for the wanted PID
 * Use calculate(current value, desired value) to calculate the next step for the controller 
 * 
 * The libary will handle last values and time keeping by itself
 * 
 * This liabry requires: arduino
 */

#ifndef PID_h
#define PID_h

#include "Arduino.h"

class PID
{
  public:
    PID(float Kp_in, float Ki_in, float Kd_in);
    float calculate(float value, float target);
  
  private:
    float Kp;
    float Ki;
    float Kd;
    float last_val;
    float last_i_val;
    unsigned long my_time;
    unsigned long dt;
    
};

#endif 
