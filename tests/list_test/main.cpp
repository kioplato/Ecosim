// File: main.cpp

/* System headers */
#include <iostream>
#include <string>
/******************/

/* Custom headers */
#include "list.hpp"
/******************/

/* Namespace access */
using namespace std;
/********************/

int main(int argc, char *argv[]) {
	List<int> list;
	size_t next_number = 1;
	size_t option = 1;
	while (option != 0) {
		cout << "0. Quit." << endl;
		cout << "1. Add new item." << endl;
		cout << "2. Pop item." << endl;
		cout << "3. Move left." << endl;
		cout << "4. Move right." << endl;
		cout << "Option(0-4): "; cin >> option;
		if (option == 0)
			cout << "Exiting.." << endl;
		else if (option == 1) {
			cout << "Adding new item." << endl;
			int *item = new int(next_number);
			list.push(item);
			next_number++; }
		else if (option == 2) {
			cout << "Popping item." << endl;
			int *item = list.pop();
			if (item == NULL)
				cout << "The list is empty." << endl;
			else
				cout << *item << endl; }
		else if (option == 3) {
			cout << "Moving left." << endl;
			if (list.move_left() == false)
				cout << "Failed to move left." << endl; }
		else if (option == 4) {
			cout << "Moving right." << endl;
			if (list.move_right() == false)
				cout << "Failed to move right." << endl; }
		else cout << "Unknown option." << endl;
	}

	return 0;
}
