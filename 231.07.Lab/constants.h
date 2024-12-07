/***********************************************************************
 * Header File:
 *    Constants
 * Author:
 *    Angelo Arellano
 *    Connor Hopkins
 *    Jacob Mower
 * Summary:
 *    All the constants for the program.
 ************************************************************************/

#pragma once

const double FRAME_RATE   = 30.0;
const int NUMBER_OF_STARS = 10000;
const double STARTING_HEIGHT_HUBBLE     = -42164000.0;
const double STARTING_HEIGHT_SPUTNIK_Y  = 21082000.0;
const double STARTING_HEIGHT_SPUTNIK_X  = -36515095.13;
const double STARTING_HEIGHT_STARLINK   = -13020000.0;
const double STARTING_HEIGHT_CREWDRAGON = 8000000.0;
const double GRAVITY_AT_SEA  = 9.80665;
const double EARTH_RADIUS    = 6378000.0;
const double TIME_DIALATION  = 24 * 60; // hours * minutes
const double TIME_PER_FRAME  = TIME_DIALATION / FRAME_RATE;
const double SECONDS_PER_DAY = 86400.0;
