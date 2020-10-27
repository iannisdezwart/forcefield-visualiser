#ifndef MOTION_HEADER
#define MOTION_HEADER

#include <bits/stdc++.h>

#include "mass.hpp"
#include "rendering.hpp"

using namespace std;

// Tell the compiler that `vector<Mass> masses` is defined in `mass.hpp`

extern vector<Mass> masses;

// Put your animations in this namespace. Call them from index.cpp

namespace motion {
	void circular()
	{
		// The fixed mass in the middle

		masses.push_back(Mass(WIDTH / 2, HEIGHT / 2, 1));

		// The moving mass

		Mass moving_mass(300, 0, 1);
		masses.push_back(moving_mass);

		// Set the rotation

		double rotation = 0.01 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix({
			{ cos(rotation), -sin(rotation) },
			{ sin(rotation), cos(rotation) },
		});

		// Render 100 frames

		for (int i = 0; i < 100; i++) {
			string frame_number = to_string(i);

			if (frame_number.length() != 4) {
				frame_number = string(4 - frame_number.length(), '0') + frame_number;
			}

			// Move the moving mass

			moving_mass.position = rotation_matrix * moving_mass.position;

			// Set the moving mass in the image

			masses[1].position = masses[0].position + moving_mass.position;

			render_image("output/" + frame_number + ".png", MULTI_THREADED);

			cout << "Rendered frame " << i << "/" << "100\n";
		}
	}

	void three_body()
	{
		// The center of the image

		Vector<2> image_centre({ WIDTH / 2, HEIGHT / 2 });

		// Set the planets and their rotation vectors

		// Planet 1

		Mass planet_1(200, 0, 3);
		masses.push_back(planet_1);

		double rotation_1 = 0.003333 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_1({
			{ cos(rotation_1), -sin(rotation_1) },
			{ sin(rotation_1), cos(rotation_1) },
		});

		// Planet 2

		Mass planet_2(-150, 261, 2);
		masses.push_back(planet_2);

		double rotation_2 = 0.006666 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_2({
			{ cos(rotation_2), -sin(rotation_2) },
			{ sin(rotation_2), cos(rotation_2) },
		});

		// Planet 3

		Mass planet_3(-200, 348, 1);
		masses.push_back(planet_3);

		double rotation_3 = 0.01 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_3({
			{ cos(rotation_3), -sin(rotation_3) },
			{ sin(rotation_3), cos(rotation_3) },
		});

		// Render 300 frames

		for (int i = 0; i < 300; i++) {
			string frame_number = to_string(i);

			if (frame_number.length() != 4) {
				frame_number = string(4 - frame_number.length(), '0') + frame_number;
			}

			// Move the planets

			// Planet 1

			planet_1.position = rotation_matrix_1 * planet_1.position;
			masses[0].position = planet_1.position + image_centre;

			// Planet 2

			planet_2.position = rotation_matrix_2 * planet_2.position;
			masses[1].position = planet_2.position + image_centre;

			// Planet 3

			planet_3.position = rotation_matrix_3 * planet_3.position;
			masses[2].position = planet_3.position + image_centre;

			// Render the frame

			render_image("output/" + frame_number + ".png", MULTI_THREADED);

			cout << "Rendered frame " << i << "/" << "300\n";
		}
	}

	void four_body()
	{
		// The center of the image

		Vector<2> image_centre({ WIDTH / 2, HEIGHT / 2 });

		// Set the planets and their rotation vectors

		// Planet 1

		Mass planet_1(200, 0, 4);
		masses.push_back(planet_1);

		double rotation_1 = 0.000625 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_1({
			{ cos(rotation_1), -sin(rotation_1) },
			{ sin(rotation_1), cos(rotation_1) },
		});

		// Planet 2

		Mass planet_2(0, 300, 3);
		masses.push_back(planet_2);

		double rotation_2 = 0.00125 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_2({
			{ cos(rotation_2), -sin(rotation_2) },
			{ sin(rotation_2), cos(rotation_2) },
		});

		// Planet 3

		Mass planet_3(-400, 0, 2);
		masses.push_back(planet_3);

		double rotation_3 = 0.001875 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_3({
			{ cos(rotation_3), -sin(rotation_3) },
			{ sin(rotation_3), cos(rotation_3) },
		});

		// Planet 4

		Mass planet_4(0, -500, 1);
		masses.push_back(planet_4);

		double rotation_4 = 0.0025 * 2 * M_PI;

		Matrix<2, 2> rotation_matrix_4({
			{ cos(rotation_4), -sin(rotation_4) },
			{ sin(rotation_4), cos(rotation_4) },
		});

		// Render 1600 frames

		for (int i = 0; i < 1600; i++) {
			string frame_number = to_string(i);

			if (frame_number.length() != 4) {
				frame_number = string(4 - frame_number.length(), '0') + frame_number;
			}

			// Move the planets

			// Planet 1

			planet_1.position = rotation_matrix_1 * planet_1.position;
			masses[0].position = planet_1.position + image_centre;

			// Planet 2

			planet_2.position = rotation_matrix_2 * planet_2.position;
			masses[1].position = planet_2.position + image_centre;

			// Planet 3

			planet_3.position = rotation_matrix_3 * planet_3.position;
			masses[2].position = planet_3.position + image_centre;

			// Planet 4

			planet_4.position = rotation_matrix_4 * planet_4.position;
			masses[3].position = planet_4.position + image_centre;

			// Render the frame

			render_image("output/" + frame_number + ".png", MULTI_THREADED);

			cout << "Rendered frame " << i << "/" << "1600\n";
		}
	}

	void render_image_from_user_input()
	{
		// Get the masses from stdin

		get_masses_from_user_input();

		// Render the image

		render_image("output/1.png", MULTI_THREADED);
	}
}

#endif