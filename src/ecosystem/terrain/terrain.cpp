// File: terrain.cpp

/* Custom headers */
#include "terrain.hpp"
/******************/

Terrain::Terrain(size_t terrain_size)
	: tiles(NULL), terrain_size(terrain_size) {
	if (terrain_size < 10) throw "Terrain size must be at least 10.";
	map_generator();
}
