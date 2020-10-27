#ifndef FORCES_HEADER
#define FORCES_HEADER

#include <bits/stdc++.h>

#include "lib/linear_algebra.hpp"

#include "mass.hpp"

using namespace std;

// Tell the compiler that `vector<Mass> masses` is defined in `mass.hpp`

extern vector<Mass> masses;

// This function calculates the resulting force.
// `Vector<2> pixel_position` is the position where this function will
// calculate the resulting force.

Vector<2> calculate_resulting_force(Vector<2> pixel_position)
{
	Vector<2> resulting_force;

	// For each mass ...

	for (int i = 0; i < masses.size(); i++) {
		// ... we calculate the vector from the pixel to the mass ...

		Vector<2> pixel_to_mass = masses[i].position - pixel_position;

		// ... and we calculate the angle and the inverse distance of this vector ...

		double angle = pixel_to_mass.angle();
		double inverse_distance = masses[i].weight / pixel_to_mass.length();

		// ... with these we construct a normalised `Vector<2> force_vector`,
		// which we multiply by the scalar `double inverse_distance` ...

		Vector<2> force_vector = Vector<2>::from_angle(angle) * inverse_distance;

		// ... and add the current `force_vector` to the `resulting_force`.

		resulting_force += force_vector;
	}

	return resulting_force;
}

#endif