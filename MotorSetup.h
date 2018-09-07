#ifndef MOTORSETUP_H_
#define MOTORSETUP_H_

#include "GpioSetup.h"

int init_motors();
int set_direction_helper_dc(int DIR_PIN, int EN_PIN, int directionSignal);
int set_direction_helper_stepper(int DIR_PIN, int EN_PIN, int directionSignal);
int set_enable_helper(int EN_PIN, int enableSignal);
int set_motor_helper_dc(int DIR_PIN, int EN_PIN, int directionSignal, int enableSignal);
int set_motor_helper_stepper(int DIR_PIN, int EN_PIN, int directionSignal, int enableSignal);

///////////////////////////////////////////////////////////////////////////////

int set_direction_index(int directionSignal);
int set_direction_middle(int directionSignal);
int set_direction_ring(int directionSignal);
int set_direction_pinky(int directionSignal);
int set_direction_x(int directionSignal);
int set_direction_y(int directionSignal);
int set_direction_z(int directionSignal);

int set_enable_index(int enableSignal);
int set_enable_middle(int enableSignal);
int set_enable_ring(int enableSignal);
int set_enable_pinky(int enableSignal);
int set_enable_x(int enableSignal);
int set_enable_y(int enableSignal);
int set_enable_z(int enableSignal);

int set_motor_index(int directionSignal, int enableSignal);
int set_motor_middle(int directionSignal, int enableSignal);
int set_motor_ring(int directionSignal, int enableSignal);
int set_motor_pinky(int directionSignal, int enableSignal);
int set_motor_x(int directionSignal, int enableSignal);
int set_motor_y(int directionSignal, int enableSignal);
int set_motor_z(int directionSignal, int enableSignal);

#endif