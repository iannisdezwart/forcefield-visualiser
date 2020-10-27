#ifndef LINEAR_ALGEBRA_HEADER
#define LINEAR_ALGEBRA_HEADER

#include <bits/stdc++.h>

using namespace std;

enum VectorErrors {
	WRONG_DIMENSION
};

template <int size, typename number_type = double>
class Vector {
	public:
		number_type values[size];

		Vector(initializer_list<number_type> initial_values = {})
		{
			if (initial_values.size() > 0) {
				if (initial_values.size() != size) throw WRONG_DIMENSION;
				copy(initial_values.begin(), initial_values.end(), values);
			} else {
				for (int i = 0; i < size; i++) {
					values[i] = 0;
				}
			}
		}

		// Get accessor

		number_type operator[](int index) const
		{
			return values[index];
		}

		// Set accessor

		number_type & operator[](int index)
		{
			return values[index];
		}

		Vector<size, number_type> each(function<number_type(number_type)> callback)
		{
			Vector<size, number_type> new_vector;

			for (int i = 0; i < size; i++) {
				new_vector.values[i] = callback(values[i]);
			}

			return new_vector;
		}

		Vector<size, number_type> operator+(Vector<size, number_type> other_vector)
		{
			Vector<size, number_type> new_vector;

			for (int i = 0; i < size; i++) {
				new_vector.values[i] = values[i] + other_vector.values[i];
			}

			return new_vector;
		}

		Vector<size, number_type> operator+=(Vector<size, number_type> other_vector)
		{
			for (int i = 0; i < size; i++) {
				values[i] += other_vector.values[i];
			}

			return *this;
		}

		Vector<size, number_type> operator-(Vector<size, number_type> other_vector)
		{
			Vector<size, number_type> new_vector;

			for (int i = 0; i < size; i++) {
				new_vector.values[i] = values[i] - other_vector.values[i];
			}

			return new_vector;
		}

		Vector<size, number_type> operator-=(Vector<size, number_type> other_vector)
		{
			for (int i = 0; i < size; i++) {
				values[i] -= other_vector.values[i];
			}

			return *this;
		}

		Vector<size, number_type> operator*(Vector<size, number_type> other_vector)
		{
			Vector<size, number_type> new_vector;

			for (int i = 0; i < size; i++) {
				new_vector.values[i] = values[i] * other_vector.values[i];
			}

			return new_vector;
		}

		Vector<size, number_type> operator*=(Vector<size, number_type> other_vector)
		{
			for (int i = 0; i < size; i++) {
				values[i] *= other_vector.values[i];
			}

			return *this;
		}

		Vector<size, number_type> operator*(number_type scalar)
		{
			Vector<size, number_type> new_vector;

			for (int i = 0; i < size; i++) {
				new_vector.values[i] = values[i] * scalar;
			}

			return new_vector;
		}

		Vector<size, number_type> operator*=(number_type scalar)
		{
			for (int i = 0; i < size; i++) {
				values[i] *= scalar;
			}

			return *this;
		}

		bool operator==(Vector<size, number_type> other_vector)
		{
			for (int i = 0; i < size; i++) {
				if (values[i] != other_vector.values[i]) return false;
			}

			return true;
		}

		string to_string()
		{
			string str = "[ ";

			for (int i = 0; i < size - 1; i++) {
				str += std::to_string(values[i]) + ", ";
			}

			str += std::to_string(values[size - 1]) + " ]";
			return str;
		}

		double length()
		{
			number_type square_sum = 0;

			for (int i = 0; i < size; i++) {
				square_sum += pow(values[i], 2);
			}

			return sqrt(square_sum);
		}

		double angle()
		{
			if (size != 2) throw WRONG_DIMENSION;

			return atan2((double) values[1], (double) values[0]);
		}

		static Vector<2> from_angle(double angle)
		{
			Vector<2> vector({ cos(angle), sin(angle) });
			return vector;
		}

};

#endif
