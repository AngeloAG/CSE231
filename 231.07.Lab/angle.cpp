/***********************************************************************
 * Source File:
 *    ANGLE
 * Author:
 *    Br. Helfrich
 *    Jacob Mower
 *    Alberto Angelo Arellano Gaona
 * Summary:
 *    Everything we need to know about a direction
 ************************************************************************/

#include "angle.h"
#include <math.h>  // for floor()
#include <cassert>
using namespace std;

/************************************
 * GET OFFSET
 * Calculates how off an angle is from
 *             0 or 2PI.
 * Input:
 *   radians - The angle to calculate the offset from.
 * Output:
 *   the times you need to add or substract PI to be between 0 and 2PI.
 ************************************/
int calculateOffset(double radians)
{
   // We separated it because the compiler thinks we try to abs a double
   int offset = floor(radians / (M_PI * 2));
   return abs(offset);
}

/************************************
 * ANGLE : NORMALIZE
 * Changes the given angle in radians
 *         to be within 0 and 2PI
 * Input:
 *   radians - The angle to normalize.
 * Output:
 *   normalized radians.
 ************************************/
double Angle::normalize(double radians) const
{
   if (radians < 0.0)
      radians += (2.0 * M_PI) * calculateOffset(radians);


   if (radians > M_PI * 2.0)
      radians -= (2.0 * M_PI) * calculateOffset(radians);

   return radians;
}


