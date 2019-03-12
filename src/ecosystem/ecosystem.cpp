// File: ecosystem.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "ecosystem.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

Ecosystem::Ecosystem(size_t terrain_size, string season)
		: terrain(terrain_size), season(season), day_of_year(1), day_of_season(1) {
	if (season != "Summer" && season != "Winter" &&
			season != "Fall" && season != "Spring")
		throw "Season must be Summer/Winter/Fall/Spring.";
	// Spring (animals wake up from hibernation).
	grow_period[Spring].plants = 5;
	grow_period[Spring].animals = 20;
	breed_period[Spring].plants = 10;
	breed_period[Spring].herbivores = 12;
	breed_period[Spring].carnivores = 11;
	// Summer.
	grow_period[Summer].plants = 10;
	grow_period[Summer].animals = 30;
	breed_period[Summer].plants = 10;
	breed_period[Summer].herbivores = 8;
	breed_period[Summer].carnivores = 9;
	// Fall.
	grow_period[Fall].plants = 0;  // Don't grow.
	grow_period[Fall].animals = 15;
	breed_period[Fall].plants = 20;
	breed_period[Fall].herbivores = 5;
	breed_period[Fall].carnivores = 9;
	// Winter (animals hibernate).
	grow_period[Winter].plants = 10;
	grow_period[Winter].animals = 30;
	breed_period[Winter].plants = 0;  // Don't breed.
	breed_period[Winter].herbivores = 18;
	breed_period[Winter].carnivores = 10;
	// Current grow/breed period.
	apply_periods();
	// Print ecosystem's current state.
	print_system();
	print_plant_statistics();
}

Ecosystem::~Ecosystem() {
	print_system();
	print_plant_statistics();
}

void Ecosystem::apply_periods() {
	if (season == "Summer") {
		c_grow_period.plants = grow_period[Summer].plants;
		c_grow_period.animals = grow_period[Summer].animals;
		c_breed_period.plants = breed_period[Summer].plants;
		c_breed_period.herbivores = breed_period[Summer].herbivores;
		c_breed_period.carnivores = breed_period[Summer].carnivores; }
	else if (season == "Winter") {
		c_grow_period.plants = grow_period[Winter].plants;
		c_grow_period.animals = grow_period[Winter].animals;
		c_breed_period.plants = breed_period[Winter].plants;
		c_breed_period.herbivores = breed_period[Winter].herbivores;
		c_breed_period.carnivores = breed_period[Winter].carnivores; }
	else if (season == "Spring") {
		c_grow_period.plants = grow_period[Spring].plants;
		c_grow_period.animals = grow_period[Spring].animals;
		c_breed_period.plants = breed_period[Spring].plants;
		c_breed_period.herbivores = breed_period[Spring].herbivores;
		c_breed_period.carnivores = breed_period[Spring].carnivores; }
	else if (season == "Fall") {
		c_grow_period.plants = grow_period[Fall].plants;
		c_grow_period.animals = grow_period[Fall].animals;
		c_breed_period.plants = breed_period[Fall].plants;
		c_breed_period.herbivores = breed_period[Fall].herbivores;
		c_breed_period.carnivores = breed_period[Fall].carnivores; }
}

void Ecosystem::apply_season() {
	if (season == "Summer") {
		season = "Fall";
		cout << "Changing season from Summer to Fall." << endl; }
	else if (season == "Fall") {
		season = "Winter";
		cout << "Changing season from Fall to Winter." << endl; }
	else if (season == "Winter") {
		season = "Spring";
		cout << "Changing season from Winter to Spring." << endl; }
	else if (season == "Spring") {
		season = "Summer";
		cout << "Changing season from Spring to Summer." << endl; }
	apply_periods();
}

void Ecosystem::grow_plants() {
	if (season == "Fall") return;
	if (day_of_year % c_grow_period.plants != 0) return;
	List<Plant> &plants = terrain.get_plants();
	plants.move_start();
	do {
		Plant *plant = plants.get_data();
		plant->grow();
	} while(plants.move_right() == true);
}

void Ecosystem::daily_reset() {
	grow_plants();
}

void Ecosystem::plant_breeding() {
	if (season == "Winter") return;
	if (day_of_year % c_breed_period.plants != 0) return;
	List<Plant> &plants = terrain.get_plants();
	plants.move_start();
	do {
		Plant *plant = plants.get_data();
		plant->breed();
	} while(plants.move_right() == true);
}

void Ecosystem::run_day() {
	daily_reset();
	plant_breeding();
}

void Ecosystem::run_ecosystem(size_t n_days) {
	for (size_t c_day = 0; c_day < n_days; c_day++, day_of_year++) {
		if (day_of_year % 91 == 0) {
			apply_season();
			print_system();
			print_plant_statistics(); }
		run_day();
	}
}

void Ecosystem::print_habitats() const {
	size_t terrain_size = terrain.get_size();
	for (size_t c_row = 0; c_row < terrain_size; c_row++) {
		for (size_t c_col = 0; c_col < terrain_size; c_col++)
			cout << terrain.get_habitat(c_row, c_col);
		cout << endl;
	}
}

void Ecosystem::print_system() const {
	size_t terrain_size = terrain.get_size();
	for (size_t c_row = 0; c_row < terrain_size; c_row++) {
		for (size_t c_col = 0; c_col < terrain_size; c_col++) {
			Plant *plant = terrain.get_plant(c_row, c_col);
			if (plant == NULL)
				cout << terrain.get_habitat(c_row, c_col);
			else
				cout << plant->get_token();
		}
		cout << endl;
	}
}

void Ecosystem::print_plant_statistics() {
	size_t n_grass = 0, n_algae = 0, n_oak = 0, n_pine = 0, n_maple = 0;
	List<Plant> &plants = terrain.get_plants();
	plants.move_start();
	do {
		switch (plants.get_data()->get_token()) {
			case 'G': n_grass++; break;
			case 'A': n_algae++; break;
			case 'O': n_oak++; break;
			case 'P': n_pine++; break;
			case 'M': n_maple++; break;
			default: cout << "In Ecosystem::print_plant_statistics(): Invalid token from plant." << endl;
		}
	} while(plants.move_right() == true);
	cout << "Plant statistics:" << endl;
	cout << "	# grass: " << n_grass << endl;
	cout << "	# algae: " << n_algae << endl;
	cout << "	# oak: " << n_oak << endl;
	cout << "	# pine: " << n_pine << endl;
	cout << "	# maple: " << n_maple << endl;
}
