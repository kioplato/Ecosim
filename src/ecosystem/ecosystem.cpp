// File: ecosystem.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "ecosystem.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

Ecosystem::Ecosystem(size_t terrain_size)
	: terrain(terrain_size)
{ }

void Ecosystem::print_system() const {
	size_t terrain_size = terrain.get_size();
	for (size_t c_row = 0; c_row < terrain_size; c_row++) {
		for (size_t c_col = 0; c_col < terrain_size; c_col++)
			cout << terrain.get_habitat(c_row, c_col);
		cout << endl;
	}
}
