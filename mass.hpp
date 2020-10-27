#ifndef MASS_HEADER
#define MASS_HEADER

#include <bits/stdc++.h>

#include "lib/linear_algebra.hpp"

using namespace std;

// This class holds the `Vector<2> position` and the `int weight` of a mass

class Mass {
	public:
		Vector<2> position;
		int weight;

		Mass(int x, int y, int weight)
		{
			this->position[0] = x;
			this->position[1] = y;
			this->weight = weight;
		}
};

// Store the masses in a dynamic array

vector<Mass> masses;

// This function will take user input of the masses from stdin

void get_masses_from_user_input()
{
	int number_of_masses;
	cin >> number_of_masses;

	for (int i = 0; i < number_of_masses; i++) {
		int x, y, weight;
		cin >> x >> y >> weight;

		Mass mass(x, y, weight);
		masses.push_back(mass);
	}
}

#endif