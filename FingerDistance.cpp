#include "FingerDistance.h"

double getFingerAdjustment(double encoderAngle, double x, double y, double z)
{
    double arcLength, *bentJointAngle, *coordAdjustment;

    arcLength = getArcLength(encoderAngle, STR_RADIUS);
    bentJointAngle = getBentJointAngle(arcLength);
    coordAdjustment = getCoordAdjustment(bentJointAngle);

    // TODO LOCK FILE
    // APPEND NEW POINT 

    return 0;
}

double getArcLength(double angle, double radius)
{
    return (PI/180) * angle * radius;
}

double* getBentJointAngle(double arcLength)
{
    double bentJointDist[NUM_JOINTS];
    double bentJointAngle[NUM_JOINTS];
    for (int i = 0; i < NUM_JOINTS; i++)
    {
        // bentJointDist[i] = JOINT_DIST[i] - (arcLength * WEIGHTED_DISTRIBUTION[i]);
        bentJointDist[i] = JOINT_DIST[i] - (arcLength * JOINT_DIST[i] / TOTAL_JOINT_DIST);
        bentJointAngle[i] = (180/PI) * atan2( bentJointDist[i] / 2, STR_RADIUS );
    }
    return bentJointAngle;
}

double getCoordAdjustment(double* jointAngle)
{
    // Fingers point in the +Y direction and imaginary 'thumb' pointing in the -X direction
    double coordAdjustment[3]; // [X, Y, Z] adjustments
    coordAdjustment[0] = 0; // X is uneffected by finger bend
    
    double angle_fromHorizontal[3];
    angle_fromHorizontal[0] = -jointAngle[0];
    angle_fromHorizontal[1] = angle_fromHorizontal[0] -jointAngle[1];
    angle_fromHorizontal[2] = angle_fromHorizontal[1] -jointAngle[2] -30; 
    // -30 degrees to adjust to estimated FSR position 
    
    coordAdjustment[1] = 0; // initialize Y and Z to 0, 0 (starting position)
    coordAdjustment[2] = 0;
    for (int i = 0; i < 3; i++)
    {
        coordAdjustment[1] = coordAdjustment[1] - SEG_DIST[i] * cos(angle_fromHorizontal[i]);
        coordAdjustment[2] = coordAdjustment[2] - SEG_DIST[i] * sin(angle_fromHorizontal[i]);
    }

    return coordAdjustment;
}