// File: tile.hpp

#ifndef TILE_HPP
#define TILE_HPP

/* Custom headers */
#include "../../plant/plant.hpp"
/******************/

class Plant;

class Tile {
	private:
		char token;
		Plant *plant;
	public:
		Tile();
		~Tile();
		bool set_habitat(char token);
		char get_habitat() const;
		bool has_habitat() const;
		bool has_habitat(char token) const;
		bool add_plant(Plant *plant);
		Plant *get_plant();
		Plant *remove_plant();
};

#endif  // #ifndef TILE_HPP
