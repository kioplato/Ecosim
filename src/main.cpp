// File: main.cpp

/* System headers */
#include <iostream>
/******************/

/* Custom headers */
#include "ecosystem/ecosystem.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

int main(void) {
	cout << "Welcome to ecosim." << endl;
	size_t terrain_size;
	cout << "Please input terrain size: ";
	cin >> terrain_size;
	Ecosystem ecosystem(terrain_size);
	size_t option = 1;
	while (option != 0) {
		cout << "0. Quit simulation." << endl;
		cout << "1. Print ecosystem." << endl;
		cin >> option;
		if (option == 0)
			cout << "Exiting.." << endl;
		else if (option == 1) {
			cout << "Printing ecosystem.." << endl;
			ecosystem.print_system(); }
		else
			cout << "Unknown option." << endl;
	}
	return EXIT_SUCCESS;
}
