// File: grass.hpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "../seedless.hpp"
/******************/

class Grass : public Seedless {
	public:
		Grass(size_t row, size_t col);
};
