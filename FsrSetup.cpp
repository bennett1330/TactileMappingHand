#include "FsrSetup.h"

int fsr_index;
int fsr_middle;
int fsr_ring;
int fsr_pinky;

int init_fsrs()
{
	bcm2835_gpio_fsel(FSR_INDEX_PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(FSR_MIDDLE_PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(FSR_RING_PIN, BCM2835_GPIO_FSEL_INPT);
	bcm2835_gpio_fsel(FSR_PINKY_PIN, BCM2835_GPIO_FSEL_INPT);

	bcm2835_gpio_set_pud(FSR_INDEX_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(FSR_MIDDLE_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(FSR_RING_PIN, BCM2835_GPIO_PUD_UP);
	bcm2835_gpio_set_pud(FSR_PINKY_PIN, BCM2835_GPIO_PUD_UP);

    fsr_index = HIGH;
    fsr_middle = HIGH;
    fsr_ring = HIGH;
    fsr_pinky = HIGH;

    return 0;
}

int read_fsr_helper(int PIN, int &flag)
{
	flag = (bcm2835_gpio_lev(PIN) == 0 ? LOW : HIGH);
	return 0;
}

///////////////////////////////////////////////////////////////////////////////

int read_fsr_index()
{
	return read_fsr_helper(FSR_INDEX_PIN, fsr_index);
}

int read_fsr_middle()
{
	return read_fsr_helper(FSR_MIDDLE_PIN, fsr_middle);
}

int read_fsr_ring()
{
	return read_fsr_helper(FSR_RING_PIN, fsr_ring);
}

int read_fsr_pinky()
{
	return read_fsr_helper(FSR_PINKY_PIN, fsr_pinky);
}