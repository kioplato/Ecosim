// File: terrain.hpp

#ifndef TERRAIN_HPP
#define TERRAIN_HPP

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "../plant/plant.hpp"
#include "tile/tile.hpp"
#include "../list/list.hpp"
/******************/

class Tile;
class Plant;

class Terrain {
	private:
		Tile** tiles;
		size_t terrain_size;
		void terrain_generator();
		void generate_river();
		void generate_lake();
		void generate_hills();
		void generate_meadow();
		void place_plants(size_t n_grass, size_t n_algae, size_t n_maple, size_t n_oak, size_t n_pine);
		List<Plant> plants;
	public:
		Terrain(size_t terrain_size);
		~Terrain();
		size_t get_size() const;
		char get_habitat(size_t row, size_t col) const;
		char find_free_tile(size_t row, size_t col, char habitat_mask);
		bool add_plant(Plant *plant, size_t row, size_t col);
		Plant *get_plant(size_t row, size_t col) const;
		List<Plant> &get_plants();
};

#endif  // #ifndef TERRAIN_HPP
