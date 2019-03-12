// File: algae.hpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "../seedless.hpp"
/******************/

class Algae : public Seedless {
	public:
		Algae(size_t row, size_t col);
};
