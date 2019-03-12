// plant.hpp

#ifndef PLANT_HPP
#define PLANT_HPP

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "../terrain/terrain.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

class Terrain;

class Plant {
	private:
		static Terrain *terrain;
		string name;
		char token;
		size_t row;
		size_t col;
		size_t breeding_prob;
		size_t illness_prob;
		size_t life;
		size_t life_factor;
		bool is_alive;
	protected:
		size_t size;
		size_t get_illness_prob();
		size_t get_life_factor();
		void lose_life_life_factor();
		void incr_life_life_factor();
	public:
		Plant(string name, char token, size_t row, size_t col,
				size_t breeding_prob, size_t illness_prob,
				size_t life, size_t life_factor, size_t size);
		virtual ~Plant();
		static bool set_terrain(Terrain *terrain);
		char get_token();
		virtual size_t lose_life(size_t amount);
		virtual void grow() = 0;
		void breed();
		size_t get_size();
		bool get_is_alive();
};

#endif  // #ifndef PLANT_HPP
