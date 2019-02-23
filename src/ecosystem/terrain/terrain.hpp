// File: terrain.hpp

#ifndef TERRAIN_HPP
#define TERRAIN_HPP

/* System headers */
/******************/

/* Custom headers */
/******************/

/* Namespace access */
/********************/

class Terrain {
	private:
		Tile** tiles;
		size_t terrain_size;
		void map_generator();
	public:
		Terrain(size_t terrain_size);
		~Terrain();
		size_t get_size() const;
};

#endif  // #ifndef TERRAIN_HPP