#ifndef DCCONFIG_H_
#define DCCONFIG_H_

#include <iostream>
#include <chrono>

#include "SelectSetup.h"
#include "EncoderSetup.h"

int config_min_helper_dc_precheck(int &state_count, char id);
int config_min_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, char id);
int config_max_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, int &state_count_max, char id);

int move_start_position_helper_dc(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count);
int measure_position_helper(int ENCODER_PIN, int DIR_PIN, int EN_PIN, int &state_value, int &state_count, int state_count_max);

///////////////////////////////////////////////////////////////////////////////

int config_min_index();
int config_min_middle();
int config_min_ring();
int config_min_pinky();

int config_max_index();
int config_max_middle();
int config_max_ring();
int config_max_pinky();

///////////////////////////////////////////////////////////////////////////////

int move_start_position_index();
int move_start_position_middle();
int move_start_position_ring();
int move_start_position_pinky();

int measure_position_index();
int measure_position_middle();
int measure_position_ring();
int measure_position_pinky();

#endif
