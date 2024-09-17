/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_dante
*/

#include <stdio.h>
#include "sm_dante.h"

int sm_dante()
{
    int size_x = 20;
    int size_y = 20;
    int **maze = init_map(size_x, size_y);
    map_t map = {
        .size_x = size_x,
        .size_y = size_y,
        .map = maze
    };

    Point start = {0, 0};
    Point end = {size_x - 2 , size_y - 2};

    //print_int_map(map.map, size_x, size_y);
    dante_generator(&map, size_x, size_y);
    //print_int_map(map.map, size_x, size_y);
    dante_algorithm(size_x, size_y, map.map, start, end);
    //print_map(map.map, size_x, size_y);
    gameplay(&map, start, end);
    return 0;
}