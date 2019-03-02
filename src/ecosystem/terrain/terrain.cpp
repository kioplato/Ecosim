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
