#ifndef FSRSETUP_H_
#define FSRSETUP_H_

#include "GpioSetup.h"

extern int fsr_index;
extern int fsr_middle;
extern int fsr_ring;
extern int fsr_pinky;

int init_fsrs();
int read_fsr_helper(int PIN, int &flag);

///////////////////////////////////////////////////////////////////////////////

int read_fsr_index();
int read_fsr_middle();
int read_fsr_ring();
int read_fsr_pinky();

#endif