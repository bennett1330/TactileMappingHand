#include "SelectSetup.h"
#include <iostream>

int init_select()
{
	// SELECT PINS
	bcm2835_gpio_fsel(SELECT_01_PIN, BCM2835_GPIO_FSEL_OUTP);
	bcm2835_gpio_fsel(SELECT_02_PIN, BCM2835_GPIO_FSEL_OUTP);

	// TODO determine which mode should be 'default' and which signal it is
	bcm2835_gpio_write(SELECT_01_PIN, LOW);
	bcm2835_gpio_write(SELECT_02_PIN, LOW);
	return 0;
}

int set_select(int select)
{
	bcm2835_gpio_write(SELECT_01_PIN, select);
	bcm2835_gpio_write(SELECT_02_PIN, select);
	return 0;
}

int set_finger_mode()
{
	std::cout << "finger mode..." << std::endl;
	set_step_speed_helper(LOW, LOW);
	set_enable_x(LOW);
	set_enable_y(LOW);
	set_enable_z(LOW);
	set_select(LOW);
	return 0;
}

int set_3daxis_mode()
{
	std::cout << "axis mode..." << std::endl;
	set_enable_index(LOW);
	set_enable_middle(LOW);
	set_enable_ring(LOW);
	set_enable_pinky(LOW);
	set_select(HIGH);
	set_step_speed_eighth();
	return 0;
}