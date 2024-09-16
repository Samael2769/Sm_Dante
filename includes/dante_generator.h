
#pragma once

#include "struct.h"

int **depth_first_backtracking(map_t *map);
void print_map(int **map, int size_x, int size_y);
void print_int_map(int **map, int size_x, int size_y);
void free_map(int **map, int size_y);
int **init_map(int size_x, int size_y);