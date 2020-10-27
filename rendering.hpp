#ifndef RENDERING_HEADER
#define RENDERING_HEADER

#include <bits/stdc++.h>

#include "lib/png++-0.2.9/png.hpp"
#include "lib/linear_algebra.hpp"

#include "forces.hpp"
#include "colour.hpp"

// Rendering constants

#define WIDTH 1920
#define HEIGHT 1080
const int number_of_threads = thread::hardware_concurrency();

// Create the image

png::image<png::rgb_pixel> image(WIDTH, HEIGHT);

using namespace std;

// Render each pixel

void render_pixel(Vector<2> pixel_position)
{
	// Calculate the angle of the resulting force at this position ...

	Vector<2> resulting_force = calculate_resulting_force(pixel_position);
	double angle = resulting_force.angle();

	// ... and set the pixel in the image to the corresponding hue

	image[pixel_position[1]][pixel_position[0]] = angle_to_rgb(angle);
}

// Render the rows
// `int start_row` is the starting row index
// `int increment` is the increment between the rows

void render_rows(int start_row, int increment)
{
	// Render each pixel of the given rows

	Vector<2> current_position;

	// Start `int y` at the `start_row` and increment it by `increment` each time

	for (int y = start_row; y < HEIGHT; y += increment) {
		current_position[1] = y;

		for (int x = 0; x < WIDTH; x++) {
			current_position[0] = x;

			// Render the current pixel

			render_pixel(current_position);
		}
	}
}

enum RenderingMode { SINGLE_THREADED, MULTI_THREADED };

// This function will render an image given a `string file_name` and
// the `RenderingMode rendering_mode` (SINGLE_THREADED or MULTI_THREADED)

void render_image(string file_name, RenderingMode rendering_mode)
{
	// If we're doing multithreading ...

	if (rendering_mode == MULTI_THREADED) {
		// ... store the threads in an array, ...

		thread thread_pool[number_of_threads];

		// ... start each thread ...

		for (int i = 0; i < number_of_threads; i++) {
			thread_pool[i] = thread(render_rows, i, number_of_threads);
		}

		// ... and wait until all threads finished.

		for (int i = 0; i < number_of_threads; i++) {
			thread_pool[i].join();
		}
	} else {
		// Else, let the main thread render the whole image

		render_rows(0, 1);
	}

	// Write the image

	image.write(file_name);
}

#endif