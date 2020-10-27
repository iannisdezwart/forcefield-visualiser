#ifndef COLOUR_HEADER
#define COLOUR_HEADER

#include <bits/stdc++.h>

#include "lib/png++-0.2.9/png.hpp"

using namespace std;

// This function converts a given angle in radians [-PI, PI]
// to a `png::rgb_pixel` with the correct hue.

png::rgb_pixel angle_to_rgb(double angle)
{
	// We convert the angle such that it becomes a number between 0 and 1.
	// Here, 0 means an angle of 0 radians, and 1 means an angle of 2 PI radians.

	double angle_ratio = (angle / M_PI) / 2; // [-0.5, 0.5]
	if (angle_ratio < 0) angle_ratio += 1; // [0, 1]

	// Now we multiply this `angle_ratio` by 6 and cast it to an int.
	// This will initialise `int angle_sector` to an integer between [0, 6].
	// The edge case `angle_sector == 6` will be handled by the switch below.

	int angle_sector = angle_ratio * 6; // [0, 6] (int)

	// We calculate how far the angle is from the `angle_sector` base.
	// We store this value into `int remaining_value` and multiply it by 255
	// to make it a pixel value.

	int remaining_value = ((angle_ratio * 6) - (double) angle_sector) * 255.0;

	// The switch will return the correct png::rgb_pixel

	switch (angle_sector) {
		case 0:
		default: // If the `angle_sector` is 6 (equivalent to 6 mod 6 == 0)
			return png::rgb_pixel(255, remaining_value, 0);
		case 1:
			return png::rgb_pixel(255 - remaining_value, 255, 0);
		case 2:
			return png::rgb_pixel(0, 255, remaining_value);
		case 3:
			return png::rgb_pixel(0, 255 - remaining_value, 255);
		case 4:
			return png::rgb_pixel(remaining_value, 0, 255);
		case 5:
			return png::rgb_pixel(255, 0, 255 - remaining_value);
	}
}

// This function converts a given `Vector<2> force`
// to a `png::rgb_pixel` with the correct hue.

png::rgb_pixel force_to_rgb(Vector<2> force)
{
	// Get the angle and the length of the vector

	double angle = force.angle();

	// Calculate the corresponding hue

	png::rgb_pixel pixel = angle_to_rgb(angle);

	// Calculate the normalised force

	double normalised_force = tanh(force.length() * 20.0);

	// Set the lightness

	int inverse_red = 255 - pixel.red;
	int inverse_green = 255 - pixel.green;
	int inverse_blue = 255 - pixel.blue;

	pixel.red += inverse_red * normalised_force * 0.85;
	pixel.green += inverse_green * normalised_force * 0.85;
	pixel.blue += inverse_blue * normalised_force * 0.85;

	return pixel;
}

#endif