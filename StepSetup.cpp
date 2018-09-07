#include "StepSetup.h"

std::mutex mtx_step;
int flag_step;

int step_count_x_max;
int step_count_y_max;
int step_count_z_max;

//std::mutex mtx_step_count;
int step_count_x;
int step_count_y;
int step_count_z;

int start_step()
{
	mtx_step.lock();
	flag_step = 1;
	mtx_step.unlock();
	while(true)
	{
	    bcm2835_gpio_write(STEP_PIN, HIGH); //Trigger one step forward
    	std::this_thread::sleep_for(std::chrono:: milliseconds(1));
    	bcm2835_gpio_write(STEP_PIN, LOW); //Reset trigger
    	std::this_thread::sleep_for(std::chrono:: milliseconds(1));
    	
    	update_step_x();
    	update_step_y();
    	update_step_z();
    	
    	mtx_step.lock();
    	if (flag_step == 0) break;
    	mtx_step.unlock();
	}
	return 0;
}

int stop_step()
{
    flag_step = 0;
}

int set_step_speed_helper(int MS1, int MS2)
{
	bcm2835_gpio_write(DIR_PINKY_MS_PIN, MS1);
	bcm2835_gpio_write(EN_PINKY_MS_PIN, MS2);
	return 0;
}

int update_step_helper(int DIR_PIN, int EN_PIN, int &step_count)
{
	if (bcm2835_gpio_lev(EN_PIN) == HIGH) // NEMAS ARE ACTIVE LOW but not-ed
	{
		(bcm2835_gpio_lev(DIR_PIN) == LOW) ? step_count-- : step_count++;
	}
	return 0;
}

int set_step_min_helper(int &step_count)
{
	step_count = 0;
	return 0;
}

int set_step_max_helper(int &step_count, int &step_count_max)
{
	step_count_max = step_count;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int set_step_speed_full()
{
	return set_step_speed_helper(LOW, LOW);
}

int set_step_speed_half()
{
	return set_step_speed_helper(HIGH, LOW);
}

int set_step_speed_quarter()
{
	return set_step_speed_helper(LOW, HIGH);
}

int set_step_speed_eighth()
{
	return set_step_speed_helper(HIGH, HIGH);
}

///////////////////////////////////////////////////////////////////////////////

int update_step_x()
{
	return update_step_helper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, step_count_x);
}

int update_step_y()
{
	return update_step_helper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, step_count_y);
}

int update_step_z()
{
	return update_step_helper(DIR_RING_Z_PIN, EN_RING_Z_PIN, step_count_z);
}