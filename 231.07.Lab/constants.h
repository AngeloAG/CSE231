#pragma once

const double FRAME_RATE = 30.0;
const int NUMBER_OF_STARS = 10000;
const double STARTING_HEIGHT = 42164000.0;
const double GRAVITY_AT_SEA = 9.80665;
const double EARTH_RADIUS = 6378000.0;
const double TIME_DIALATION = 24 * 60; //hours * minutes
const double TIME_PER_FRAME = TIME_DIALATION / FRAME_RATE;
const double SECONDS_PER_DAY = 86400.0;