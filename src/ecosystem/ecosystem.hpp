// File: ecosystem.hpp

#ifndef ECOSYSTEM_HPP
#define ECOSYSTEM_HPP

/* Custom headers */
#include "terrain/terrain.hpp"
/******************/

class Ecosystem {
	private:
		Terrain terrain;
	public:
		Ecosystem(size_t terrain_size);
		void print_system() const;
};

#endif  // #ifndef ECOSYSTEM_HPP
