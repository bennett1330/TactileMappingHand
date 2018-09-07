#ifndef MEASUREMENTCONFIG_H_
#define MEASUREMENTCONFIG_H_

#include <iostream>
#include <thread>
#include <chrono>

#include "MotorSetup.h"
#include "EncoderSetup.h"
#include "FsrSetup.h"
#include "DcConfig.h"

int move_finger_helper(int FSR_PIN, int ENCODER_PIN, int DIR_PIN, int EN_PIN, 
	int &state_value, int &state_count, int state_count_max, int &fsr_flag);

///////////////////////////////////////////////////////////////////////////////

int move_finger_index();
int move_finger_middle();
int move_finger_ring();
int move_finger_pinky();

#endif