// File: tile.cpp

/* Custom headers */
#include "tile.hpp"
/******************/

Tile::Tile() : token(0) {}

bool Tile::set_habitat(char token) {
	if (token != '#' && token != '^' && token != '"') return false;
	if (has_habitat()) return false;
	this->token = token;
	return true;
}

char Tile::get_habitat() const {
	return token;
}
