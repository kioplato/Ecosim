// File: tile.hpp

#ifndef TILE_HPP
#define TILE_HPP

/* Custom headers */
/******************/

class Tile {
	private:
		char token;
	public:
		Tile();
		~Tile();
		void set_habitat(char token);
};

#endif  // #ifndef TILE_HPP
