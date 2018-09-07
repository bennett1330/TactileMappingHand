#ifndef STEPSETUP_H_
#define STEPSETUP_H_

#include <mutex>
#include <thread>
#include <chrono>

#include "GpioSetup.h"

extern std::mutex mtx_step;
extern int flag_step;

extern int step_count_x_max;
extern int step_count_y_max;
extern int step_count_z_max;

extern int step_count_x;
extern int step_count_y;
extern int step_count_z;

int start_step();
int stop_step();
int set_step_speed_helper(int MS1, int MS2);
int update_step_helper(int DIR_PIN, int EN_PIN, int &step_count);
int set_step_min_helper(int &step_count);
int set_step_max_helper(int &step_count, int &step_count_max);

///////////////////////////////////////////////////////////////////////////////

int set_step_speed_full();
int set_step_speed_half();
int set_step_speed_quarter();
int set_step_speed_eighth();

int update_step_x();
int update_step_y();
int update_step_z();

#endif