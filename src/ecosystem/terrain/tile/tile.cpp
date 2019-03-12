// File: tile.cpp

/* Custom headers */
#include "tile.hpp"
/******************/

Tile::Tile() : token(0), plant(NULL) {}

Tile::~Tile() {
	if (plant != NULL)
		delete plant;
}

bool Tile::set_habitat(char token) {
	if (token != '#' && token != '^' && token != '"') return false;
	if (has_habitat()) return false;
	this->token = token;
	return true;
}

char Tile::get_habitat() const {
	return token;
}

bool Tile::has_habitat() const {
	if (token == 0) return false;
	return true;
}

bool Tile::has_habitat(char token) const {
	if (this->token != token) return false;
	return true;
}

bool Tile::add_plant(Plant *plant) {
	if (plant == NULL) {
		cerr << "Plant to add to tile is NULL." << endl;
		return false; }
	if (this->plant != NULL) {
		cerr << "Tile already has plant." << endl;
		return false; }
	this->plant = plant;
	return true;
}

Plant *Tile::get_plant() {
	return plant;
}

Plant *Tile::remove_plant() {
	Plant *tmp = plant;
	plant = NULL;
	return tmp;
}
