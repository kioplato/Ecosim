// File: terrain.cpp

/* Custom headers */
#include "terrain.hpp"
/******************/

Terrain::Terrain(size_t terrain_size)
	: tiles(NULL), terrain_size(terrain_size) {
	if (terrain_size < 10) throw "Terrain size must be at least 10.";
	map_generator();
}

Terrain::~Terrain() {
	// TODO: Free memory for tiles
}

void Terrain::terrain_generator() {
	tiles = new Tile *[terrain_size];
	for (size_t c_row = 0; c_row < terrain_size; c_row++)
		tiles[c_row] = new Tile[terrain_size];
	generate_river();
	generate_lake();
	generate_hills();
	generate_meadow();
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
