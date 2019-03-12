// File: grass.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "grass.hpp"
/******************/

Grass::Grass(size_t row, size_t col)
		: Seedless("Grass", 'G', row, col, 15, 15, 5, 4) { }
