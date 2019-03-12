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
	srand(time(NULL));
	cout << "Welcome to ecosim." << endl;
	size_t terrain_size;
	cout << "Please input terrain size: ";
	cin >> terrain_size;
	string season;
	cout << "Please input starting season: ";
	cin >> season;
	Ecosystem ecosystem(terrain_size, season);
	size_t option = 1;
	while (option != 0) {
		cout << "0. Quit simulation." << endl;
		cout << "1. Print ecosystem." << endl;
		cout << "2. Pring habitats." << endl;
		cout << "3. Run ecosystem." << endl;
		cin >> option;
		if (option == 0)
			cout << "Exiting.." << endl;
		else if (option == 1) {
			cout << "Printing ecosystem.." << endl;
			ecosystem.print_system(); }
		else if (option == 2) {
			cout << "Printing habitats.." << endl;
			ecosystem.print_habitats(); }
		else if (option == 3) {
			cout << "Running ecosystem.." << endl;
			size_t n_days;
			cout << "Please input # days: ";
			cin >> n_days;
			ecosystem.run_ecosystem(n_days); }
		else if (option == 4) {
			cout << "Printing plant statistics.." << endl;
			ecosystem.print_plant_statistics(); }
		else
			cout << "Unknown option." << endl;
	}
	return EXIT_SUCCESS;
}
