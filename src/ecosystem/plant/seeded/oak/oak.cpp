// File: oak.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "oak.hpp"
/******************/

Oak::Oak(size_t row, size_t col)
		: Seeded("Oak", 'O', row, col, 20, 20, 15, 5, 15, 30) { }
