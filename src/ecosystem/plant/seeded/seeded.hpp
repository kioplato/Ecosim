// File: seeded.hpp

#ifndef SEEDED_HPP
#define SEEDED_HPP

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

class Seeded : public Plant {
	private:
		size_t foliage;
		size_t seeds;
	public:
		Seeded(string name, char token, size_t row, size_t col,
				size_t breeding_prob, size_t illness_prob,
				size_t life_factor, size_t size,
				size_t seeds, size_t foliage);
		size_t lose_life(size_t amount);
		void grow();
};

#endif
