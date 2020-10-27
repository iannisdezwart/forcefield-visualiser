#include <bits/stdc++.h>
#include <thread>

#include "lib/png++-0.2.9/png.hpp"
#include "lib/linear_algebra.hpp"

#include "colour.hpp"
#include "mass.hpp"
#include "forces.hpp"
#include "rendering.hpp"
#include "motion.hpp"

using namespace std;

int main()
{
	// Store the current timestamp to measure the execution time

	auto start = chrono::high_resolution_clock::now();

	// Replace this function with what you want to render
	// Some example functions are written in `motion.hpp`

	motion::four_body();

	// Print the execution time

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);

	cout << "Total execution time: " << duration.count() << " ms\n";
}
