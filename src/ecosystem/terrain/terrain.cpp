// File: terrain.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "terrain.hpp"
#include "../misc/habitat_masks.hpp"
#include "../plant/seedless/grass/grass.hpp"
#include "../plant/seedless/algae/algae.hpp"
#include "../plant/seeded/oak/oak.hpp"
#include "../plant/seeded/pine/pine.hpp"
#include "../plant/seeded/maple/maple.hpp"
/******************/

/* Namespace access */
using namespace std;
using namespace habitat_masks;
/********************/

Terrain::Terrain(size_t terrain_size)
	: tiles(NULL), terrain_size(terrain_size) {
	if (terrain_size < 10) throw "Terrain size must be at least 10.";
	terrain_generator();
}

Terrain::~Terrain() {
	for (size_t c_row = 0; c_row < terrain_size; c_row++)
		delete[] tiles[c_row];
	delete[] tiles;
}

void Terrain::terrain_generator() {
	tiles = new Tile *[terrain_size];
	for (size_t c_row = 0; c_row < terrain_size; c_row++)
		tiles[c_row] = new Tile[terrain_size];
	generate_river();
	generate_lake();
	generate_hills();
	generate_meadow();
	place_plants(1, 1, 1, 1, 1);
}

void Terrain::generate_river() {
	// River can start from [5, terrain_size - 5]
	size_t possible_points = terrain_size - 9;
	size_t start_point = (rand() % possible_points) + 5;
	tiles[0][start_point].set_habitat('#');
	size_t current_point = start_point;
	for (size_t c_row = 1; c_row < terrain_size; c_row++) {
		tiles[c_row][current_point].set_habitat('#');
		bool deviate = (rand() % 10 < 3) ? true : false;
		if (deviate) {
			bool to_right = rand() % 2;
			bool twice = rand() % 2;
			if (to_right) {
				if (current_point + 1 >= terrain_size - 2) continue;
				tiles[c_row][current_point + 1].set_habitat('#');
				current_point ++;
				if (twice) {
					if (current_point + 1 >= terrain_size - 2) continue;
					tiles[c_row][current_point + 1].set_habitat('#'); }
				current_point += (twice) ? 1 : 0;
			} else {
				if (current_point - 3 > terrain_size) continue;
				tiles[c_row][current_point - 1].set_habitat('#');
				current_point--;
				if (twice) {
					if (current_point - 3 > terrain_size) continue;
					tiles[c_row][current_point - 1].set_habitat('#'); }
				current_point += (twice) ? -1 : 0;
			}
		}
	}
}

void Terrain::generate_lake() {
	size_t lake_size = terrain_size / 4;
	// The lake will have 1 tile from each side of the grid (-1 * 2).
	// The lake will cover lake_size tiles from the starting point (lake_size - 1).
	size_t possible_starts = terrain_size - 1 - 1 - (lake_size - 1);
	// +1 to separate the start_row from the edge of the grid - to add margin.
	size_t start_row = (rand() % possible_starts) + 1;
	size_t start_col = (rand() % possible_starts) + 1;
	for (size_t c_row = start_row; c_row < lake_size + start_row; c_row++)
		for (size_t c_col = start_col; c_col < lake_size + start_col; c_col++)
			tiles[c_row][c_col].set_habitat('#');
}

/* TODO: Implement a function that takes starting point and ending point and fills it with hills.
 * Also checks if the ending point is out of the grid's size. If there is water or other habitat
 * then it just ignores it, does not overwrite it, and continues to place hills. (Using nested fors) */
void generate_2x2_hill(size_t point_x, size_t point_y, Tile **tiles) {
	if (tiles[point_x][point_y].has_habitat() == false)
		tiles[point_x][point_y].set_habitat('^');
	if (tiles[point_x + 1][point_y].has_habitat() == false)
		tiles[point_x + 1][point_y].set_habitat('^');
	if (tiles[point_x][point_y + 1].has_habitat() == false)
		tiles[point_x][point_y + 1].set_habitat('^');
	if (tiles[point_x + 1][point_y + 1].has_habitat() == false)
		tiles[point_x + 1][point_y + 1].set_habitat('^');
}

