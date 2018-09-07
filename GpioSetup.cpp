#include "GpioSetup.h"


int init()
{
	return (bcm2835_init() ? 0 : 1);
}

int init(int debugFlag)
{
	// If you call this, it will not actually access the GPIO
    // Use for testing
	bcm2835_set_debug(debugFlag);
	return (bcm2835_init() ? 0 : 1);
}

int shutdown()
{

	// TODO do we even need this or will close() just set everything low?

	// TODO turn 'off' all outputs......... remember stepper motors are active HIGH
	// Write all outputs LOW prior to shutdown

	// if (bcm2835_gpio_lev(SELECT_01_PIN) == LOW)
	// { // SELECT_02_PIN also LOW

	// }
	// else
	// {

	// }

    bcm2835_close();
    return 0;
}