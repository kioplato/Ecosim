// File: ecosystem.cpp

/* Custom headers */
#include "ecosystem.hpp"
/******************/

Ecosystem::Ecosystem(size_t terrain_size, string season)
	: terrain(terrain_size), day_of_year(1)
{
	if (season != "Summer" && season != "Winter" && season != "Fall" && season != "Autumn")
		throw "Unknown season provided.";
	this->season = season;
}