void generate_3x3_hill(size_t point_x, size_t point_y, Tile **tiles, size_t terrain_size) {
	generate_2x2_hill(point_x, point_y, tiles);
	if (point_x + 2 > terrain_size - 1) return;
	if (point_y + 2 > terrain_size - 1) return;
	if (tiles[point_x + 2][point_y].has_habitat() == false)
		tiles[point_x + 2][point_y].set_habitat('^');
	if (tiles[point_x][point_y + 2].has_habitat() == false)
		tiles[point_x][point_y + 2].set_habitat('^');
	if (tiles[point_x + 2][point_y + 1].has_habitat() == false)
		tiles[point_x + 2][point_y + 1].set_habitat('^');
	if (tiles[point_x + 1][point_y + 2].has_habitat() == false)
		tiles[point_x + 1][point_y + 2].set_habitat('^');
	if (tiles[point_x + 2][point_y + 2].has_habitat() == false)
		tiles[point_x + 2][point_y + 2].set_habitat('^');
}

void generate_4x4_hill(size_t point_x, size_t point_y, Tile **tiles, size_t terrain_size) {
	generate_3x3_hill(point_x, point_y, tiles, terrain_size);
	if (point_x + 3 > terrain_size - 1) return;
	if (point_y + 3 > terrain_size - 1) return;
	if (tiles[point_x + 3][point_y].has_habitat() == false)
		tiles[point_x + 3][point_y].set_habitat('^');
	if (tiles[point_x + 3][point_y + 1].has_habitat() == false)
		tiles[point_x + 3][point_y + 1].set_habitat('^');
	if (tiles[point_x + 3][point_y + 2].has_habitat() == false)
		tiles[point_x + 3][point_y + 2].set_habitat('^');
	if (tiles[point_x][point_y + 3].has_habitat() == false)
		tiles[point_x][point_y + 3].set_habitat('^');
	if (tiles[point_x + 1][point_y + 3].has_habitat() == false)
		tiles[point_x + 1][point_y + 3].set_habitat('^');
	if (tiles[point_x + 2][point_y + 3].has_habitat() == false)
		tiles[point_x + 2][point_y + 3].set_habitat('^');
	if (tiles[point_x + 3][point_y + 3].has_habitat() == false)
		tiles[point_x + 3][point_y + 3].set_habitat('^');
}

void Terrain::generate_hills() {
	for (size_t c_row = 0; c_row < terrain_size - 1; c_row++) {
		for (size_t c_col = 0; c_col < terrain_size - 1; c_col++) {
			if (tiles[c_row][c_col].has_habitat()) continue;
			if (rand() % 100 < 10) {
				size_t percent = rand() % 100;
				if (percent >= 40) generate_2x2_hill(c_row, c_col, tiles);
				else if (percent >= 15) generate_3x3_hill(c_row, c_col, tiles, terrain_size);
				else generate_4x4_hill(c_row, c_col, tiles, terrain_size);
			}
		}
	}
}

void Terrain::generate_meadow() {
	for (size_t c_row = 0; c_row < terrain_size; c_row++)
		for (size_t c_col = 0; c_col < terrain_size; c_col++)
			if (tiles[c_row][c_col].has_habitat() == false)
				tiles[c_row][c_col].set_habitat('"');
}

