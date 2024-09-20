
#pragma once

#include "sm_timer.h"

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


typedef struct dante_s
{
    map_t *map;
    Point start;
    Point end;
    sm_timer_t timer;
    int difficulty;
} dante_t;