#ifndef STEPPERCONFIG_H_
#define STEPPERCONFIG_H_

// X-AXIS : 172 steps = 6 cm
// Y-AXIS : 58 steps = 2 cm
// Z-AXIS : 3150 steps = 2 cm
#define STEP_RESOLUTION_X (172*8)
#define STEP_RESOLUTION_Y (58*8)
#define STEP_RESOLUTION_Z (3150*8)

#include <iostream>

#include "SelectSetup.h"

int config_min_helper_stepper_precheck(int &step_count, char id);
int config_min_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count, char id);
int config_max_helper_stepper(int DIR_PIN, int EN_PIN, int &step_count, int &step_count_max, char id);

int move_start_position_helper_stepper(int DIR_PIN, int EN_PIN, int &state_count);
int next_position_helper_stepper(int DIR_PIN, int EN_PIN, int step_count, int step_count_max);

///////////////////////////////////////////////////////////////////////////////

int config_min_x();
int config_min_y();
int config_min_z();

int config_max_x();
int config_max_y();
int config_max_z();

///////////////////////////////////////////////////////////////////////////////

int move_start_position_x();
int move_start_position_y();
int move_start_position_z();

int next_position_x();
int next_position_y();
int next_position_z();

#endif