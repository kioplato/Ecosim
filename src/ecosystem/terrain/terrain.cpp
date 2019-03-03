// File: terrain.cpp

/* Custom headers */
#include "terrain.hpp"
/******************/

Terrain::Terrain(size_t terrain_size)
	: tiles(NULL), terrain_size(terrain_size) {
	if (terrain_size < 10) throw "Terrain size must be at least 10.";
	terrain_generator();
}

Terrain::~Terrain() {
	// TODO: Free memory for tiles
}

void Terrain::terrain_generator() {
	tiles = new Tile *[terrain_size];
	for (size_t c_row = 0; c_row < terrain_size; c_row++)
		tiles[c_row] = new Tile[terrain_size];
	generate_river();
	generate_lake();
	generate_hills();
	generate_meadow();
}

void Terrain::generate_river() {
	// River can start from [5, terrain_size - 5]
	size_t possible_points = terrain_size - 9;
	size_t start_point = (rand() % possible_points) + 5;
	tiles[0][start_point].set_habitat('#');
	size_t current_point = start_point;
	for (size_t c_row = 1; c_row < terrain_size; c_row++) {
		tiles[c_row][current_point].set_habitat('#');
		bool deviate = (rand() % 10 < 3) ? true : false;
		if (deviate) {
			bool to_right = rand() % 2;
			bool twice = rand() % 2;
			if (to_right) {
				if (current_point + 1 >= terrain_size - 2) continue;
				tiles[c_row][current_point + 1].set_habitat('#');
				current_point ++;
				if (twice) {
					if (current_point + 1 >= terrain_size - 2) continue;
					tiles[c_row][current_point + 1].set_habitat('#'); }
				current_point += (twice) ? 1 : 0;
			} else {
				if (current_point - 3 > terrain_size) continue;
				tiles[c_row][current_point - 1].set_habitat('#');
				current_point--;
				if (twice) {
					if (current_point - 3 > terrain_size) continue;
					tiles[c_row][current_point - 1].set_habitat('#'); }
				current_point += (twice) ? -1 : 0;
			}
		}
	}
}

void Terrain::generate_lake() {
	size_t lake_size = terrain_size / 4;
	cout << "Creating lake with size: " << lake_size << endl;
	// The lake will have 1 tile from each side of the grid (-1 * 2).
	// The lake will cover lake_size tiles from the starting point (lake_size - 1).
	size_t possible_starts = terrain_size - 1 - 1 - (lake_size - 1);
	// +1 to separate the start_row from the edge of the grid - to add margin.
	size_t start_row = (rand() % possible_starts) + 1;
	size_t start_col = (rand() % possible_starts) + 1;
	for (size_t c_row = start_row; c_row < lake_size + start_row; c_row++)
		for (size_t c_col = start_col; c_col < lake_size + start_col; c_col++)
			tiles[c_row][c_col].set_habitat('#');
}

/* TODO: Implement a function that takes starting point and ending point and fills it with hills.
 * Also checks if the ending point is out of the grid's size. If there is water or other habitat
 * then it just ignores it, does not overwrite it, and continues to place hills. (Using nested fors) */
void generate_2x2_hill(size_t point_x, size_t point_y, Tile **tiles) {
	if (tiles[point_x][point_y].has_habitat() == false)
		tiles[point_x][point_y].set_habitat('^');
	if (tiles[point_x + 1][point_y].has_habitat() == false)
		tiles[point_x + 1][point_y].set_habitat('^');
	if (tiles[point_x][point_y + 1].has_habitat() == false)
		tiles[point_x][point_y + 1].set_habitat('^');
	if (tiles[point_x + 1][point_y + 1].has_habitat() == false)
		tiles[point_x + 1][point_y + 1].set_habitat('^');
}

void generate_3x3_hill(size_t point_x, size_t point_y, Tile **tiles, size_t terrain_size) {
	generate_2x2_hill(point_x, point_y, tiles);
	if (point_x + 2 > terrain_size - 1) return;
	if (point_y + 2 > terrain_size - 1) return;
	if (tiles[point_x + 2][point_y].has_habitat() == false)
		tiles[point_x + 2][point_y].set_habitat('^');
	if (tiles[point_x][point_y + 2].has_habitat() == false)
		tiles[point_x][point_y + 2].set_habitat('^');
	if (tiles[point_x + 2][point_y + 1].has_habitat() == false)
		tiles[point_x + 2][point_y + 1].set_habitat('^');
	if (tiles[point_x + 1][point_y + 2].has_habitat() == false)
		tiles[point_x + 1][point_y + 2].set_habitat('^');
	if (tiles[point_x + 2][point_y + 2].has_habitat() == false)
		tiles[point_x + 2][point_y + 2].set_habitat('^');
}

void generate_4x4_hill(size_t point_x, size_t point_y, Tile **tiles, size_t terrain_size) {
	generate_3x3_hill(point_x, point_y, tiles, terrain_size);
	if (point_x + 3 > terrain_size - 1) return;
	if (point_y + 3 > terrain_size - 1) return;
	if (tiles[point_x + 3][point_y].has_habitat() == false)
		tiles[point_x + 3][point_y].set_habitat('^');
	if (tiles[point_x + 3][point_y + 1].has_habitat() == false)
		tiles[point_x + 3][point_y + 1].set_habitat('^');
	if (tiles[point_x + 3][point_y + 2].has_habitat() == false)
		tiles[point_x + 3][point_y + 2].set_habitat('^');
	if (tiles[point_x][point_y + 3].has_habitat() == false)
		tiles[point_x][point_y + 3].set_habitat('^');
	if (tiles[point_x + 1][point_y + 3].has_habitat() == false)
		tiles[point_x + 1][point_y + 3].set_habitat('^');
	if (tiles[point_x + 2][point_y + 3].has_habitat() == false)
		tiles[point_x + 2][point_y + 3].set_habitat('^');
	if (tiles[point_x + 3][point_y + 3].has_habitat() == false)
		tiles[point_x + 3][point_y + 3].set_habitat('^');
}

void Terrain::generate_hills() {
	// TODO: Why terrain_size - 1?
	for (size_t c_row = 0; c_row < terrain_size - 1; c_row++) {
		for (size_t c_col = 0; c_col < terrain_size - 1; c_col++) {
			if (tiles[c_row][c_col].has_habitat()) continue;
			if (rand() % 100 < 20) {
				size_t percent = rand() % 100;
				if (percent >= 40) generate_2x2_hill(c_row, c_col, tiles);
				else if (percent >= 15) generate_3x3_hill(c_row, c_col, tiles, terrain_size);
				else generate_4x4_hill(c_row, c_col, tiles, terrain_size);
			}
		}
	}
}

void Terrain::generate_meadow() {
	for (size_t c_row = 0; c_row < terrain_size; c_row++)
		for (size_t c_col = 0; c_col < terrain_size; c_col++)
			if (tiles[c_row][c_col].has_habitat() == false)
				tiles[c_row][c_col].set_habitat('"');
}
