/*
Implémentation de l'algorithme de backtracking en profondeur
*/

#include "dante_generator.h"
#include <stdio.h>
#include <stdlib.h>


int **depth_first_backtracking(map_t *map)
{
    print_int_map(map->map, map->size_x, map->size_y);
    return map->map;
}

