// File: seeded.cpp

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "seeded.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

Seeded::Seeded(string name, char token, size_t row, size_t col,
		size_t breeding_prob, size_t illness_prob,
		size_t life_factor, size_t size,
		size_t seeds, size_t foliage)
		: Plant(name, token, row, col, breeding_prob, illness_prob,
				foliage, life_factor, size),
		foliage(foliage), seeds(seeds) { }

size_t Seeded::lose_life(size_t amount) {
	size_t damaged_amount = 0;
	while (seeds != 0 && amount != 0) {
		seeds--; amount--; damaged_amount++; }
	foliage -= (foliage >= amount) ? amount : foliage;
	damaged_amount += Plant::lose_life(amount);
	return damaged_amount;
}

void Seeded::grow() {
	size_t illness_prob = get_illness_prob();
	size_t life_factor = get_life_factor();
	size_t percent = rand() % 100;
	foliage += (percent < illness_prob) ? -life_factor : life_factor;
	seeds += (percent < illness_prob) ? -life_factor * 2 : life_factor * 2;
	size += (percent < illness_prob) ? -1 : 1;
}
