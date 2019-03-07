// File: terrain.hpp

#ifndef TERRAIN_HPP
#define TERRAIN_HPP

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "tile/tile.hpp"
/******************/

class Terrain {
	private:
		Tile** tiles;
		size_t terrain_size;
		void terrain_generator();
		void generate_river();
		void generate_lake();
		void generate_hills();
		void generate_meadow();
		void place_plants();
	public:
		Terrain(size_t terrain_size);
		~Terrain();
		size_t get_size() const;
		char get_habitat(size_t row, size_t col) const;
};

#endif  // #ifndef TERRAIN_HPP