void Terrain::place_plants(size_t n_grass, size_t n_algae, size_t n_maple, size_t n_oak, size_t n_pine) {
	if (Plant::set_terrain(this) == false) cerr << "In Terrain::place_plants(): Could not set Plant's terrain." << endl;
	for (size_t chance = 2; chance < 100; chance += 2) {
		for (size_t c_row = 0; c_row < terrain_size; c_row++) {
			for (size_t c_col = 0; c_col < terrain_size; c_col++) {
				if ((size_t)rand() % 100 < chance) {
					char habitat = tiles[c_row][c_col].get_habitat();
					if (tiles[c_row][c_col].get_plant() != NULL) continue;
					if (habitat == '#') {
						if (n_algae != 0) { add_plant(new Algae(c_row, c_col), c_row, c_col); n_algae--; } }
					else if (habitat == '"') {
						size_t option = rand() % 3;
						if (option == 0 && n_maple != 0) { add_plant(new Maple(c_row, c_col), c_row, c_col); n_maple--; }
						else if ((option == 0 || option == 1) && n_oak != 0) { add_plant(new Oak(c_row, c_col), c_row, c_col); n_oak--; }
						else if (n_grass != 0) { add_plant(new Grass(c_row, c_col), c_row, c_col); n_grass--; } }
					else if (habitat == '^') {
						if (rand() % 2 == 0 && n_pine != 0) { add_plant(new Pine(c_row, c_col), c_row, c_col); n_pine--; }
						else if (n_maple != 0) { add_plant(new Maple(c_row, c_col), c_row, c_col); n_maple--; } }
				}
			}
		}
	}
}

size_t Terrain::get_size() const {
	return terrain_size;
}

char Terrain::get_habitat(size_t row, size_t col) const {
	if (row > terrain_size) return 0;
	if (col > terrain_size) return 0;
	return tiles[row][col].get_habitat();
}

char Terrain::find_free_tile(size_t row, size_t col, char habitat_mask) {
	if (row > terrain_size - 1 || col > terrain_size - 1) {
		cerr << "In Terrain::find_free_tile: requested tile is out of bounds." << endl;
		exit(7); }
	if (col - 1 < terrain_size) {
		if (tiles[row][col - 1].get_plant() == NULL) {
			char habitat = tiles[row][col - 1].get_habitat();
			if (habitat == '#' && ((habitat_mask & WATER) == WATER)) return 'W';
			if (habitat == '^' && ((habitat_mask & HILL) == HILL)) return 'W';
			if (habitat == '"' && ((habitat_mask & MEADOW) == MEADOW)) return 'W'; } }
	if (col + 1 < terrain_size) {
		if (tiles[row][col + 1].get_plant() == NULL) {
			char habitat = tiles[row][col + 1].get_habitat();
			if (habitat == '#' && ((habitat_mask & WATER) == WATER)) return 'E';
			if (habitat == '^' && ((habitat_mask & HILL) == HILL)) return 'E';
			if (habitat == '"' && ((habitat_mask & MEADOW) == MEADOW)) return 'E'; } }
	if (row + 1 < terrain_size) {
		if (tiles[row + 1][col].get_plant() == NULL) {
			char habitat = tiles[row + 1][col].get_habitat();
			if (habitat == '#' && ((habitat_mask & WATER) == WATER)) return 'S';
			if (habitat == '^' && ((habitat_mask & HILL) == HILL)) return 'S';
			if (habitat == '"' && ((habitat_mask & MEADOW) == MEADOW)) return 'S'; } }
	if (row - 1 < terrain_size) {
		if (tiles[row - 1][col].get_plant() == NULL) {
			char habitat = tiles[row - 1][col].get_habitat();
			if (habitat == '#' && ((habitat_mask & WATER) == WATER)) return 'N';
			if (habitat == '^' && ((habitat_mask & HILL) == HILL)) return 'N';
			if (habitat == '"' && ((habitat_mask & MEADOW) == MEADOW)) return 'N'; } }
	return 0;
}

bool Terrain::add_plant(Plant *plant, size_t row, size_t col) {
	if (tiles[row][col].get_plant() != NULL) return false;
	tiles[row][col].add_plant(plant);
	plants.push(plant);
	return true;
}

Plant *Terrain::get_plant(size_t row, size_t col) const {
	if (row > terrain_size - 1 || col > terrain_size - 1) {
		cerr << "In Terrain::get_plant: tile requested is out of bounds." << endl;
		exit(3); }
	return tiles[row][col].get_plant();
}

List<Plant> &Terrain::get_plants() {
	return plants;
}
