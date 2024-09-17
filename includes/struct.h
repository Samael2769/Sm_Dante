
#pragma once

typedef struct map_s
{
    int **map;
    int size_x;
    int size_y;
} map_t;

typedef struct {
    int x, y;
} Point;

void print_map(int **map, int size_x, int size_y);
void print_int_map(int **map, int size_x, int size_y);
void free_map(int **map, int size_y);
int **init_map(int size_x, int size_y);