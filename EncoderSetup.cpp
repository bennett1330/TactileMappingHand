#include "EncoderSetup.h"

int state_count_index;
int state_count_middle;
int state_count_ring;
int state_count_pinky;

int state_count_index_max;
int state_count_middle_max;
int state_count_ring_max;
int state_count_pinky_max;

int state_value_index;
int state_value_middle;
int state_value_ring;
int state_value_pinky;

int init_encoders()
{
	bcm2835_gpio_fsel(ENCODER_INDEX_PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(ENCODER_MIDDLE_PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(ENCODER_RING_PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(ENCODER_PINKY_PIN, BCM2835_GPIO_FSEL_INPT);

	bcm2835_gpio_set_pud(ENCODER_INDEX_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(ENCODER_MIDDLE_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(ENCODER_RING_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(ENCODER_PINKY_PIN, BCM2835_GPIO_PUD_UP);

    return 0;
}

int clear_count_all()
{
	update_count_index();
	update_count_middle();
	update_count_ring();
	update_count_pinky();

	state_count_index = 0;
	state_count_middle = 0;
	state_count_ring = 0;
	state_count_pinky = 0;

	return 0;
}

int update_count_helper(int ENCODER_PIN, int DIR_PIN, int &flag_encoder, int &state_count)
{
	uint8_t value = bcm2835_gpio_lev(ENCODER_PIN);
	if (value != flag_encoder)
	{
		(bcm2835_gpio_lev(DIR_PIN) == HIGH) ? state_count-- : state_count++;
		//std::cout << "updated state count = " << state_count << std::endl;
		flag_encoder = value;
	}
	return 0;
}

int set_dc_min_helper(int &state_count)
{
	state_count = 0;
	//std::cout << "set state count = " << state_count << std::endl;
	return 0;
}

int set_dc_max_helper(int &state_count, int &state_count_max)
{
	state_count_max = state_count;
	//std::cout << "set max state count = " << state_count << std::endl;
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int update_count_index()
{
	return update_count_helper(ENCODER_INDEX_PIN, DIR_INDEX_X_PIN, state_value_index, state_count_index);
}

int update_count_middle()
{
	return update_count_helper(ENCODER_MIDDLE_PIN, DIR_MIDDLE_Y_PIN, state_value_middle, state_count_middle);
}

int update_count_ring()
{
	return update_count_helper(ENCODER_RING_PIN, DIR_RING_Z_PIN, state_value_ring, state_count_ring);
}

int update_count_pinky()
{
	return update_count_helper(ENCODER_PINKY_PIN, DIR_PINKY_MS_PIN, state_value_pinky, state_count_pinky);
}
