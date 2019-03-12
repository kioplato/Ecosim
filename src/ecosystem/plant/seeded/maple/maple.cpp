// File: maple.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "maple.hpp"
/******************/

Maple::Maple(size_t row, size_t col)
		: Seeded("Maple", 'M', row, col, 5, 5, 10, 2, 10, 20) { }
