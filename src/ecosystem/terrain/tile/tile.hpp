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
		bool set_habitat(char token);
		char get_habitat() const;
		bool has_habitat() const;
};

#endif  // #ifndef TILE_HPP
