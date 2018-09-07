#ifndef GPIOSETUP_H_
#define GPIOSETUP_H_

#include <iostream>
#include "bcm2835.h"

///////////////////////////////////////////////////////////////////////////////
/////////////////////////////// P  I  N  S ////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
#define SELECT_01_PIN RPI_V2_GPIO_P1_22
#define SELECT_02_PIN RPI_V2_GPIO_P1_29

#define STEP_PIN RPI_V2_GPIO_P1_12

#define DIR_INDEX_X_PIN RPI_V2_GPIO_P1_03
#define DIR_MIDDLE_Y_PIN RPI_V2_GPIO_P1_16
#define DIR_RING_Z_PIN RPI_V2_GPIO_P1_07
#define DIR_PINKY_MS_PIN RPI_V2_GPIO_P1_13

#define EN_INDEX_X_PIN RPI_V2_GPIO_P1_05
#define EN_MIDDLE_Y_PIN RPI_V2_GPIO_P1_18
#define EN_RING_Z_PIN RPI_V2_GPIO_P1_11
#define EN_PINKY_MS_PIN RPI_V2_GPIO_P1_15

#define ENCODER_INDEX_PIN RPI_V2_GPIO_P1_31
#define ENCODER_MIDDLE_PIN RPI_V2_GPIO_P1_33
#define ENCODER_RING_PIN RPI_V2_GPIO_P1_35
#define ENCODER_PINKY_PIN RPI_V2_GPIO_P1_37

#define FSR_INDEX_PIN RPI_V2_GPIO_P1_32
#define FSR_MIDDLE_PIN RPI_V2_GPIO_P1_36
#define FSR_RING_PIN RPI_V2_GPIO_P1_38
#define FSR_PINKY_PIN RPI_V2_GPIO_P1_40
///////////////////////////////////////////////////////////////////////////////

int init();
int init(int debugFlag);
int shutdown();

#endif