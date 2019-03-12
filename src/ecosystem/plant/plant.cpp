// File: plant.cpp

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "plant.hpp"
#include "../misc/habitat_masks.hpp"
#include "seedless/grass/grass.hpp"
#include "seedless/algae/algae.hpp"
#include "seeded/oak/oak.hpp"
#include "seeded/pine/pine.hpp"
#include "seeded/maple/maple.hpp"
/******************/

/* Namespace access */
using namespace std;
using namespace habitat_masks;
/********************/

Plant::Plant(string name, char token, size_t row, size_t col,
		size_t breeding_prob, size_t illness_prob,
		size_t life, size_t life_factor, size_t size)
		: name(name), token(token), row(row), col(col), breeding_prob(breeding_prob),
		illness_prob(illness_prob), life(life), life_factor(life_factor), size(size) { }

Plant::~Plant() { }

Terrain* Plant::terrain = NULL;

bool Plant::set_terrain(Terrain* terrain) {
	if (Plant::terrain != NULL) return false;
	if (Plant::terrain == NULL) Plant::terrain = terrain;
	return true;
}

size_t Plant::get_illness_prob() {
	return illness_prob;
}

size_t Plant::get_life_factor() {
	return life_factor;
}

void Plant::lose_life_life_factor() {
	if (life <= life_factor) life = 0;
	else life -= life_factor;
	if (life == 0) is_alive = false;
}

void Plant::incr_life_life_factor() {
	life += life_factor;
}

char Plant::get_token() {
	return token;
}

size_t Plant::lose_life(size_t amount) {
	size_t damaged_amount;
	if (amount >= life) {
		damaged_amount = life;
		life = 0;
		is_alive = false; }
	else {
		damaged_amount = amount;
		life -= amount; }
	return damaged_amount;
}

void Plant::breed() {
	if ((size_t)rand() % 100 >= breeding_prob) return;
	char direction;
	Plant *plant = NULL;
	if (name == "Grass") {
		direction = terrain->find_free_tile(row, col, MEADOW);
		if (direction == 0) return;
		size_t child_row = row, child_col = col;
		if (direction == 'W') child_col--;
		else if (direction == 'E') child_col++;
		else if (direction == 'S') child_row++;
		else if (direction == 'N') child_row--;
		plant = new Grass(child_row, child_col);
		terrain->add_plant(plant, child_row, child_col); }
	else if (name == "Algae") {
		direction = terrain->find_free_tile(row, col, WATER);
		if (direction == 0) return;
		size_t child_row = row, child_col = col;
		if (direction == 'W') child_col--;
		else if (direction == 'E') child_col++;
		else if (direction == 'S') child_row++;
		else if (direction == 'N') child_row--;
		plant = new Algae(child_row, child_col);
		terrain->add_plant(plant, child_row, child_col); }
	else if (name == "Oak") {
		direction = terrain->find_free_tile(row, col, MEADOW);
		if (direction == 0) return;
		size_t child_row = row, child_col = col;
		if (direction == 'W') child_col--;
		else if (direction == 'E') child_col++;
		else if (direction == 'S') child_row++;
		else if (direction == 'N') child_row--;
		plant = new Oak(child_row, child_col);
		terrain->add_plant(plant, child_row, child_col); }
	else if (name == "Pine") {
		direction = terrain->find_free_tile(row, col, MEADOW | HILL);
		if (direction == 0) return;
		size_t child_row = row, child_col = col;
		if (direction == 'W') child_col--;
		else if (direction == 'E') child_col++;
		else if (direction == 'S') child_row++;
		else if (direction == 'N') child_row--;
		plant = new Pine(child_row, child_col);
		terrain->add_plant(plant, child_row, child_col); }
	else if (name == "Maple") {
		direction = terrain->find_free_tile(row, col, MEADOW | HILL);
		if (direction == 0) return;
		size_t child_row = row, child_col = col;
		if (direction == 'W') child_col--;
		else if (direction == 'E') child_col++;
		else if (direction == 'S') child_row++;
		else if (direction == 'N') child_row--;
		plant = new Maple(child_row, child_col);
		terrain->add_plant(plant, child_row, child_col); }
	else { cerr << "In Plant::breed(): unknown class name." << endl; exit(5); }
}

size_t Plant::get_size() {
	return size;
}

bool Plant::get_is_alive() {
	return is_alive;
}
