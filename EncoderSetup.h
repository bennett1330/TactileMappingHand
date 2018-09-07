#ifndef ENCODERSETUP_H_
#define ENCODERSETUP_H_

#include "GpioSetup.h"
#include <iostream>

extern int state_count_index;
extern int state_count_middle;
extern int state_count_ring;
extern int state_count_pinky;

extern int state_count_index_max;
extern int state_count_middle_max;
extern int state_count_ring_max;
extern int state_count_pinky_max;

extern int state_value_index;
extern int state_value_middle;
extern int state_value_ring;
extern int state_value_pinky;

int init_encoders();
int reset_count_all();
int update_count_helper(int ENCODER_PIN, int DIR_PIN, int &state_value, int &state_count);
int set_dc_min_helper(int &state_count);
int set_dc_max_helper(int &state_count, int &state_count_max);

int update_count_index();
int update_count_middle();
int update_count_ring();
int update_count_pinky();

#endif
