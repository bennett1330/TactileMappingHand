#include "MotorSetup.h"

int init_motors()
{
	// SET STEP, DIR, & EN PINS AS OUTPUT
	bcm2835_gpio_fsel(STEP_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DIR_INDEX_X_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DIR_MIDDLE_Y_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DIR_RING_Z_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(DIR_PINKY_MS_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(EN_INDEX_X_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(EN_MIDDLE_Y_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(EN_RING_Z_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(EN_PINKY_MS_PIN, BCM2835_GPIO_FSEL_OUTP);

	// INITIALIZE STEP, DIR, & EN PIN LOW
	bcm2835_gpio_write(STEP_PIN, LOW);
	bcm2835_gpio_write(DIR_INDEX_X_PIN, LOW);
	bcm2835_gpio_write(DIR_MIDDLE_Y_PIN, LOW);
	bcm2835_gpio_write(DIR_RING_Z_PIN, LOW);
	bcm2835_gpio_write(DIR_PINKY_MS_PIN, LOW);
	bcm2835_gpio_write(EN_INDEX_X_PIN, LOW);
	bcm2835_gpio_write(EN_MIDDLE_Y_PIN, LOW);
	bcm2835_gpio_write(EN_RING_Z_PIN, LOW);
	bcm2835_gpio_write(EN_PINKY_MS_PIN, LOW);

    return 0;
}

///////////////////////////////////////////////////////////////////////////////

int set_direction_helper_dc(int DIR_PIN, int EN_PIN, int directionSignal)
{
	if (bcm2835_gpio_lev(DIR_PIN) == directionSignal)
		return 0;
	if (bcm2835_gpio_lev(EN_PIN) == LOW)
		bcm2835_gpio_write(DIR_PIN, directionSignal);
	else // motor is on 
	{
		bcm2835_gpio_write(EN_PIN, LOW);
		bcm2835_gpio_write(DIR_PIN, directionSignal);
		bcm2835_gpio_write(EN_PIN, HIGH);
	}
	return 0;
}

int set_direction_helper_stepper(int DIR_PIN, int EN_PIN, int directionSignal)
{
	if (bcm2835_gpio_lev(DIR_PIN) == directionSignal)
		return 0;
	if (bcm2835_gpio_lev(EN_PIN) == LOW)
		bcm2835_gpio_write(DIR_PIN, directionSignal);
	else // motor is on 
	{
		bcm2835_gpio_write(EN_PIN, LOW);
		bcm2835_gpio_write(DIR_PIN, directionSignal);
		bcm2835_gpio_write(EN_PIN, HIGH);
	}
	return 0;	
}

int set_enable_helper(int EN_PIN, int enableSignal)
{
	bcm2835_gpio_write(EN_PIN, enableSignal);
	return 0;
}

int set_motor_helper_dc(int DIR_PIN, int EN_PIN, int directionSignal, int enableSignal)
{
	int flag_direction = bcm2835_gpio_lev(DIR_PIN);
	int flag_enable = bcm2835_gpio_lev(EN_PIN);

	if (flag_direction == directionSignal && flag_enable == enableSignal)
		return 0;	
	if (flag_direction != directionSignal)
		set_direction_helper_dc(DIR_PIN, EN_PIN, directionSignal);
	if (flag_enable != enableSignal)
		set_enable_helper(EN_PIN, enableSignal);
	return 0;
}

int set_motor_helper_stepper(int DIR_PIN, int EN_PIN, int directionSignal, int enableSignal)
{
	int flag_direction = bcm2835_gpio_lev(DIR_PIN);
	int flag_enable = bcm2835_gpio_lev(EN_PIN);

	if (flag_direction == directionSignal && flag_enable == enableSignal)
		return 0;	
	if (flag_direction != directionSignal)
		set_direction_helper_stepper(DIR_PIN, EN_PIN, directionSignal);
	if (flag_enable != enableSignal)
		set_enable_helper(EN_PIN, enableSignal);
	return 0;
}


///////////////////////////////////////////////////////////////////////////////

int set_direction_index(int directionSignal)
{
	return set_direction_helper_dc(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, directionSignal);
}

int set_direction_middle(int directionSignal)
{
	return set_direction_helper_dc(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, directionSignal);
}

int set_direction_ring(int directionSignal)
{
	return set_direction_helper_dc(DIR_RING_Z_PIN, EN_RING_Z_PIN, directionSignal);
}

int set_direction_pinky(int directionSignal)
{
	return set_direction_helper_dc(DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, directionSignal);
}

int set_direction_x(int directionSignal)
{
	return set_direction_helper_stepper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, directionSignal);
}

int set_direction_y(int directionSignal)
{
	return set_direction_helper_stepper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, directionSignal);
}

int set_direction_z(int directionSignal)
{
	return set_direction_helper_stepper(DIR_RING_Z_PIN, EN_RING_Z_PIN, directionSignal);
}

///////////////////////////////////////////////////////////////////////////////

int set_enable_index(int enableSignal)
{
	return set_enable_helper(EN_INDEX_X_PIN, enableSignal);
}

int set_enable_middle(int enableSignal)
{
	return set_enable_helper(EN_MIDDLE_Y_PIN, enableSignal);
}

int set_enable_ring(int enableSignal)
{
	return set_enable_helper(EN_RING_Z_PIN, enableSignal);
}

int set_enable_pinky(int enableSignal)
{
	return set_enable_helper(EN_PINKY_MS_PIN, enableSignal);
}

int set_enable_x(int enableSignal)
{
	return set_enable_helper(EN_INDEX_X_PIN, enableSignal);
}

int set_enable_y(int enableSignal)
{
	return set_enable_helper(EN_MIDDLE_Y_PIN, enableSignal);
}

int set_enable_z(int enableSignal)
{
	return set_enable_helper(EN_RING_Z_PIN, enableSignal);
}

///////////////////////////////////////////////////////////////////////////////

int set_motor_index(int directionSignal, int enableSignal)
{
	return set_motor_helper_dc(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, directionSignal, enableSignal);
}

int set_motor_middle(int directionSignal, int enableSignal)
{
	return set_motor_helper_dc(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, directionSignal, enableSignal);
}

int set_motor_ring(int directionSignal, int enableSignal)
{
	return set_motor_helper_dc(DIR_RING_Z_PIN, EN_RING_Z_PIN, directionSignal, enableSignal);
}

int set_motor_pinky(int directionSignal, int enableSignal)
{
	return set_motor_helper_dc(DIR_PINKY_MS_PIN, EN_PINKY_MS_PIN, directionSignal, enableSignal);
}

int set_motor_x(int directionSignal, int enableSignal)
{
	return set_motor_helper_stepper(DIR_INDEX_X_PIN, EN_INDEX_X_PIN, directionSignal, enableSignal);
}

int set_motor_y(int directionSignal, int enableSignal)
{
	return set_motor_helper_stepper(DIR_MIDDLE_Y_PIN, EN_MIDDLE_Y_PIN, directionSignal, enableSignal);
}

int set_motor_z(int directionSignal, int enableSignal)
{
	return set_motor_helper_stepper(DIR_RING_Z_PIN, EN_RING_Z_PIN, directionSignal, enableSignal);
}