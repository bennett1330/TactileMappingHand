#ifndef SELECTSETUP_H_
#define SELECTSETUP_H_

#include "MotorSetup.h"
#include "StepSetup.h"
#include "EncoderSetup.h"

int init_select();
int set_select(int select);

int set_finger_mode();
int set_3daxis_mode();

#endif