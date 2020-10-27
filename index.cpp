#include <bits/stdc++.h>
#include <thread>

#include "lib/png++-0.2.9/png.hpp"
#include "lib/linear_algebra.hpp"

#include "colour.hpp"
#include "mass.hpp"
#include "forces.hpp"
#include "rendering.hpp"

using namespace std;

// Set the desired rendering mode here (SINGLE_THREADED or MULTI_THREADED)

#define RENDERING_MODE MULTI_THREADED

int main()
{
	// Get the masses from stdin

	get_masses_from_user_input();

	// Store the current timestamp to measure the execution time

	auto start = chrono::high_resolution_clock::now();

	// Render the image

	render_image("output/1.png", RENDERING_MODE);

	// Print the execution time

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

	cout << "Total execution time: " << duration.count() << " ms\n";
}
