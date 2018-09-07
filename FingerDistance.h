#ifndef FINGERDISTANCE_H_
#define FINGERDISTANCE_H_

#include <stdio.h>
#include <cmath>
#define PI 3.14159265358979323846

#define NUM_JOINTS 3
// ALL MEASUREMENTS IN MM { 0, 1, 2 ... }

// general measurements, not all used currently
const double AXEL_RADIUS = 1.5;
const double STR_RADIUS = 3;
const double SEG_DIST[] = { 24, 24, 20.3 };
const double TOTAL_JOINT_DIST = 13.9;
const double JOINT_DIST[] = { 5.9, 4, 4 };
const double JOINT_ANGLE[] = { 44.5, 33.7, 33.7 };

// distribution of length/angle changes to joints
const double WEIGHTED_DISTRIBUTION[] = { .333, .333, .333 };

double getFingerPosition(double encoderAngle, double x, double y, double z);
double getArcLength(double angle, double radius);
double* getBentJointAngle(double arcLength);
double getCoordAdjustment(double* jointAngle);

#endif