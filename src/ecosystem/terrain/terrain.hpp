// File: terrain.hpp

#ifndef TERRAIN_HPP
#define TERRAIN_HPP

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
	public:
		Terrain(size_t terrain_size);
		~Terrain();
		size_t get_size() const;
};

#endif  // #ifndef TERRAIN_HPP
