// File: tile.hpp

#ifndef TILE_HPP
#define TILE_HPP

class Tile {
	private:
		char token;
	public:
		Tile();
		bool set_habitat(char token);
		char get_habitat() const;
		bool has_habitat() const;
		bool has_habitat(char token) const;
};

#endif  // #ifndef TILE_HPP
