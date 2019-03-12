// File: ecosystem.hpp

#ifndef ECOSYSTEM_HPP
#define ECOSYSTEM_HPP

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "terrain/terrain.hpp"
/******************/

class Ecosystem {
	private:
		Terrain terrain;
		string season;
		size_t day_of_year;
		size_t day_of_season;
		enum { Summer, Fall, Winter, Spring };
		struct Grow_Period {
			size_t plants;
			size_t animals; };
		struct Breed_Period {
			size_t plants;
			size_t herbivores;
			size_t carnivores; };
		Grow_Period grow_period[4];
		Breed_Period breed_period[4];
		Grow_Period c_grow_period;
		Breed_Period c_breed_period;
		void apply_periods();
		void apply_season();
		void grow_plants();
		void daily_reset();
		void plant_breeding();
		void run_hour();
		void run_day();
	public:
		Ecosystem(size_t terrain_size, string season);
		~Ecosystem();
		void run_ecosystem(size_t n_days);
		void print_habitats() const;
		void print_system() const;
		void print_plant_statistics();
};

#endif  // #ifndef ECOSYSTEM_HPP
