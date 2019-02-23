// File: tile.hpp

#ifndef TILE_HPP
#define TILE_HPP

/* System headers */
/******************/

/* Custom headers */
/******************/

/* Namespace access */
/********************/

class Tile {
	private:
		char token;
		// AnimalList animals;
		// Plant* plant;
	public:
		Tile();
		~Tile();
		void set_habitat(char token);
};

#endif  // #ifndef TILE_HPP
