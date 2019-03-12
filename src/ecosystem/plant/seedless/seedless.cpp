// File: seedless.cpp

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "seedless.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

Seedless::Seedless(string name, char token, size_t row, size_t col,
		size_t breeding_prob, size_t illness_prob,
		size_t life, size_t life_factor) : Plant(name, token, row, col,
			breeding_prob, illness_prob, life, life_factor, 1) { }

void Seedless::grow() {
	size_t percent = rand() % 100;
	if (percent < get_illness_prob())
		incr_life_life_factor();
	else
		lose_life_life_factor();
}
