// File: seedless.hpp

#ifndef SEEDLESS_HPP
#define SEEDLESS_HPP

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "../plant.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

class Seedless : public Plant {
	public:
		Seedless(string name, char token, size_t row, size_t col,
				size_t breeding_prob, size_t illness_prob,
				size_t life, size_t life_factor);
		void grow();
};

#endif
